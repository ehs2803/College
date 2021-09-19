import os
import time
sz = os.path.getsize(__file__)
print(f'Program Size = {sz:#,}\n') #단계1. 파일크기 출력

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

int_list = [12334567891, 20500, 1100007, 900001, 9028, 100, 15, 8, 0, 2510]
s_time = time.time() #단계4. 시간측정시작

for i in int_list:
    print_num(i) #출력
# num_lines = 64
c_time = time.time() #시간측정 중단
print('\nTotal Execution Time = {0:.4f}[sec]'.format(c_time - s_time)) #시간측정 결과 출력