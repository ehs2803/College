#====================================================================================================================
# 미션 과제(3)
# 파일의 이름과 영상 품질을 키보드로 입력 받아 저장하는 프로그램을 작성하시오.
# 사용 예: python lenna.bmp out.jpg 20         # lenna.bmp 영상을 입력 받아 out.jpg로 저장.
#====================================================================================================================

import cv2 as cv

infile = input()
outfile = input()
quality = int(input())


img = cv.imread(infile)

cv.imwrite(outfile, img, (cv.IMWRITE_JPEG_QUALITY, quality))