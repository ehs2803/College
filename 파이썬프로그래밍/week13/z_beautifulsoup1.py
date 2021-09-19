"""
프로그램 수행을 위해서는 2개의 패키지 설치가 필요합니다.
1. pip install bs4              <= BeautifulSoup 패키지
2. pip install lxml             <= parser library

"""


from bs4 import BeautifulSoup

# --------------------------------------------------------------------------------------------------
# 단계 1: 분석할 xml 파일의 위치와 이름을 지정한다.
# 아래 2개의 방법 중 하나를 택한다.
# --------------------------------------------------------------------------------------------------

# 1) 소스 프로그램과 아래 xml 파일이 같은 폴더에 위치하는 경우
# 파이썬 콘솔에서 수행할 때는 xml 파일을 못 찾는 경우가 발생할 수 있다.
xml_file_name = "data/books.xml"

# 2) 다른 폴더에 있으면 그 위치를 다음과 같은 방법으로 지정해 주어야 한다.
#xml_file_name = "D:\\Work\\ch15\\books.xml"
#xml_file_name = "D:/Work/ch15/books.xml"


# --------------------------------------------------------------------------------------------------
# 단계 2: 파일을 읽고 그 내용을 화면에 출력한다.
# --------------------------------------------------------------------------------------------------

with open(xml_file_name, "r", encoding="utf8") as books_file:
    books_xml = books_file.read()               # 파일을 문자열로 읽어 오기

print(type(books_xml))
print(books_xml)
# 프린트가 안되었다면 books.xml 파일 읽기가 실패한 경우이다.


# --------------------------------------------------------------------------------------------------
# 단계 3: BeautifulSoup() 함수를 lxml parser를 이용해 파일을 분석한다.
# --------------------------------------------------------------------------------------------------

print('\n-------------------------------------------')
print('Parsing result')
print('-------------------------------------------\n')

soup = BeautifulSoup(books_xml, "lxml") # 형식=(문자열, 지정된_파서)

# 추출하고자 하는 요소의 Tag 지정
Tag = 'publisher'
Tag = "author"

result = soup.find_all(Tag)
print(f'type(result)={type(result)}, len(result)={len(result)}')
for info in result:
    print(info, end=' : ')
    print(type(info))
    print(info.get_text(), end=' : ')
    print(type(info.get_text()), '\n')    # 해당 요소에서 값 추출









"""
# 메모용: 작업 디렉터리를 바꾸는 사례. 본 예제와 직접적 관련은 없음. 
import os
os.getcwd()
Out[3]: 'D:\\Work\\@@PythonProgramming\\LectureMaterials'
os.chdir('12_(ch15)_XML_JSON/ch15')
os.getcwd()
Out[5]: 'D:\\Work\\@@PythonProgramming\\LectureMaterials\\12_(ch15)_XML_JSON\\ch15'
"""