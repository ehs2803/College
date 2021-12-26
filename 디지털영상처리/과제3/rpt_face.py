import cv2 as cv
import dlib
import numpy as np
import pickle
from matplotlib import pyplot as plt
import time
# 필수 사항 -----------------------------
# 아래의 변수이름과 표현식은 바꾸지 말고 소스 그대로 상단에 노출되게 해 주십시오.

# 1) 테스트할 영상 파일이 있는 드라이브와 폴더. 실제 평가에서는 바꾸어 사용할 수 있습니다.
test_img_path = 'd:/dip/images/'

# 2) 그 폴더 안에 있는 테스트 대상 파일 이름
# 이 파일은 런닝맨 맴버와 아닌 사람들이 섞여 있습니다.
# 실제 평가에서는 바꾸어 사용할 수 있습니다. 테스트 파일이 10여개가 될 수도 있습니다.
test_file_list = ['t1.jpg', 't2.jpg', 't3.jpg', 't4.jpg', 't5.jpg']

# 3) path for dlib model: 위치 바꾸지 말고 제출해 주세요.
# 평가자의 PC에 설치해 놓고 테스트 할 것입니다.
model_path = 'd:/dip/data/dlib_face_recog/'

# 4) shape predictor와 사용하는 recognition_model
# 아래 정의된 것을 그대로 사용해 주세요.
pose_predictor_5_point = dlib.shape_predictor(model_path + "shape_predictor_5_face_landmarks.dat")
face_encoder = dlib.face_recognition_model_v1(model_path + "dlib_face_recognition_resnet_model_v1.dat")

# 검색하고자 하는 인물 7인
mb_han_lst = ['유재석', '지석진', '김종국', '하하', '송지효', '전소민', '양세찬']
mb_eng_lst = ['Yoo', 'ji', 'kim', 'ha', 'song', 'jeon', 'yang']
md_dic = {'Yoo':'유재석', 'ji':'지석진', 'kim':'김종국', 'ha':'하하',
          'song':'송지효', 'jeon':'전소민', 'yang':'양세찬'}

# threshold보다 큰 유클리디언 거리는 동일 인물로 판단하지 않음.
threshold = 0.6

# 얼굴검출 dlib hog face detector 사용.
detector = dlib.get_frontal_face_detector()

# face_encodings은 128차원의 ndarray 데이터들을 사람 얼굴에 따라 리스트 자료형과 얼굴 위치좌표를 반환
def face_encodings(face_image, number_of_times_to_upsample=1, num_jitters=2):
    """Returns the 128D descriptor for each face in the image"""
    # Detect faces:
    # hog 기반의 dlib face detector. gray 변환된 영상을 사용.
    gray = cv.cvtColor(face_image, cv.COLOR_RGB2GRAY)
    face_locations = detector(gray, number_of_times_to_upsample)
    # Detected landmarks:
    raw_landmarks = [pose_predictor_5_point(face_image, face_location) for face_location in face_locations]
    # Calculate the face encoding for every detected face using the detected landmarks for each one:
    return face_locations, [np.array(face_encoder.compute_face_descriptor(face_image, raw_landmark_set, num_jitters))
                            for raw_landmark_set in raw_landmarks]

# unknown encoding을 known_encoding list에 비교해 유클리디어 거리를 계산해 이름과 반환하고, 거리는 오름차순 정렬해 반환한다.
def compare_faces_ordered(dbfaces, encodings, face_names, encoding_to_check):
    """Returns the ordered distances and names when comparing a list of face encodings against a candidate to check"""
    distances = list(np.linalg.norm(encodings - encoding_to_check, axis=1))
    return zip(*sorted(zip(distances,dbfaces, face_names)))

# show_detection은 이미지에 있는 사람 얼굴에 빨간 사각형과 검색된 사람의 영문 이름을 출력해 반환
def show_detection(image, face, text, num):
    """Draws a rectangle and Eng name over each detected face"""
    cv.rectangle(image, (face.left(), face.top()), (face.right(), face.bottom()), (0, 0, 255), 2)
    cv.putText(image,text, (face.left()-10,face.top()-3), cv.FONT_HERSHEY_DUPLEX, 1, (255,0,0),2)
    cv.putText(image, str(num), (face.left() - 30, face.top() + 30), cv.FONT_HERSHEY_DUPLEX, 1, (255, 0, 0), 2)
    return image

def loadObjects(file_name):             # 지정한 파일, file_name에서 읽은 객체를 반환하기
    with open(file_name, "rb") as file:
        return(pickle.load(file))

start = time.time()

# 검색 대상 파일 즉 미지의 사진을 로드.
unknown_images = []
for i in range(len(test_file_list)):
    unknown_image = cv.imread(test_img_path+test_file_list[i]) # image read
    unknown_image = unknown_image[:, :, ::-1]         # Convert image from BGR (OpenCV format) to RGB (dlib format)
    unknown_images.append(unknown_image)              # append image to unknown_images list

# 검색 대상 파일 사진에 대해 encoding
unknown_encodings = []
unknown_rects = []
for image in unknown_images:
    unknown_image_rects, unknown_image_encoding = face_encodings(image)
    unknown_encodings.append(unknown_image_encoding)  # 검색 대상 파일 사진에 여러사람이 존재 가능
    unknown_rects.append(unknown_image_rects)         # 찾은 얼굴의 위치 좌표값 삽입

# 인물 데이터 읽기
all_member_face, all_member_encodings1d_lst, all_member1d_label_lst = loadObjects("db.bin")

print(type(all_member_face[0]))
print(all_member_face[0].shape)
print(type(all_member_encodings1d_lst[0]))
print(all_member_encodings1d_lst[0].shape)
print(all_member1d_label_lst)


# 5장의 검색 대상 파일에 대해 얼굴 인식, 얼굴 비교 후 matplotlib창 띄위기 및 출력창에 정보 출력
for i ,ue in enumerate(unknown_encodings):
    total_count = len(ue) # 총 감지된 얼굴 수
    member_count=0        # 인식된 런닝맨 멤버수
    img_faces = unknown_images[i].copy()
    rects = unknown_rects[i]
    text=[]
    extra=[]
    for m, ue_face in enumerate(ue): # 감지된 얼굴에 대해
        computed_distances_ordered, faces, ordered_names = compare_faces_ordered(all_member_face,
                                        all_member_encodings1d_lst, all_member1d_label_lst, ue_face) # 비교
        if computed_distances_ordered[0] < threshold:  # 유클리디안 거리가 0.6인 경우
            text.append([mb_eng_lst[int(ordered_names[0])], computed_distances_ordered[0]])  # 그 사람 이름 추가
            member_count += 1  # 인식된 멤버수 변수 1 증가
            unface = unknown_images[i][rects[m].top():rects[m].bottom(), rects[m].left():rects[m].right()]
            info = [[unface, -1], [faces[0], computed_distances_ordered[0]],
                    [faces[1], computed_distances_ordered[1]],
                    [faces[2], computed_distances_ordered[2]]]
            extra.append(info)
        else:  # unknown인 경우
            text.append(['unknown', -1])
            unface = unknown_images[i][rects[m].top():rects[m].bottom(), rects[m].left():rects[m].right()]
            info = [[unface, -1], [faces[0], computed_distances_ordered[0]], [faces[1], computed_distances_ordered[1]],
                [faces[2], computed_distances_ordered[2]]]
            extra.append(info)
        # 개선된 알고리즘
        ''' 
        if computed_distances_ordered[0]<threshold: # 유클리디안 거리가 0.6인 경우
            if computed_distances_ordered[0]>0.4: # 유클리디안 거리가 0.4 < dist < 0.6 사이의 값인 경우
                if not (ordered_names[0]==ordered_names[1] and ordered_names[1]==ordered_names[2]): # unknown으로 판단
                    text.append(['unknown', -1])
                    unface = unknown_images[i][rects[m].top():rects[m].bottom(), rects[m].left():rects[m].right()]
                    info = [[unface, -1], [faces[0], computed_distances_ordered[0]],
                            [faces[1], computed_distances_ordered[1]],
                            [faces[2], computed_distances_ordered[2]]]
                    extra.append(info)
                else: # 인식된 얼굴로 판단
                    text.append([mb_eng_lst[int(ordered_names[0])], computed_distances_ordered[0]])  # 그 사람 이름 추가
                    member_count += 1  # 인식된 멤버수 변수 1 증가
                    unface = unknown_images[i][rects[m].top():rects[m].bottom(), rects[m].left():rects[m].right()]
                    info = [[unface, -1], [faces[0], computed_distances_ordered[0]],
                            [faces[1], computed_distances_ordered[1]],
                            [faces[2], computed_distances_ordered[2]]]
                    extra.append(info)
            else: # 인식된 얼굴로 판단
                text.append([mb_eng_lst[int(ordered_names[0])], computed_distances_ordered[0]])  # 그 사람 이름 추가
                member_count += 1  # 인식된 멤버수 변수 1 증가
                unface = unknown_images[i][rects[m].top():rects[m].bottom(), rects[m].left():rects[m].right()]
                info = [[unface, -1], [faces[0], computed_distances_ordered[0]],
                        [faces[1], computed_distances_ordered[1]],
                        [faces[2], computed_distances_ordered[2]]]
                extra.append(info)
        else: # unknown인 경우
            text.append(['unknown',-1])
            unface = unknown_images[i][rects[m].top():rects[m].bottom(), rects[m].left():rects[m].right()]
            info = [[unface, -1], [faces[0], computed_distances_ordered[0]], [faces[1], computed_distances_ordered[1]],
                    [faces[2], computed_distances_ordered[2]]]
            extra.append(info)
        '''

    for j, ue_rect in enumerate(unknown_rects[i]):              # 인식된 사람 얼굴에 대해
        img_faces = show_detection(img_faces, ue_rect, text[j][0], j) # 사각형과 이름 출력
    plt.figure(num=f'{test_file_list[i]}')
    plt.imshow(img_faces)
    title = f'[File: {test_file_list[i]}] {total_count} faces found including {member_count} members'
    plt.title(title, fontsize=20)
    plt.axis('off')
    mng = plt.get_current_fig_manager()
    mng.window.state('zoomed')           # 창 최대화
    # 이미지 분석 창
    plt.figure(num=f'{test_file_list[i]} - analysis')
    for index, j in enumerate(extra,1):
        for k in range(4):
            img_index = index+k*(total_count)
            plt.subplot(4,total_count,img_index)
            if k!=0: plt.title(round(j[k][1],3))
            plt.axis('off')
            plt.imshow(j[k][0])
    mng = plt.get_current_fig_manager()
    mng.window.state('zoomed')           # 창 최대화
    # 주어진 형식으로 정보 출력
    print(f'[File: {test_file_list[i]}] ------------------------------')
    for k, info in enumerate(text):
        if info[1]==-1:
            print(f'face {k}: {info[0]}')
        else: print(f'face {k}: {info[0]}={round(info[1],3)}')
    print(title)
    print()
print("\n실행시간 : ", time.time()-start)
plt.show()


# db.py - 인식 인물 데이터베이스 파일 생성
'''
import numpy as np
import dlib
import cv2 as cv
import pickle
import os

model_path = 'data/'#'d:/dip/data/dlib_face_recog/'
pose_predictor_5_point = dlib.shape_predictor(model_path + "shape_predictor_5_face_landmarks.dat")
face_encoder = dlib.face_recognition_model_v1(model_path + "dlib_face_recognition_resnet_model_v1.dat")
detector = dlib.get_frontal_face_detector()

# 검색하고자 하는 인물 7인
mb_han_lst = ['유재석', '지석진', '김종국', '하하', '송지효', '전소민', '양세찬']
mb_eng_lst = ['Yoo', 'ji', 'kim', 'ha', 'song', 'jeon', 'yang']
mb_index = [0,1,2,3,4,5,6]

# face_encodings은 128차원의 ndarray 데이터들을 사람 얼굴에 따라 리스트 자료형과 얼굴 위치좌표를 반환
def face_encodings(face_image, number_of_times_to_upsample=1, num_jitters=2):
    """Returns the 128D descriptor for each face in the image"""
    # Detect faces:
    # hog 기반의 dlib face detector. gray 변환된 영상을 사용.
    gray = cv.cvtColor(face_image, cv.COLOR_RGB2GRAY)
    face_locations = detector(gray, number_of_times_to_upsample)
    # Detected landmarks:
    raw_landmarks = [pose_predictor_5_point(face_image, face_location) for face_location in face_locations]
    # Calculate the face encoding for every detected face using the detected landmarks for each one:
    return face_locations, [np.array(face_encoder.compute_face_descriptor(face_image, raw_landmark_set, num_jitters))
                            for raw_landmark_set in raw_landmarks]


def saveObjects(file_name, data):       # data를 지정한 이름의 파일 file_name에 저장하기
    with open(file_name, "wb") as file:
        pickle.dump(data, file)

def loadObjects(file_name):             # 지정한 파일, file_name에서 읽은 객체를 반환하기
    with open(file_name, "rb") as file:
        return(pickle.load(file))

db = []
db_faces=[]
db_encoding1d=[]
db_labels=[]
for i in os.listdir('FaceImages/'):
    path = 'FaceImages/'+i
    img = cv.imread(path)
    img = cv.cvtColor(img, cv.COLOR_BGR2RGB)
    faces, known_image_encoding = face_encodings(img)
    img_face = img[faces[0].top():faces[0].bottom(), faces[0].left():faces[0].right(),:]
    db_faces.append(img_face)
    db_encoding1d.append(known_image_encoding[0])
    db_labels.append(i[0:i.find('_')])
    print(i)

db.append(db_faces)
db.append(db_encoding1d)
db.append(db_labels)

# 저장
saveObjects("db.bin", db)
'''