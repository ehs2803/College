# ========================================================================================================
# 미션 (2)
# monarch.bmp 영상의 좌측 상단을 제공된 흑백영상 2개를 좌측 상단, 우측 하단에 넣어 영상을 만들어 화면에 보이고, JPG로 저장하시오.
# 좌측 상단: char_90_A_256.bmp(0~255로 이루어진 영상), 우측 하단: char_A_bin.bmp(이진 영상 0, 255로 변환해야 할 것임)
# 출력 방법 - matplotlib, non-interactive mode로 먼저 보이고, 같은 내용을 openCV로 또 한번 더 보인다.
# 1. 일단 3개의 입력 영상을 각각 출력한다.
# 2. 좌측 상단, 우측 하단에 삽입한 monarch 영상을 보인다.
# 3. 위의 내용을 opencv로 한번 더 출력한다.
# ========================================================================================================

import cv2 as cv
from matplotlib import pyplot as plt

fname1 = '../data/monarch.bmp'
fname2 = '../data/char_90_A_256.bmp'
fname3 = '../data/char_A_bin.bmp'

#flags=-1: 있는 그대로.. 모노 그레이면 1채널, 칼라영상이면 3채널[BGR]을 반환한다.
#flags=0: 원래 영상에 관계 없이 모노 그레이, 1채널로 변환하여 반환한다.
#flags=1: 디폴트. 칼라 영상 뿐만 아니라 모노 그레이 영상도 3채널[BGR] 영상으로 변환하여 반환한다.
image1 = cv.imread(fname1)
image2 = cv.imread(fname2, -1)
image3 = cv.imread(fname3)

print(image1.shape, image2.shape, image3.shape)

cv.imshow(fname1[fname1.rfind('/')+1:], image1)
cv.imshow(fname2[fname2.rfind('/')+1:], image2)
cv.imshow(fname3[fname3.rfind('/')+1:], image3)
cv.waitKey(0)
cv.destroyAllWindows()

image1[0:image2.shape[0],0:image2.shape[1],]=image2
image1[image1.shape[0]-image3.shape[0]:,image1.shape[1]-image3.shape[1]:,]=image3

cv.imwrite('merge.jpg', image1)

image = cv.imread('merge.jpg')
cv.imshow('merge.jpg', image)
cv.waitKey(0)
cv.destroyAllWindows()

image = image[..., ::-1]
plt.figure('plt show')
plt.axis('off')
plt.imshow(image)
plt.show()


