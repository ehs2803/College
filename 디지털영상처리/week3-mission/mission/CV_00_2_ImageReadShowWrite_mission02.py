#====================================================================================================================
# 미션 과제(2)
# 영상 품질을 키보드로 입력 받아 저장하는 프로그램을 작성하시오.
# 이때 파일 확장자는 jpg를 가정하며 이는 입력받지 않는다.
# 활용 예: lenna.tif를 입력받아 quality=20인 abc.jpg로 변환하여 저장하한다.
#   input file:lenna.tif
#   out file:abc
#   quality:20
#
#  만약 입력 영상이 위치한 곳이 현재 폴더 위의 data 폴더에 위치한다면
#  입력할 파일명은 ==> "../data/lenna.tif"
#====================================================================================================================

import cv2 as cv

infile = input('input file:')
outfile = input('out file:')
quality = int(input('quality:'))

outFileName = outfile+'.jpg'

img = cv.imread(infile)

cv.imwrite(outFileName, img, (cv.IMWRITE_JPEG_QUALITY, quality))


