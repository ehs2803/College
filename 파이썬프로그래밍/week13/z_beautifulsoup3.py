"""

개요
    BeautifulSoup로 선언된 객체를 통해 수행 가능한 여러가지 method와 멤버 변수에 대해 익힌다.

BeautifulSoup methods
    find_all(tag)
        지정하는 태그(tag)를 검색해서 여러 개의 태그를 반환하는 함수
    get_text( )
        해당 태그 사이에 있는 값을 반환한다.

html 문서의 tag해석
    <a ...> ... </a>  => 해석 Tag a
    <a xx=yy> ==> xx는 Tag a의 attribute, attribute의 값은 yy
    A tag may have any number of attributes.
    The tag <b id="boldest"> has an attribute “id” whose value is “boldest”.
    You can access a tag’s attributes by treating the tag like a dictionary
    print(soup.b[id]) => 수행 결과 => boldest

참고 링크: https://www.crummy.com/software/BeautifulSoup/bs4/doc/

"""

from bs4 import BeautifulSoup


# --------------------------------------------------------------------------------------
# 단계 1: markup 문서 데이터를 확보한다. - 3가지 방법이 준비되어 있음.
# --------------------------------------------------------------------------------------

# 1) markup 문서 데이터를 소스에서 정의한다.
html_doc = """
<html><head><title>The Dormouse's story</title></head>

<p Class="title"><b>The Dormouse's story</b></p>

<p class="story">Once upon a time there were three little sisters; and their names were
<a href="http://example.com/elsie" class="sister" id="link1">Elsie</a>,
<a href="http://example.com/lacie" class="sister" id="link2">Lacie</a> and
<a href="http://example.com/tillie" class="sister" id="link3">Tillie</a>;
and they lived at the bottom of a well.</p>

<p class="story">...</p>
"""
# 2) 파일에서 읽고자 하면 아래의 주석처리를 해제하시오.
#with open('data/index.html', "r", encoding="utf8") as fp:
#    html_doc = fp.read()               # 파일을 문자열로 읽어 오기

"""
# 3) URL 링크에서 읽고자 한다면 다음을 사용하시오.
# 위 html 문서 데이터, html_doc과 비슷한 것을 다음의 링크에서도 볼 수 있다.
import urllib.request                   # URL 접근을 위한 모듈
url = 'https://computational-class.github.io/bigdata/data/test.html'
f = urllib.request.urlopen(url)
html_doc = f.read().decode('utf-8')       # html 형식
"""


# --------------------------------------------------------------------------------------
# 단계 2: BeautifulSoup 객체를 정의하고, 여러 method를 실험해 본다.
# --------------------------------------------------------------------------------------

soup = BeautifulSoup(html_doc, "lxml")
print(soup.prettify())


print(1, soup.title)
print(2, soup.title.string)

print()             # for 'p' Tag
print(3, soup.p)            # <p class="title"><b>The Dormouse's story</b></p>
# 속성이 대문자 Class로 선언되었으나, 이후 class로 간주하여 처리함. 속성은 소문자로 한정.
print(3.1, type(soup.p))        # 3.2 <class 'bs4.element.Tag'>
print(3.2, soup.p['class'])     # class attribute의 값을 출력.
print(3.3, soup.p.name, type(soup.p.name))   # Every tag has a name, accessible as .name:


# A Tag object corresponds to an XML or HTML tag in the original document
print()             # for 'a' Tag
print(4, soup.a)
print(4.1, type(soup.a))
print(4.2, soup.a['class'])     # class attribute의 값을 출력.
print(4.3, soup.a.name)     # Every tag has a name, accessible as .name:


print()
fnd_all = soup.find_all('a')
print(f'5. type(fnd_all)={type(fnd_all)}, len(fnd_all)={len(fnd_all)}')
for i, v in enumerate(fnd_all):
    print(f'5.1.{i+1}: {v}')
for i, v in enumerate(fnd_all):
    print(f"5.2.{i+1}: {v.get('href')}")


print()
print(6, soup.find(id="link3"))             # id="link3"인 Tag를 반환한다.
print(6.1, type(soup.find(id="link3")))     # <class 'bs4.element.Tag'>

print(7, soup.find('title'))         # 태그값을 기준으로 내용 불러오기 (최초 검색 결과만 출력)


print()
fnd_all = soup.find_all('p')
print(f'8. type(fnd_all)={type(fnd_all)}, len(fnd_all)={len(fnd_all)}')
for i, v in enumerate(fnd_all):
    print(f'8.1.{i+1}: {v}')
for i, v in enumerate(fnd_all):     # <class 'bs4.element.ResultSet'>
    #print(i, ')', msg.get_text())
    print(f'8.2.{i + 1}: {v.get_text()}')

print()
head_tag = soup.find('head')
print(9, head_tag.get_text())       # head 다음의 Tag 제외 문자열
print(9.1, head_tag.find('title'))
print(9.2, head_tag.find('title').get_text())



print()

