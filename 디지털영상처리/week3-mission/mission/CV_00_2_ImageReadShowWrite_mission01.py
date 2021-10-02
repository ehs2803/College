#====================================================================================================================
# 미션 과제(1)
# 변수 fname로 주어진 영상 파일에 대해 주어진 미션을 완수히시오.
# fname = "../data/colorbas_chart.jpg"      # 단, 파일의 실제 이름은 바뀔 수도 있음.
# 0. fname으로 지정된 파일을 화면에 출력하시오..
# 1. 가로(column, 열) 및 세로(row, 행) 정보를 변수 a, b에 넣으시오.
#     a.shape
#    이를 이용하여 영상의 가로, 세로 정보를 출력하시오. => print(f'가로={a}, 세로={b}')
# 2. 영상의 면적을 출력하시오. => 면적 = 23674834
# 3. 파일이 칼라인지 모노 영상인지를 검사하여 그 결과를 출력하시오. => 영상은 '칼라 혹은 모노'입니다.
# 4. 해당 영상을 화면에 출력하시오. 이때 파일 이름이 타이틀 바에 출력되어야 합니다. 경로(path)를 제외하면 가점
# 5. 읽은 영상을 quality를 지정하여 현재의 폴더에 JPG 영상으로 저장하시오. 파일 이름은 tmp.jpg
#    quality는 사용자의 입력을 받아 지정하게 하면 가점. 못하겠으면 5로 고정.
# 6. 저장된 영상을 읽어 화면에 출력하시오 이때 타이틀 바의 이름은 "quality=?"
#     ? 값은 5로 고정하거나, 사용자 입력으로 정한 값으로 정한다. 사용자 입력 가점.
#====================================================================================================================

import cv2 as cv

# 0
Path = '../data/'       # . 현재 폴더, .. 바로 윗 폴더, ../data/ => 현재 폴더 바로 위 폴더 아래에 있는 data 폴더 아래
Name = 'colorbar_chart.jpg'
fname = Path + Name

print(fname)


img = cv.imread(fname)   # 칼라모드로 읽어낸다. default

# 1
a = img.shape[1]
b = img.shape[0]

print(f'가로={a}, 세로={b}')

# 2
c = a*b
print(f'면적 = {c}')

# 3
if len(img.shape) == 3:
    print('영상은 칼라입니다.')
else:
    print('영상은 모노입니다.')

# 4
winname_img = fname[fname.rfind('/')+1:]

cv.imshow(winname_img, img)

key = cv.waitKey(0)       # 이곳에서 키보드 입력을 무한정 기다린다.
cv.destroyWindow(winname_img)     # 지정한 이름의 창을 닫는다.

# 5
quality = int(input('사진 퀄리티를 입력하세요 : ')) # quality : 1 to 100. The higher is the better. quality is 95 default.

file_qual = 'tmp.jpg'              # 저장할 파일의 이름 = 원래이름+(q=05)

cv.imwrite(file_qual, img, (cv.IMWRITE_JPEG_QUALITY, quality))       # 영상을 주어진 품질(quality)로 저장한다.

# 6
fname = file_qual

img = cv.imread(fname)
cv.imshow(f'quality={quality}',img)

cv.waitKey(0)
cv.destroyAllWindows()
