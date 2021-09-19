"""
    BeautifulSoup의 객체 메서드를 사용하여 xml 혹은 html 문서에서 지정한 tag의 문자열을 검색한다.
    객체 soup를 생성할 때는 markup 문서와 그 문서를 해석학 parser의 선택이 필요하다.
        soup = BeautifulSoup(markup=xml, features=parser)

US 특허 링크
    https://patents.google.com/patent/US20120260387

"""


import urllib.request                   # URL 접근을 위한 모듈
from bs4 import BeautifulSoup


# --------------------------------------------------------------------------------------------------
# 실험 1: 교과서에서 제공된 xml 파일로 특정 태그로 주어진 문자열을 찾는다.
# --------------------------------------------------------------------------------------------------

# 1) 현재의 폴더에 위치한 파일에서 읽어오기. xml을 읽어온다.
file_here = "data/US08621662-20140107.XML"  # 교과서 배포 파일
parser = "lxml"     # "lxml", "lxml-xml", "html.parser", or "html5lib"

with open(file_here, "r", encoding="utf8") as patent_xml:
    xml = patent_xml.read()             # xml 형식

# 2) 읽어들인 내용을 화면에 출력한다.
#print(xml)

# 3) 문서자료에 대해 parser를 지정한다.
soup = BeautifulSoup(markup=xml, features=parser)        # lxml 파서 호출 - xml, html 다 되는 듯.
print(type(soup))

# 4) 태그를 지정하여 문자열을 찾아 출력한다.
Tag = "invention-title"     # xml의 경우
print('\n------ using lxml')
invention_title_tag = soup.find(Tag)
print(f'1. Parsing Result from file, "{file_here}"\n', invention_title_tag.get_text())



# --------------------------------------------------------------------------------------------------
# 실험 2: 지정된 url의 html 문서를 다운받아 특정 태그로 주어진 문자열을 찾는다.
# --------------------------------------------------------------------------------------------------

# 1) URL을 제시하여 html을 읽어온다.
url = 'https://patents.google.com/patent/US20120260387'
f = urllib.request.urlopen(url)
html = f.read().decode('utf-8')       # html 형식

# 다운 로드받은 문서를 저장해 둔다.. => 파일명 intro.html
with open("intro.html", "w", encoding="utf8") as file_w:
    file_w.write(html)             # html 형식

# 2) 다운 받은 html을 출력한다.
#print(html)

# 3) parser를 지정한다.
soup = BeautifulSoup(html, "html.parser")   # html 파서 사용

# 4) 태그를 지정하여 문자열을 찾아 출력한다.
Tag = 'title'               # html의 경우
print('\n------ using html.parser')
invention_title_tag = soup.find(Tag)
print('2. Parsing Result from URL =\n', invention_title_tag.get_text())


# --------------------------------------------------------------------------------------------------
# 실험 3: 실험 2에서 URL에서 다운 받아 저장해 둔 html 파일로 특정 태그로 주어진 문자열을 찾는다.
# --------------------------------------------------------------------------------------------------

# 1) 현재의 폴더에 위치한 파일에서 읽어오기. 확인해 보면 html 문서이다.
file_here = "intro.html"        # 실험 2에서 URL에서 다운 받아 저장해 둔 파일
# parser: "lxml", "lxml-xml", "html.parser", or "html5lib"
parser = "lxml"         # lxml 파서 호출 - xml, html 다 된다.
#parser = "html.parser"

with open(file_here, "r", encoding="utf8") as f:
    txt = f.read()             # html 형식

# 2) 읽어들인 내용을 화면에 출력한다.
#print(txt)

# 3) 문서자료에 대해 parser를 지정한다.
soup = BeautifulSoup(markup=txt, features=parser)


# 4) 태그를 지정하여 문자열을 찾아 출력한다.
Tag = 'title'               # html의 경우
print(f'\n------ using {parser}')
invention_title_tag = soup.find(Tag)
print(f'3. Parsing Result from file, "{file_here}"\n', invention_title_tag.get_text())

