# 아래 Path와 Name은 그대로 현재 설정을 사용해 주세요....
# 현재 d:/dip/dark1.png 파일을 입력 영상으로 사용하고 있습니다.
Path = 'd:/dip/'
Name = 'dark1.png'

import cv2 as cv

FullName = Path + Name
image_ori = cv.imread(FullName)/255 # 이미지 파일 읽어오기 + 0~1로 정규화

# 원본 이미지 복사해 'Original' text 그리기
image_ori_text = image_ori.copy()
cv.putText(image_ori_text, 'Original', (50, 50), cv.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)


Touched = False # 트랙바를 건드리면 True. 이 때만 연산을 다시 한다.
scale = 0 # 밝기 scale 크기

# scale 이벤트 함수
def callback_scale(x):
    global scale, Touched
    scale = x
    Touched = True

cv.namedWindow('image')
cv.createTrackbar('scale', 'image',	0, 30,	callback_scale)

image_scale = image_ori.copy() # 원본 이미지 복사
cv.putText(image_scale, 'Brighter', (50, 50), cv.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)  # 복사이미지에 'Brighter 출력'
image_h = cv.hconcat([image_ori_text, image_scale]) # 원본이미지, 복사이미지 가로로 붙이기
cv.imshow('image', image_h) # 이미지 출력
while(1):
    k = cv.waitKey(1)
    if k == 115: # 's' 키를 누르면 사진 저장
        image_scale_save = image_ori.copy() # 원본영상 복사
        image_scale_save = image_scale_save* (1+0.1*scale) # 밝게 만들기
        image_scale_save = image_scale_save * 255 # 0~255로 정규화
        image_save_filename = f'tmp{scale:0>2}_{Name[:Name.rfind(".")]}.png' # 저장할 파일 이름
        cv.imwrite(image_save_filename, image_scale_save) # 이미지 저장
    elif k== 27: # esc 키를 누르면 종료
        break
    if Touched==True:
        image_scale = image_ori.copy() # 원본영상 복사
        image_scale = image_scale * (1 + 0.1 * scale) # 밝게 만들기
        cv.putText(image_scale, 'Brighter', (50, 50), cv.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2) # 'Brighter 출력'
        image_h = cv.hconcat([image_ori_text, image_scale]) # 원본이미지, 밝게만든 이미지 가로로 붙이기
        cv.imshow('image', image_h) # 이미지 출력
        Touched=False

cv.destroyAllWindows()

