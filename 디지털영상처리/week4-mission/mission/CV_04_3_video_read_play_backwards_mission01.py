# 미션 수행
# play 방법 2: 프레임과 프레임 간의 간격을 실제로 시간을 측정해서 필요한 만큼의 지연시간을 보충하는 방안.
# 아래 2가지 방법 중에서 여러분이 선택해서 도전해 보세요. (b) 방법이 성공하면 더 우대하여 평가하겠습니다.
#   (a) time() 함수를 사용. 영상처리에 시간이 많이 소요되어도 일정 시간 간격을 유지할 수 있음.
#       단, FPS시간 이내 작업이 이루어진다는 전제입니다. 예를 들어, 간단한 영상 처리만 한다는 전제입니다.
#       프레임과 프레임 간격 안에 필요한 처리을 못한다면 이 방법은 사용이 불가하겠죠.
#   (b) threading을 이용한 방안도 있을 것으로 보임. 강의 내용에 포함도지 않았음으로 자율적인 학습이 필요함.
#       '파이썬 스레드 프로그래밍' 등의 키워드로 검색하여 예제 프로그램을 활용하면 될 것으로 보임.

import cv2  as cv
import argparse
import time

Path = '../data/'
Name = 'frozen.mp4'
FullName = Path + Name

capture = cv.VideoCapture(FullName)


fps = capture.get(cv.CAP_PROP_FPS)
dly_ms = 1000/(fps)       # ms로 표시한 프레임간의 간격[ms]

# We get the index of the last frame of the video file:
frame_index = capture.get(cv.CAP_PROP_FRAME_COUNT) - 1

number_of_total_frames = int(capture.get(cv.CAP_PROP_FRAME_COUNT))

rate = 2       # 재생 시간이 rate 배로 저속 지생된다.
#rate = 1/2        # 재생 시간이 1/2 배로 저속 지생된다. => 2배 고속 재생된다.
dly_between_frames = rate*1000 / fps

# 프레임간의 시간지연 시간 조정. +이면 증가. -이면 감소. [ms] 단위,.
playing_sec = rate * number_of_total_frames/fps           # 상영시간[sec]


s_time = time.time()
while capture.isOpened() and frame_index >= 0:
    t_frame_s = time.time()
    capture.set(cv.CAP_PROP_POS_FRAMES, frame_index)    # We set the current frame position
    ret, frame = capture.read()     # Capture frame-by-frame from the video file
    if ret is True:
        # Print current frame number per iteration
        # print("CAP_PROP_POS_FRAMES : '{}'".format(capture.get(cv.CAP_PROP_POS_FRAMES)))
        # Get the timestamp of the current frame in milliseconds
        # print("CAP_PROP_POS_MSEC : '{}'".format(capture.get(cv.CAP_PROP_POS_MSEC)))
        cv.imshow('Original frame', frame)                  # Display the resulting frame
        frame_index = frame_index - 1                       # Decrement the index to read next frame
        print(f"\r  next index to read: {frame_index}", end='  ')
        if cv.waitKey(1) == ord('q'):      # Press q on keyboard to exit the program
            break        # Break the loop
        else:
            while((time.time() - t_frame_s) *1000 < dly_between_frames):   pass
                #continue
    else:
        break

e_time = time.time() - s_time
print(f'\n8.          play time in actual test = {e_time:#.2f}[sec]')