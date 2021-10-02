# ========================================================================================================
# 미션 : 320x240의 영상을 촬영하여 그 영상과 그 영상의 모노의 영상을 가로로 이어 붙이고
# 이를 파일로 저장하시오.
# ========================================================================================================

import cv2 as cv
import numpy as np
import time

cameraCapture = cv.VideoCapture(0, cv.CAP_DSHOW)

N_width = 320; N_height = 240           # 120fps. 대다수 작동.

cameraCapture.set(cv.CAP_PROP_FRAME_WIDTH, N_width)
cameraCapture.set(cv.CAP_PROP_FRAME_HEIGHT, N_height)

size = (int(cameraCapture.get(cv.CAP_PROP_FRAME_WIDTH)),
    int(cameraCapture.get(cv.CAP_PROP_FRAME_HEIGHT)))

print('Changed Resolution : WIDTH*HEIGHT=', size)

success, frame = cameraCapture.read()
cameraCapture.release()

framem = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
height, width, channel = frame.shape
frameM = np.zeros((height, width, channel), dtype=np.uint8)

frameM[:,:,0]=framem[:,:]
frameM[:,:,1]=framem[:,:]
frameM[:,:,2]=framem[:,:]

cv.imshow('test', frameM)
cv.waitKey(0)
cv.destroyAllWindows()

two_h = cv.hconcat([frame, frameM])

cv.imwrite('two_h.jpg', two_h)