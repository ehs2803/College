src_folder = 'mission/'
dst_folder = 'dst/'
file_type = ['jpg', 'png', 'tif', 'txt', 'py']
key8=0b0011_1001

import os
import time

sz = os.path.getsize(__file__)
print(f'Program Size = {sz:#,}\n')#파일사이즈 출력

s_time = time.time() #시간측정 시작

if os.path.exists(dst_folder): #dst_folder 폴더가 있다면
    pass #아무동작도 안함.
else: #dst_folder 폴더가 없다면
    os.mkdir(dst_folder) #dst_folder 폴더 만들기

for i, j in enumerate(file_type): #처리할 확장자에 .확장자 형태로 저장
    temp = '.'+j
    file_type[i] = temp

lst_src=[] #file_type에 있는 확장자 파일 정보가 담길 리스트
for i, (path, sub_dir, files) in enumerate(os.walk(src_folder)):
    for filename in files:
        ext = os.path.splitext(filename)[-1]
        ext_and_lst = file_type
        for ext_nm in ext_and_lst:
            if ext_nm == ext.lower():  # 소문자로 바꾸어 비교한다.
                a = os.path.join(path, filename) #파일이름 저장
                b = os.path.getsize(path+"/"+ filename) #파일크기 저장
                lst_temp = [a,b]
                lst_src.append(lst_temp)
                break

for i in lst_src:
    dst = dst_folder + i[0][i[0].rfind('\\') + 1:]#저장경로+파일이름+확장자
    f1 = open(i[0], 'rb') # i[0]파일을 'rb'모드로
    f2 = open(dst, 'wb')  # dst파일로 저장. 'wb'모드로
    f = f1.read() #f에 f1내용읽어들이기
    f2.write(f) #f2에 f내용 쓰기
    f1.close() #f1파일닫기
    f2.close() #f2파일닫기

#암호화, 복호화 구현 못함

index=1
ch='\\'
for i in lst_src:
    filename_dst = dst_folder+i[0][i[0].rfind('\\')+1:] #암호화후 저장된경로+파일이름+확장자
    f1 = open(filename_dst, 'rb') #암호화후 저장된 파일 'rb'로 열기
    f2 = open(i[0],'rb') #원본파일 i[0]을 'rb'로 열기
    b = True # b가 True로 유지되면 두 파일내용이 같다.
    byte1 = f1.read(1) #byte1변수에 f1파일을 1바이트씩 읽기
    byte2 = f2.read(1) #byte2변수에 f2파일을 1바이트씩 읽기
    while byte1: #파일끝까지 계속해서 읽기
        if byte1!=byte2: #만약 1바이트씩 비교해서 다르면
            b=False #b를 False로
            break #while반복문 빠져나오기
        byte1 = f1.read(1) #f1을 계속해서 1바이트씩 읽기
        byte2 = f2.read(1) #f2를 계속해서 1바이트씩 읽기
    if b==True: #b가 True라면, 만약 두 파일내용이 같다면
        print(f'#{index:03}: {i[0][i[0].rfind(ch)+1:]}({i[1]:#,}), pass!!') #지정된형식으로 출력
        print(f'location: {i[0][:i[0].rfind(ch)]}')
        index=index+1
        print()
    else: #같지 않으면
        print(f'#{index:03}: {i[0][i[0].rfind(ch) + 1:]}({i[1]:#,}), fail!!')  #지정된형식 + fail 출력
        print(f'location: {i[0][:i[0].rfind(ch)]}')
        index = index + 1
        print()
    f1.close() #f1파일닫기
    f2.close() #f2파일닫기

c_time = time.time() #시간측정 종료
print('\nTotal Execution Time = {0:.4f}[sec]'.format(c_time - s_time)) #소요된 시간 출력