def read(filename):
    f = open(filename, 'rt', encoding='utf-8')  # 파일 열기
    lines = f.readlines()  # 파일 내용 읽기
    f.close()  # 파일 닫기
    return lines #리스트 반환

def readContent(lines):
    contents=[]
    for line in lines:
        if '오후' in line or '오전' in line:  # 각 줄에 '오후' 혹은 '오전'이 있으면
            contents.append(line)  # contents리스트에 추가
    for i in range(len(contents)):
        contents[i] = contents[i].replace('\n', '')  # 각줄 맨뒤에있는 '\n'제거
    return contents #리스트 반환

def readDIR(contents):
    DIR=[]
    for content in contents:
        if '<DIR>' in content:  # '<DIR>'이 있는 문자열일 경우==폴더일 경우
            i = content.rfind(' ')  # 마지막부터 ' '을 찾아 변수i에 저장
            if content[i + 1:len(content)] != '.'  and content[i + 1:len(content)] != '..' :#폴더<.>,<..>제외
                DIR.append(content[i + 1:len(content)])  # 폴더이름을 DIR리스트에 저장
    return DIR #리스트 반환

def readFILE(contents):
    file=[]
    for content in contents:
        if '.' in content and '<DIR>' not in content:  # .(확장자)이있고, <DIR>(폴더)가 없는경우에
            i = 20  # 시간 이후 문자열 인덱스
            content_temp = content[20:]  # 그 이후 문자열 슬라이싱해서 content_temp에 저장
            content_temp = content_temp.lstrip()  # 왼쪽의 공백 제거
            j = content_temp.find(' ')  # ' '찾기
            size_str = content_temp[:j]  # 처음부터 j-1까지 슬라이싱해서 size_str에 저장
            while ',' in size_str:
                size_str = size_str.replace(',', '')  # 용량에서 ','를 반복문으로 모두 제거
            size = int(size_str)  # size변수에 size_str문자열 정수형으로 변환
            i = content_temp.rfind('.')  # 뒤에서부터 . 찾고 인덱스 반환
            name = content_temp[i + 1:]  # i+1부터 끝까지 슬라이싱=확장자명
            b = False  # 기존에 있는 중복파일명인지 선별해줄 bool형변수
            k = 0  # 기존에 있는 중복파일명이라면 그 파일명의 위치 인덱스 저장할 변수
            for j in range(len(file)):
                if file[j][0] == name:  # 만약 파일이름이 이미 저장되있는 문자열이라면
                    b = True  # b를 True로
                    k = j  # k에 찾은 인덱스 j를 저장
                    break  # 반복문 빠져나감
            if b == True:  # 만약 파일이름이 이미 file 이중리스트에 저장되있다면
                file[k][1] += 1  # 개수 1 증가
                file[k][2] += size  # 사이즈 추가
            else:  # 파일이름이 새로운 것이라면
                file.append([name, 1, size])  # [파일이름,개수초기값1,용량]저장
    file = sorted(file, key=lambda filename: filename[0]) #확장자 알파벳순서로 정렬
    return file #이중리스트 반환

def writeContent(DIR, file):
    print("{0:>10s}{1:>10s}{2:>10s}{3:>13s}".format("파일:","개수:","파일크기의합","퍼센트용량"))
    sum=0 #파일 전체용량 저장변수
    totalfile = 0 # 전체파일개수 저장변수
    for i in file:
        totalfile+=i[1] #파일개수 누적저장
    for i in file:
        sum+=i[2] #파일 전체용량 저장
    if sum==0: #파일 용량이 0일경우
        for i in file:
            print("{0:>10s}:{1:>10}{2:>15}{3:>15.5f} %".format(i[0], printNum(i[1]), printNum(i[2]),
                                                                                   (i[1]/totalfile)*100))
    else: #파일 용량이 있을경우
        for i in file:
            print("{0:>10s}:{1:>10}{2:>15}{3:>15.5f} %".format(i[0], printNum(i[1]), printNum(i[2]),
                                                                                   ((i[2] / sum) * 100)))
    print()
    if len(DIR)>0: #폴더가 있다면
        print("{0:>10} <{1}>".format("폴더:", DIR[0]))
        for i in range(1, len(DIR)):
            temp_str = "<"
            temp_str += DIR[i]
            temp_str += ">"
            print("{0:12}{1:<12}".format(" ", temp_str))
    else: #폴더가 없다면
        print("{0:>10} {1}".format("폴더:","없음"))

    print()
    print("\t   확장자의 수={0}, 폴더의 수={1}, 총 파일의 수={2}, 총 용량={3}".format(printNum(len(file)), printNum(len(DIR)),
                                                                       printNum(totalfile), printNum(sum)))
def printNum(num): #숫자를 천단위로 , 를 넣어 문자열로 반환하는 함수
    str_num = str(num)  #정수를 문자열로 변환
    num_len = len(str_num) #문자열 길이
    if num_len < 4:  #문자열길이가 4미만이라면
        return str_num  #그냥 반환
    else: #문자열길이가 4이상이라면
        numlist=list(str_num) #문자열을 리스트로 변환
        index = num_len-1 - 3 + 1
        numlist.insert(index,",") #, 삽입
        while True:
            index = index - 3 #인덱스 3빼기
            if index<=0: #인덱스가 맨앞자리거나 음수면 반복문 빠져나감
                break
            else:
                numlist.insert(index,",")#아니면 인덱스에 , 삽입
        str_num=''.join(numlist) #리스트를 문자열로 변환
        return str_num #문자열로 반환