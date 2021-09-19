src_folder = 'mission/'

import os
import time
import numpy as np
import matplotlib.image as img
import matplotlib.pyplot as plt

sz = os.path.getsize(__file__)
print(f'Program Size = {sz:#,}\n')#단계1. 파일 사이즈 출력(주석문 포함)

def print_num(num):
    str_num = str(num)  #정수를 문자열로 변환
    num_len = len(str_num) #문자열 길이
    if num_len < 4: print(str_num, end='') #단계2. 1,000 단위 쉼표(,) 넣기 ...문자열길이가 4미만이라면 그냥출력
    else: #문자열길이가 4이상이라면
        numlist=list(str_num) #문자열을 리스트로 변환
        index = num_len - 3
        numlist.insert(index,",") #, 삽입
        while True:
            index = index - 3 #인덱스 3빼기
            if index<=0: #인덱스가 맨앞자리거나 음수면 반복문 빠져나감
                break
            else:
                numlist.insert(index,",")#아니면 인덱스에 , 삽입
        str_num2=''.join(numlist) #리스트를 문자열로 변환
        print(str_num2, end='') #출력
    if str_num == '0': #단계3. 10000 이하의 자릿수에 대한 아라비아 숫자와 한글표현 ... str_num이 0이라면
        print('()') #()만 출력
    elif num_len==1: #숫자길이가 1이라면
        print('({0})'.format(str_num)) #(숫자) 출력
    elif num_len==2: #숫자길이가 2라면
        print('(', end='')
        if str_num[0]!='1': print(str_num[0], end='')#십의자리가 1이 아닐때 십의자리 숫자출력
        print('십',end='') #'십'출력
        if str_num[1]!='0': print(str_num[1], end='')#일의자리가 0이 아닐때 일의자리 숫자출력
        print(')')
    elif num_len==3: #숫자길이가 3이라면
        print('(', end='')
        if str_num[0]!='1': print(str_num[0], end='') #백의자리가 '1'이 아니면 백의자리 숫자 출력
        print('백',end='') #'백'출력
        if str_num[1]!='0': #십의자리숫자가 '0'이 아닐때
            if str_num[1]=='1': print('십',end='') #십의자리숫자가 '0'이아니면서 '1'일때 '십'만 출력
            else : print(str_num[1]+'십',end='') #그외 숫자+'십'형태로 출력
        if str_num[2]!='0': print(str_num[2],end='') #일의자리숫자가 '0'이 아니면 일의자리숫자 그대로 출력
        print(')')
    elif num_len==4: #숫자길이가 4라면
        print('(', end='')
        if str_num[0] != '1': print(str_num[0], end='') #천의자리숫자가 '1'이 아니면 천의자리 숫자 출력
        print('천', end='') #'천'출력
        if str_num[1] != '0':#백의자리가 '0'이 아닐때
            if str_num[1]=='1': print('백', end='')#백의자리숫자가 '0'이 아니면서 '1'일때 '백'만 출력
            else: print(str_num[1] + '백', end='') #그외 숫자+'백'형태로 출력
        if str_num[2] != '0':#십의자리숫자가 '0'이 아닐때
            if str_num[2]=='1': print('십', end='')#십의자리숫자가 '0'이 아니면서 '1'일때  '십'만 출력
            else : print(str_num[2] + '십', end='')#십의자리숫자가 '0'이 아니면 숫자+'십'형태로 출력
        if str_num[3] != '0': print(str_num[3], end='') #일의자리숫자가 '0'이 아니면 일의자리숫자 그대로 출력
        print(')')
    else: #숫자길이가 5이상이라면
        print('(', end='')
        if(num_len==5): #숫자길이가 5일경우
            if str_num[0]!='1': print(str_num[0], end='') #만의자리수사가 '1'이 아니면 만의자리숫자출력
            print('만',end='') #'만'출력
        else: print(str_num[:len(str_num)-4] + '만', end='') #길이6이상일때 인덱스0부터 만의자리숫자까지 출력후 '만'출력
        if str_num[len(str_num)-4] != '0':#천의자리가 '0'이 아닐때
            if str_num[len(str_num)-4]=='1': print('천', end='')#천의자리숫자가 '0'아 아니면서 '1'일때 '천'만 출력
            else: print(str_num[len(str_num)-4] + '천', end='')#천의자리숫자가 '0'이 아니면 숫자+'천'형태로 출력
        if str_num[len(str_num)-3] != '0':#백의자리가 '0'이 아닐때
            if str_num[len(str_num)-3]=='1': print('백', end='')#백의자리숫자가 '0'이 아니면서 '1'일때 '백'만 출력
            else: print(str_num[len(str_num)-3] + '백', end='')#백의자리숫자가 '0'이 아니면 숫자+'백'형태로 출력
        if str_num[len(str_num)-2] != '0':#십의자리숫자가 '0'이 아닐때
            if str_num[len(str_num)-2]=='1': print('십', end='')#십의자리숫자가 '0'이 아니면서 '1'일때  '십'만 출력
            else: print(str_num[len(str_num)-2] + '십', end='')#십의자리숫자가 '0'이 아니면 숫자+'십'형태로 출력
        if str_num[len(str_num)-1] != '0': print(str_num[len(str_num)-1], end='')#일의자리숫자가 '0'이 아니면 숫자 그대로 출력
        print(')')

s_time = time.time() #단계2. 시간측정 시작

lst_jpg = [] #jpg사진이 담길 리스트
lst_png = [] #png사진이 담길 리스트
lst_tif =[] #tif사진이 담길 리스트
totalFilesize = 0 #총 파일 사이즈 저장 변수
for i, (path, sub_dir, files) in enumerate(os.walk(src_folder)):
    for filename in files:
        ext = os.path.splitext(filename)[-1]   # 파일 확장자를 반환함.
        ext_and_lst = zip(['.jpg', '.png', '.tif'], [lst_jpg, lst_png, lst_tif])
        for ext_nm, lst_n in ext_and_lst:
            if ext_nm == ext.lower():   # 소문자로 바꾸어 비교한다.
                a = os.path.join(path, filename)
                b = os.path.getsize(path+"/"+ filename)
                totalFilesize = totalFilesize + b
                lst_temp = [a,b]
                lst_n.append(lst_temp)
                break
#단계3. 파일 수, 확장자별 파일 개수 출력
print('Total number of picture files : {0}(jpg:{1}, png:{2}, tif:{3})'.format(
    len(lst_jpg)+len(lst_png)+len(lst_tif), len(lst_jpg),len(lst_png),len(lst_tif)))
print('Total size of files: ',end='')
print_num(totalFilesize)

lst = [lst_jpg, lst_png, lst_tif] #lst리스트에 확장자별 사진정보가 있는리스트 저장
sizeMax = ['', 0]#사이즈가 가장 큰 사진을 가정해 이름, 사이즈 두개정보를 sizeMax 리스트에 저장
sizeMin = ['', 99999999999999999999]#사이즈가 가장 작으 사진을 가정해 이름, 사이즈 두개정보를 sizeMin 리스트에 저장
for i in lst:
    for j in i:
        if j[1]>sizeMax[1]: #사이즈가 더 큰게 발견되면
            sizeMax[0]=j[0] #sizeMax[0]에 j[0]즉 사진 이름 저장
            sizeMax[1]=j[1] #sizeMax[1]에 j[1]즉 사진 사이즈 저장
for i in lst:
    for j in i:
        if j[1]<sizeMin[1]:#사이즈가 더 작은게 발견되면
            sizeMin[0]=j[0]#sizeMin[0]에 j[0]즉 사진 이름저장
            sizeMin[1]=j[1]#sizeMin[1]에 j[1]즉 사진 사이즈 저장

img1 = img.imread(sizeMax[0])#사이즈가 가장 큰 사진읽기
img2 = img.imread(sizeMin[0])#사이즈가 가장 작은 사진 읽기

temp=0 #비교변수
tall=['',0,0]#세로길이가 가장 긴 사진정보를 담을 리스트
for i in lst:
    if len(i)!=0 : #리스트i가 비어있지 않다면
        for j in i:
            temp_img = img.imread(j[0]) #반복문으로 모든 사진들 읽어오기
            n = np.array(temp_img.shape) #n에 읽어온사진 shape를 np.array를 통해 변환해 저장
            if (temp < n[0]): #그중에 세로길이가 더 큰게 발견되면
                tall[0] = j[0] #tail[0]에 j[0]즉 사진 이름저장
                tall[1] = n[0] #tail[1]에 n[0]즉 사진 세로길이 저장
                tall[2] = n[1] #tail[2]에 n[1]즉 사진 가로길이 저장
                temp=n[0] #비교변수를 갱신
temp=0 #비교변수
wide=['',0,0]#가로길이가 가장 긴 사진정보를 담을 리스트
for i in lst:
    if len(i)!=0:#리스트i가 비어있지 않다면
        for j in i:
            temp_img = img.imread(j[0])  #반복문으로 모든 사진들 읽어오기
            n = np.array(temp_img.shape) #n에 읽어온사진 shape를 np.array를 통해 변환해 저장
            if (temp < n[1]):#그중에 가로길이가 더 큰게 발견되면
                wide[0] = j[0] #wide[0]에 j[0]즉 사진 이름저장
                wide[1] = n[0] #wide[1]에 n[0]즉 사진 세로길이 저장
                wide[2] = n[1] #wide[2]에 n[1]즉 사진 가로길이 저장
                temp=n[1] #비교변수를 갱신

img3=img.imread(tall[0])#세로길이가 가장 긴 사진 읽기
img4=img.imread(wide[0])#가로길이가 가장 긴 사진 읽기

c_time = time.time()#시간측정 중단
print('\nTotal Execution Time = {0:.4f}[sec]'.format(c_time - s_time)) #소요시간 출력
#단계4. 그림 출력
ch='\\'
plt.figure(figsize=(15, 8), num='prob2') #창사이즈를 가로:15, 세로:8로 설정. 창 이름은 'prob2'로 설정
plt.subplot(221)  # 2x2 배열의 subplt 창에서 1번째 창 지정
plt.imshow(img1)
plt.title(f"max=\"{sizeMax[0][sizeMax[0].rfind(ch)+1:]}\":{sizeMax[1]:#,}")#해당창의 타이틀
plt.axis('off') # 영상의 경계가 보이지 않는다.

plt.subplot(222) # 2x2 배열의 subplt 창에서 2번째 창 지정
plt.imshow(img2)
plt.title(f"min=\"{sizeMin[0][sizeMin[0].rfind(ch)+1:]}\":{sizeMin[1]:#,}")#해당창의 타이틀
plt.axis('off') # 영상의 경계가 보이지 않는다.

plt.subplot(223) # 2x2 배열의 subplt 창에서 3번째 창 지정
plt.imshow(img3)
plt.title('tall='+'"'+tall[0][tall[0].rfind('\\')+1:]+'":('+str(tall[1])+', '+str(tall[2])+')')#해당창의 타이틀
plt.axis('off') # 영상의 경계가 보이지 않는다.

plt.subplot(224) # 2x2 배열의 subplt 창에서 4번째 창 지정
plt.imshow(img4)
plt.title('wide='+'"'+wide[0][wide[0].rfind('\\')+1:]+'":('+str(wide[1])+', '+str(wide[2])+')')#해당창의 타이틀
plt.axis('off') # 영상의 경계가 보이지 않는다.
plt.show()#사진출력