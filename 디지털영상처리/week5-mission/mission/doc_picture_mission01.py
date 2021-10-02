# ======================================================================================================================
# 미션 1: 실습 3을 2x2 서브 화면으로 나누고, 4번째 화면에는 양방향(가로/세로)으로 평균필터링한 영상을 출력하시오.
# ======================================================================================================================

import numpy as np
import cv2 as cv
from matplotlib import pyplot as plt

Path = '../data/'
Name = 'lenna.tif'
FullName = Path + Name

img = cv.imread(FullName)
assert img is not None, 'No image file....!'  # 입력 영상을 제대로 읽어오지 못하여 NULL을 반환.

img = img[..., ::-1]

N = 51

kernel_list = []         # 다수의 커널로 list 자료로 기록한다.

# 1) 1xN 커널 정의
kernel = np.ones((1, N), np.float32) / (N)      # 주의!!! N으로 나누어 커널의 합이 1이 되도록 정규화한다.
print('np.sum(kernel)=', np.sum(kernel))    # 커널의 총합을 확인.
kernel_list.append(kernel)

# 2) Nx1 커널 정의
kernel = np.ones((N, 1), np.float32)
kernel /= np.sum(kernel)   # 커널의 합으로 나누어 커널의 합이 1이 되도록 정규화한다.
print('np.sum(kernel)=', np.sum(kernel))    # 커널의 총합을 확인.
kernel_list.append(kernel)

# 3) NxN 커널 정의
kernel = np.ones((N, N), np.float32)
kernel /= np.sum(kernel)   # 커널의 합으로 나누어 커널의 합이 1이 되도록 정규화한다.
print('np.sum(kernel)=', np.sum(kernel))    # 커널의 총합을 확인.
kernel_list.append(kernel)
print(type(kernel_list))

fig = plt.figure(num='interactive mode')
plt.subplots_adjust(left=0.02, right=0.98, bottom=0.02, top=0.85)       # 상하좌우 여분 공백 제어하기
fig.patch.set_facecolor('green')            # 화면 바탕 색상을 정한다.
fig.patch.set_alpha(0.1)        # Alpha, transparency: 0이면 투명, 1이면 완전 불투명.

plt.suptitle("Averaging Filtering or Box Filtering", fontsize=14, fontweight='bold')

plt.subplot(2, 2, 1)    # 1x3 창의 첫번째 창 선택
plt.imshow(img)     # 원본 영상
plt.axis('off')
plt.title('Original')

i = 0   # kernel index
for knl in kernel_list:
    print(type(knl), knl.shape, knl.dtype)      # <class 'numpy.ndarray'> (1, 51) float32
    dst = cv.filter2D(img, -1, knl, borderType=cv.BORDER_DEFAULT)
    #print(f"dst.dtype={dst.dtype}")     # dst.dtype=uint8
    plt.subplot(220 + (i+2))      # 1x3 창의  (i+2)번째 창 선택
    plt.imshow(dst)     # filtering 결과 영상
    plt.axis('off')
    plt.title('Kernel=' + str(knl.shape))
    i += 1

#plt.show()      # interactive mode 일 때는 필요 없음
plt.waitforbuttonpress()        # 키 혹은 버튼 입력을 기다린다.
# 이후 프로그램이 종료되므로 모든 창이 닫힌다.
exit(0)
