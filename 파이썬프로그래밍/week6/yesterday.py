"""
# 실습 0: 원본
f = open("yesterday.txt", 'r')
yesterday_lyric = f.readlines() # 여러 줄들을 읽어 들인다.
f.close()

contents = ""
for line in yesterday_lyric:
    contents = contents + line.strip() + "\n"

n_of_yesterday = contents.upper().count("YESTERDAY")
print("Number of a Word 'Yesterday'" , n_of_yesterday)
"""





# 실습 1: 간략 수정본 -------
f = open("yesterday.txt", 'r')
yesterday_lyric = f.readlines()     # 가사 파일의 각 라인을 원소로 하는 리스트 자료형이 반환된다. 원소 수 = 라인 수
f.close()

print(type(yesterday_lyric), 'number of elements in the list=', len(yesterday_lyric))
# <class 'list'> number of elements in the list= 34

# 리스트의 원소를 관찰하여 보면 맨 끝에 \n이 들어 있음을 알 수 있다.
print(yesterday_lyric)

contents = ''.join(yesterday_lyric)
print(type(contents), 'number of letters=', len(contents))
# <class 'str'> number of letters= 669

#print(contents)     # 파일의 내용이 모두 출력된다.

print("number of '\\n codes=", contents.count('\n'))        # '\\ => '\은 다음 문자를 문자 자체로 처리하라는 요구
# number of '\n codes= 34

n_of_yesterday = contents.upper().count("YESTERDAY")
print("Number of a Word 'Yesterday'=" , n_of_yesterday)
# Number of a Word 'Yesterday'= 9

a=contents.replace('\n', '')    # \n을 ''로 대치. 사실상 삭제.
print(a)



# 실습 2: 파일에서 \n을 삭제 ------
