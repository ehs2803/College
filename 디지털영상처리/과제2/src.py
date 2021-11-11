# 아래 Path와 Name은 그대로 현재 설정을 사용해 주세요....
# 현재 d:/dip/the_return_of_the_king.avi 파일을 입력 동영상으로 사용하고 있습니다.
Path = 'd:/dip/'
Name = 'the_return_of_the_king.avi'

import cv2 as cv
import time
import numpy as np

FullName = Path + Name

videoCapture = cv.VideoCapture(FullName)

total_count = int(videoCapture.get(cv.CAP_PROP_FRAME_COUNT))
fps = videoCapture.get(cv.CAP_PROP_FPS)
dly_ms = 1000/(fps)       # dly_ms: ms로 표시한 프레임간의 간격[ms]
size = (int(videoCapture.get(cv.CAP_PROP_FRAME_WIDTH)),
    int(videoCapture.get(cv.CAP_PROP_FRAME_HEIGHT)))

# 출력 저장용 동영상 -----------------------------
CODEC = cv.VideoWriter_fourcc('F', 'M', 'P', '4')          # 파일 용량 적음
fourcc = cv.VideoWriter_fourcc(*'DIVX')
fname = Name[0:-4]
SaveFileName = f'tmp_{fname}.avi'

videoWriter = cv.VideoWriter(SaveFileName, CODEC, fps, (size[0]*2, size[1]))

position_total = 500 # 트랙바 'position' 최대값
position = 0 # position 값
count = 0 # 프레임 카운트 값
margin=1
IsPlay = True # 동영상 일시정지 여부
Touched = False # 트랙바 'position' 값을 제어했는지 여부
wgt = 100 # 트랙바 'HE wgt' 값
sigma = 0 # 트랙바 'sigma' 값
scale=0 # 트랙바 'scale' 값
cnt = 0 # this_index 변수

# 트랙바 'HE wgt' 이벤트 함수
def callback_wgt(x):
    global wgt
    wgt = x

# 트랙바 'sigma' 이벤트 함수
def callback_sigma(x):
    global sigma
    sigma = x

# 트랙바 'scale' 이벤트 함수
def callback_scale(x):
    global scale
    scale = x

# 트랙바 'position' 이벤트 함수
def callback_position(x):
    global count, Touched, cnt, position
    position = x
    precount = count
    count=int(total_count*(x/position_total))
    cnt += (abs(count-precount) + 1)
    Touched=True

# 트랙바 설정 및 만들기
cv.namedWindow('video')
cv.createTrackbar('HE wgt', 'video', 100, 100,	callback_wgt)
cv.createTrackbar('sigma', 'video',	0, 10,	callback_sigma)
cv.createTrackbar('scale', 'video',	0, 10,	callback_scale)
cv.createTrackbar('position', 'video',	0, position_total,	callback_position)

# 히스토그램 평활화
def HistogramEqualization(img, wgt):
    img = (np.clip(255 * img, 0, 255)).astype('uint8')
    imgC = img.copy()  # img의 복사본을 하나 저장해 둔다.
    imgG = cv.cvtColor(img, cv.COLOR_RGB2GRAY)
    hist, bins = np.histogram(imgG, 256, [0, 255])

    cdf = hist.cumsum()  # 누적분포함수, Cumulative Distribution Function
    cdf_normalized = cdf / cdf.max()  # 0~1 범위의  정규화된 누적분포함수, NCDF
    mapping = 255*cdf_normalized

    LUT = mapping.astype('uint8')  # Look Up Table - 256바이트 크기. 화소 값 변환 테이블.
    imgCeq = LUT[imgC]  # 3채널 칼라 영상에 대한 LUT 기반 히스토그램 평활화

    imgCeq = (np.clip(imgC + (wgt*0.01*imgCeq), 0, 255)).astype('uint8')  # 원본영상 반영비율 조절
    return imgCeq

# 언샤프마스킹
def UnsharpMasking(img, sigma, scale):
    um = img + scale * (img - cv.GaussianBlur(src=img, ksize=(6*sigma+1, 6*sigma+1), sigmaX=sigma))
    return np.clip(um, 0, 1)

success, frame = videoCapture.read()
frame_dip = frame.copy()
frame_h = cv.hconcat([frame, frame_dip])
file_save_cnt = 0 # 이미지 파일 저장 시 파일 이름에 붙는 숫자.
while(1):
    k = cv.waitKey(1)
    if k==27: # esc
        break # 프로그램 종료
    elif k == 115: # s
        frame_h_save = frame_h.copy()
        frame_h_save = frame_h_save * 255 # 0~255 정구화
        filename = f'tmp{file_save_cnt:0>2}_{Name[:Name.rfind(".")]}.png' # 파일 이름
        cv.imwrite(filename, frame_h_save) # 파일 저장
        file_save_cnt+=1 # 파일 저장 횟수 1 증가
    elif k!=-1: # 그 외 키를 입력하면 다시 동영상 재생
        IsPlay=True

    if Touched==True:
        videoCapture.set(cv.CAP_PROP_POS_FRAMES, count) # 프레임 설정
        success, frame = videoCapture.read()  # 프레임을 읽어온다.
        if success!=True:
            break
        frame = frame / 255 # 0~1 정규화
        frame_copy = frame.copy()
        frame_hist = HistogramEqualization(frame_copy, wgt) # 히스토그램 평활화
        frame_hist_um = UnsharpMasking(frame_hist / 255, sigma, scale) # 언샤프 마스킹

        # 원본, 개선 이미지 프레임에 텍스트 출력
        frame_str = f'org_index = {count}'
        frame_hist_str = f'this_index = {cnt}'
        frame_hist_str2 = f'sigma={sigma}, scale={scale}, weight={wgt}'
        cv.putText(frame, frame_str, (10, 20), cv.FONT_HERSHEY_SIMPLEX, 0.6, (0, 0, 255), 2)
        cv.putText(frame_hist_um, frame_hist_str, (10, 20), cv.FONT_HERSHEY_SIMPLEX, 0.6, (0, 0, 255), 2)
        cv.putText(frame_hist_um, frame_hist_str2, (10, size[1]-10), cv.FONT_HERSHEY_SIMPLEX, 0.6, (0, 0, 255), 2)

        frame_h = cv.hconcat([frame, frame_hist_um]) # 원본영상과 개선영상 합치기
        cv.imshow('video', frame_h) # 보여주기
        Touched=False

    while success and IsPlay:  # Loop until there are no more frames.
        k = cv.waitKey(1)
        if k == 32:  # space
            IsPlay=False # 영상 멈추기
        elif k==27: # esc
            exit(0) # 프로그램 종료
        elif k==115: # s
            frame_h_save = frame_h.copy()
            frame_h_save = frame_h_save * 255
            filename = f'tmp{file_save_cnt:0>2}_{Name[:Name.rfind(".")]}.png'
            cv.imwrite(filename, frame_h_save)
            file_save_cnt += 1

        s = time.time()  # start. time in sec.
        cv.imshow('video', frame_h) # 프레임 보이기
        position+=1 # position 1 증가
        cv.setTrackbarPos("position", "video", position) # 트랙바 'position' 1증가된 값으로 설정
        videoCapture.set(cv.CAP_PROP_POS_FRAMES, count) # 프레임 설정
        success, frame = videoCapture.read()  # 프레임을 읽어온다.
        if success!=True:
            break
        frame = frame/255
        frame_copy = frame.copy()
        frame_hist = HistogramEqualization(frame_copy, wgt) # 히스토그램 평활화
        frame_hist_um = UnsharpMasking(frame_hist/255, sigma, scale) # 언샤프 마스킹

        # 원본, 개선 이미지 프레임에 텍스트 출력
        frame_str = f'org_index = {count}'
        frame_hist_str=f'this_index = {cnt}'
        frame_hist_str2 = f'sigma={sigma}, scale={scale}, weight={wgt}'
        cv.putText(frame, frame_str, (10, 20), cv.FONT_HERSHEY_SIMPLEX, 0.6, (0, 0, 255), 2)
        cv.putText(frame_hist_um, frame_hist_str, (10, 20), cv.FONT_HERSHEY_SIMPLEX, 0.68, (0, 0, 255), 2)
        cv.putText(frame_hist_um, frame_hist_str2, (10, size[1] - 10), cv.FONT_HERSHEY_SIMPLEX, 0.6, (0, 0, 255), 2)

        frame_h = cv.hconcat([frame, frame_hist_um]) # 이미지 합치기
        frame_h_video = (np.clip(255 * (frame_h), 0, 255)).astype('uint8') # 비디오로 저장할 이미지 가공
        videoWriter.write(frame_h_video)  # 비디어로 저장
        print("\rCurrent frame number = ", count, end=' ')
        while ((time.time() - s) * 1000) < (dly_ms - margin):  # dly_ms: ms로 표시한 프레임간의 간격[ms]
            pass

videoCapture.release()
cv.destroyAllWindows()
