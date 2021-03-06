"""

* Trackbar_1에 구현된 아래 문제를 개선한다.
    1) 현재는 수정하지 하지 않은 다른 칼라까지도 while loop 안에서 무조건 새로 update한다.
        수정 포인트: cv.getTrackbarPos를 호출된 해당 함수 안에서 해당 칼라의 평면만 데이터를 갱신하도록 루틴을 수정하시오.
    2) 콜백함수를 호출할 때 이미 파라미터로 마우스의 위치가 전달되었지만
        getTrackbarPos 함수로 다시 마우스의 위치를 읽어내는 점이 불합리하게 설계되었다.
        수정 포인트
            3개의 콜백 함수는 자신이 클릭되었을 때의 채널 번호를 AdjustRGB() 함수에게 전달한다.
            포지션을 읽어보지 않아도 된다. 콜백함수를 호출할 때는 이미 그 위치가 전달된다.


1. 프로그램의 기능
    트랙바를 이용해 사각형 영상의 색상을 조절한다.

2. 프로그램의 목표
    트랙바를 설치하고 관리하는 기법을 습득한다.

3. 프로그램에서 점검 포인트
    호출되는 콜백함수에게는 마우스로 지정한 위치 정보와 사용자 데이터가 파라미터로 전달된다.

4. 참조
    https://opencv-python-tutroals.readthedocs.io/en/latest/py_tutorials/py_gui/py_trackbar/py_trackbar.html

    1) createTrackbar 함수의 사용법 - 트랙바를 설치하고 콜백 함수를 등록한다.
    int cv::createTrackbar (const String & 	trackbarname, 	# 트랙바 앞에 표시될 트랙바의 이름
        const String & 	winname,		# 트랙바가 나타날 창의 이름
        int * 	value,			# 시작 당시의 슬라이더의 초기 위치
        int 	count,			# 슬라이더의 최댓값. 최솟값은 0으로 고정.
        TrackbarCallback 	onChange = 0,	# 슬라이더가 움직일 때 호출될 콜백 함수의 이름
        void * 	userdata = 0) 		# 콜백 함수에게 넘겨질 사용자 데이터. 이 파라미터는 파이썬에서는 지원 안함.
        파이썬에서는 메인루틴의 변수가 함수에서 그대로 쓰여질 수 있는 사실상 전역변수화되기 때문에 필요가 없어서 때문인 듯하다.

    2) TrackbarCallback 함수에 대해..
        아래 typedef 문에 의해 함수는 2개의 파라미터가 실제로 불려질 함수에 넘어가게 된다.
        typedef void(* cv::TrackbarCallback) (int pos, void *userdata)

        Parameters
            pos: current position of the specified trackbar.
            userdata: The optional parameter.

    3) 트랙바의 위치 지정 및 위치 읽기
        cv.setTrackbarPos('트랙바의 이름', '창의 이름', 지정할 위치)
        반환받을 트랙바 위치 =cv.setTrackbarPos('트랙바의 이름', '창의 이름')

5. 미션 과제
    트랙바를 설치하여 영상을 밝게 혹은 어둡게 처리하는 프로그램을 작성하시오.
    밝음 조정 트랙바는 1~5까지의 값을 곱하는 연산으로 구성
    어둠 조정 트랙바는 1~5까지의 값으로 나누어 주는 연산으로 구성
    둘 중 하나의 트랙바를 조정하면 다른 하나는 1의 값으로 트랙바를 이동시킨다.
    복원 트랙바는 0이면 원본 영상 출력, 1이면 처리한 영상 출력
    주의 사항: 연산 결과는 부동소수로 프로그램 종료시까지 따로 간직하고
    출력 영상은 부동 소수 값을 clipping하며 출력용으로만 사용한다.
    즉, 출력용 영상에 연산을 시도하지 않는 것으로 한다.

"""



import numpy as np
import cv2 as cv
from matplotlib import pyplot as plt

# ========================================================================================================
# 섹션 1. define Call back function of Track bars
# 슬라이드 바를 움직이면 자동으로 호출되어 수행되는 함수를 정의한다.
# createTrackbar() 함수의 수행으로 설정된 트랙바의 움직임에 따라 지정한 해당 callBack() 함수가 호출된다.
# callBack() 함수가 호출될 때는 (x, *userdata)가 자동으로 입력된다.
#   x: 트랙 바에서 설정된 값(위치)
#   *userdata: 사용자 데이터, 여기서는 활용하지 않고 있음.
# 아래 callBack() 함수의 정의에서 각 함수들은 내부에서 함수 AdjustRGB(channel, x)를 공통적으로 호출한다.
# AdjustRGB(channel, x) 함수는 채널과 위치를 인자로 하여 해당 channel의 영상 데이터를 주어진 위치(픽셀 값, x)로 채운다.
# ========================================================================================================

def callBack_R(x):      # 첫 번째 파라미터, x: 트랙 바 위치=채워 넣을 화소 값.
    AdjustRGB(2, x)     # 2번 채널(Red)을 값 x로 채운다.

def callBack_G(y):
    AdjustRGB(1, y)     # 1번 채널(Green)을 값 x로 채운다.

def callBack_B(x):
    AdjustRGB(0, x)     # 0번 채널(Blue)을 값 x로 채운다.


# ========================================================================================================
# 섹션 2.
# BGR 트랙바가 움직일 때마다 해당 콜백함수에 의해 호출되어 영상 데이터를 갱신하고 화면을 출력한다.
# ========================================================================================================

def AdjustRGB(channel, x):
    img[:, :, channel] = x
    cv.imshow('image', img)


# ========================================================================================================
# 섹션 3.
# ON_OFF 트랙바의 설정에 변경을 가하면 호출된다.
# ========================================================================================================

def callBack_ON_OFF(s):
    if s == 0:
        cv.imshow('image', img_OFF)     # 미리 정의한 img_OFF(검은 색)를 출력한다.
    else:
        cv.imshow('image', img)         # RGB 슬라이드바로 선택한 영상을 출력한다.


# ========================================================================================================
# 섹션 4. define empty array and black array
# 향후 색을 채워 놓을 빈 영상 어레이와 흑백 영상을 어레이를 선언한다.
# ========================================================================================================

img = np.zeros((400, 800, 3), np.uint8)         # 색상을 채워 놓을 영상, (행, 열, 채널)
img_OFF = np.zeros((400, 800), np.uint8)         # 검은 영상
print(img.shape)

#cv.namedWindow('image')    # <= 이것만 쓰려면 창의 크기를 지정해 주어야 트랙바의 크기가 적게 열리는 것을 방지할 수 있다.
cv.imshow('image', img)     # 확실하게 처음부터 영상 크기로 연다.


# ========================================================================================================
# 섹션 5. install track bars
# 색상을 조정할 용도의 칼라 트랙바들과 화면 on/off 용도의 트랙바를 설치한다.
# ========================================================================================================

#user_data = [2, 1, 0]
cv.createTrackbar ('R', 	# 트랙바 앞에 표시될 트랙바의 이름
    'image',	# 트랙바가 나타날 창의 이름
    0,			# 시작 당시의 슬라이더의 초기 위치
    255,		# 슬라이더의 최댓값. 최솟값은 0으로 고정.
    callBack_R)	    # 슬라이더가 움직일 때 호출될 콜백 함수의 이름.
                    # 첫 번째 파라미터: 트랙 바 위치. 두 번째 파라미터: 사용자 데이터.

cv.createTrackbar('G', 'image', 0, 255, callBack_G)

cv.createTrackbar('B', 'image', 0, 255, callBack_B)

# ON/OFF 트랙바를 설치한다.
#switch = '0 : OFF \n1 : ON'
switch = 'OFF/ON'
cv.createTrackbar(switch, 'image', 1, 1, callBack_ON_OFF)



# ========================================================================================================
# 섹션 6. main loop
# 메인루프 - 사용자 입력만을 점검한다. 마우스 이벤트가 발생하면 해당 콜백 함수가 처리한다.
# ========================================================================================================

while(1):
    k = cv.waitKey(1) # & 0xFF
    if k != -1:     # break if any key in input. 무언가 키를 입력한 일이 없으면 -1을 반환한다.
        break

cv.destroyAllWindows()