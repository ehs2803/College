# 미션 2 --------------------------------------------------------------------------
# 위 소스를 참조로 하여 kxk 크기의 2차원 가우시간 커널을 설계하시오.
# 위 소스를 참조로 하여 kxk 크기의 2차원 가우시간 커널의 3D 그래프를 출력하시오.
# kxk 2차원 커널을 이용하여 filter2D() 함수를 이용하여 영상의 블러링을 시행하시오.
# --------------------------------------------------------------------------------

import cv2 as cv
import numpy as np
from matplotlib import pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

N = 7
sigma=5

K = np.linspace(start=-N, stop=N, num=2*N+1, dtype=np.float32)       # X의 범위=[-N, +N]. stop를 포함하여 총 2*N+1개로 나눈다.
print(f"X.shape={K.shape}")
XX, YY = np.meshgrid(K, K)

def gaussian2D_yes(x, y, sigma):        # 2) 정규화를 한 경우
    tmp = np.exp(-(x ** 2 + y ** 2) / (2 * sigma ** 2))
    tmp = tmp/np.sum(tmp)
    return(tmp)

ZZ = gaussian2D_yes(XX, YY, sigma)      # 정규화를 한 경우. 합이 1이다.
print(f"ZZ.shape={ZZ.shape}, np.sum(ZZ)= {np.sum(ZZ)}")

'''
knl = cv.getGaussianKernel(ksize=6*sigma+1, sigma=sigma, ktype=cv.CV_32F)     # 1차원 가우시안 커널
print(knl.shape)        # (7, 1) ... (55, 1)
knl2d = knl @ knl.T     # @는 매트릭스 곱하기 연산자. 2차원 가우시안 커널
print(knl2d.shape)
#print(knl2d)
print(f"knl2d.shape={knl2d.shape}, np.sum(knl2d)= {np.sum(knl2d)}")
'''

fig = plt.figure(num='2D Gaussian function in 3D space')

ax = Axes3D(fig)
fig.add_axes(ax)

#ax.set_title("Gaussian: sigma=" + str(sigma))
ax.set_title("Gaussian: $\sigma$=" + str(sigma))
ax.plot_surface(XX, YY, ZZ, rstride=1, cstride=1, cmap='jet')
plt.show()

img = cv.imread('../data/lenna.tif')
dst = cv.filter2D(img, -1, ZZ)
cv.imshow(f"filter2D: sigma={sigma}, ZZ.shape={ZZ.shape}", dst)
cv.waitKey()
exit()