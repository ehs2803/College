# ========================================================================================================
# 미션 : cv.imread() 함수로 읽어 낸 3채널 영상을 칼라와 모노로 matplotlib 상하 2개 화면에 출력하시오.
# 단, 칼라 영상 정보의 모노 변환은 cv 함수의 cvtColor()를 쓰는 것으로 제한한다.
# ========================================================================================================

import cv2 as cv
from matplotlib import pyplot as plt

Path = '../data/'
Name= 'RGBColors.JPG'
FullName = Path + Name

imageC = cv.imread(FullName, flags=cv.IMREAD_COLOR)
imageRGB = imageC[..., ::-1]
imageM=cv.cvtColor(imageRGB, cv.COLOR_BGR2GRAY)

plt.figure(num='color and mono')

plt.subplot(211)
plt.imshow(imageRGB)
plt.title('color')
plt.axis('off')

plt.subplot(212)
plt.imshow(imageM, cmap='gray')
plt.title('mono')
plt.axis('off')
plt.show()

