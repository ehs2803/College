'''
3. 미션
    1. 실습 1의 예제를 pyplot으로 원본과 블러링 된 영상 2개(시그마=3, 시그마=15) 를 한 화면에 출력하시오.
    2. 원영상과 시그마(= 2, 5, 15)에 따른 다양한 출력 결과를 subplot을 이용하여 한꺼번에 출력하시오.
        조건 :
            시그마=2는 1차원 가우시안 커널로 가로 방향만 filter2D() 함수로 블러링. 필터는 가우시안 연산식을 통해 직접 정의할 것.
            시그마=5는 1차원 가우시안 커널로 세로 방향만 GaussianBlur() 함수로 블러링.
            시그마=15는 2차원 가우시안 커널로 양방향으로 filter2D() 함수로 블러링. getGaussianKernel을 기반으로 2차원 필터를 정의할 것.
'''

import cv2 as cv
import numpy as np
from matplotlib import pyplot as plt

N=5

image = cv.imread('../data/lenna.tif')
image = cv.cvtColor(image, cv.COLOR_BGR2RGB)

gauss1d = cv.getGaussianKernel(ksize=2*N+1, sigma=3, ktype=cv.CV_32F)       # 계수의 크기가 정규화된 커널을 반환한다.
sigma3_2d = gauss1d @ gauss1d.T

gauss1d = cv.getGaussianKernel(ksize=2*N+1, sigma=15, ktype=cv.CV_32F)       # 계수의 크기가 정규화된 커널을 반환한다.
sigma15_2d = gauss1d @ gauss1d.T

img3 = cv.filter2D(image, -1, sigma3_2d, borderType=cv.BORDER_DEFAULT)
img15 = cv.filter2D(image, -1, sigma15_2d)

fig = plt.figure(num='original and sigma=3 and sigma=15')
fig.patch.set_facecolor('green')            # 화면 바탕 색상을 정한다.
fig.patch.set_alpha(0.1)        # Alpha, transparency: 0이면 투명, 1이면 완전 불투명.

plt.subplot(1, 3, 1)
plt.imshow(image)
plt.axis('off')
plt.title('Original')

plt.subplot(1, 3, 2)
plt.imshow(img3)
plt.axis('off')
plt.title('sigmal=3')

plt.subplot(1, 3, 3)
plt.imshow(img15)
plt.axis('off')
plt.title('sigmal=15')

plt.show()

################################
def getGaussianKernel(K, sigma):     # 가우시안 함수를 정의함.
    r = np.linspace(start=-K/2, stop=K/2, num=2*K+1, dtype=np.float32)
    y = np.exp(-r ** 2 / (2 * sigma ** 2))
    y /= np.sum(y)
    y=np.array([y])
    #y=y.T
    print(y, len(y),y.shape, y.ndim)
    return y

k1 = getGaussianKernel(30, 50)
img2 = cv.filter2D(image, -1, k1, borderType=cv.BORDER_DEFAULT)

img5 = cv.GaussianBlur(src=image, ksize=(1, 31), sigmaX=0, sigmaY=5)   # 양방향 모두 블러링. 커널크기는 홀수여야함.

knl = cv.getGaussianKernel(ksize=2*15+1, sigma=15, ktype=cv.CV_32F)
knl2d_15 = knl @ knl.T
img15 = cv.filter2D(image, -1, knl2d_15)

plt.subplot(1, 4, 1)
plt.imshow(image)
plt.axis('off')
plt.title('Original')

plt.subplot(1, 4, 2)
plt.imshow(img2)
plt.axis('off')
plt.title('sigmal=2')

plt.subplot(1, 4, 3)
plt.imshow(img5)
plt.axis('off')
plt.title('sigmal=5')

plt.subplot(1, 4, 4)
plt.imshow(img15)
plt.axis('off')
plt.title('sigmal=15')

plt.show()
