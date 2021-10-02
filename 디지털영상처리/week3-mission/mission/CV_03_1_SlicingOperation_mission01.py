# ========================================================================================================
# 미션 (1)
# 본 영상의 중심부만을 칼라로 표시하고 나머지 부분은 흑백으로 표시하시오.
#   - 예를 들어 3x3 영역으로 나누어 중심부 1개 영역만 칼라, 나머지 8개 영역은 흑백으로 표시합니다.
# 힌트: cvtColor
#   color conversion code : https://docs.opencv.org/3.4.3/d7/d1b/group__imgproc__misc.html#ga4e0972be5de079fed4e3a10e24ef5ef0
#   imgM = cv.cvtColor(image, cv.COLOR_BGR2GRAY)
# 주의: 3채널로 흑백영상을 표현하는 방법 => BGR 3개 채널을 같은 값으로 채워 넣는다.
# ========================================================================================================

import cv2 as cv

Path = '../data/'
Name= 'monarch.bmp'
FullName = Path + Name

imageC = cv.imread(FullName, flags=cv.IMREAD_COLOR)

#image = cv.cvtColor(imageRGB[20:50, 60:70,], cv.COLOR_BGR2GRAY)


width = imageC.shape[1]
height = imageC.shape[0]

width3 = int(width/3)
height3 = int(height/3)


imageC[height3:height3*2, width3:width3*2, 0]=imageC[height3:height3*2, width3:width3*2, 1]
imageC[height3:height3*2, width3:width3*2, 1]=imageC[height3:height3*2, width3:width3*2, 1]
imageC[height3:height3*2, width3:width3*2, 2]=imageC[height3:height3*2, width3:width3*2, 1]

cv.imshow('color and black', imageC)
cv.waitKey(0)
cv.destroyAllWindows()

