# 미션 1 --------------------------------------------------------------------------
# 위 소스를 참조로 하여 kx1 크기의 1차원 가우시간 커널을 반환하는 함수를 설계하시오
#       - 즉, getGaussianKernel() 함수를 설계하시오.
# 이를 기반으로 sepFilter2D() 함수를 사용하여 블러링을 행하시오.
# --------------------------------------------------------------------------------

import numpy as np
import cv2 as cv
from matplotlib import pyplot as plt

def getGaussianKernel(K, sigma):     # 가우시안 함수를 정의함.
    r = np.linspace(start=-K/2, stop=K/2, num=K, dtype=np.float32)
    y = np.exp(-r ** 2 / (2 * sigma ** 2))
    y /= np.sum(y)
    print(y, len(y))
    return y


image = cv.imread('../data/lenna.tif')

k = 50
sg = 15  # 시그마
k1 = getGaussianKernel(k, sg)
#k1 = cv.getGaussianKernel(ksize=6*sg+1, sigma=sg, ktype=cv.CV_32F)
dst = cv.sepFilter2D(src=image, ddepth=-1, kernelX=k1, kernelY=k1.T)    #  kernelY=k1.T도 같은 결과
cv.imshow(f"sepFilter2D: s={sg}, k1.shape={k1.shape}", dst)
cv.waitKey()
exit()







