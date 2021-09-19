"""
프로그램 수행을 위해서는 2개의 패키지 설치가 필요합니다.
1. pip install bs4              <= BeautifulSoup 패키지
2. pip install lxml             <= parser library


import os
os.getcwd()
Out[3]: 'D:\\Work\\@@PythonProgramming\\LectureMaterials'
os.chdir('12_(ch15)_XML_JSON/ch15')
os.getcwd()
Out[5]: 'D:\\Work\\@@PythonProgramming\\LectureMaterials\\12_(ch15)_XML_JSON\\ch15'

"""

"""
# 프로그램을 실행하기 전에 먼저 작업 디렉터리를 현재 소스가 있는 지점으로 바꾸어야 한다. 
import os
os.getcwd()
os.chdir('12_(ch15)_XML_JSON/ch15')
os.getcwd()
exit(0)
"""

from bs4 import BeautifulSoup

# 1) 이 프로그램이 수행할 때의 현재 폴더가 아래 파일과 일치하는 경우에 가능
# 그렇지 않다면 os.chdir() 명령어로 위치를 바꾸어 주어야 한다.
#xml_file_name = "books.xml"

# 2) xml 파일의 절대 위치를 자신의 예제 프로그램 설치 상태에 따라 바꾸어주어야 한다.
#xml_file_name = "D:\\Work\\@@PythonProgramming\\LectureMaterials\\12_(ch15)_XML_JSON\\ch15\\books.xml"
xml_file_name = "D:/Work/@@PythonProgramming/LectureMaterials/12_(ch15)_XML_JSON/ch15/books.xml"
with open(xml_file_name, "r", encoding="utf8") as books_file:
    books_xml = books_file.read()               # 파일을 문자열로 읽어 오기

print(type(books_xml))
print(books_xml)
# 프린트가 안되었다면 books.xml 파일 읽기가 실패한 경우이다. 작업 디렉터리를 books.xml가 있는 곳으로 변경해야 한다.

soup = BeautifulSoup(books_xml, "lxml")         # lxml 파서를 사용해 데이터 분석

# author가 들어간 모든 요소의 값 추출
for book_info in soup.find_all("author"):
    print(book_info)
    print(book_info.get_text())                 # 해당 요소에서 값 추출
