# ========================================================================================================
# 자율 학습 과제 - 연습용..
# 영상의 10번째 줄부터 20번째 줄까지 가로 한 줄을 특정 색상(붉은 색)으로 바꾸시오.
# ? 부분을 적절한 표현으로 작성하면 됩니다...
# ========================================================================================================

import cv2 as cv

FullName = '../data/monarch.bmp'
img = cv.imread(FullName)
assert img is not None, 'No image file....!'  # 입력 영상을 제대로 읽어오지 못하여 NULL을 반환.
cv.imshow('Original', img)                 # 읽어들인 영상 출력하기
cv.waitKey(0)
cv.destroyWindow('Original')

col=img.shape[1]        # col=Number of column
RandomColor = [0, 0, 255]       # RandomColor를 붉은 색으로 지정
img[10:21, 0:col,] = RandomColor  # 특정 위치를 지정하여 가로 한 줄을 RandomColor로 대치
cv.imshow('Answer', img)        # 처리한 결과 보이기
cv.waitKey(0)
exit(0)
