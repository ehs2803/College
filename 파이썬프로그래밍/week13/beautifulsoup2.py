"""
XML와 JSON
"""


#import urllib.request                   # 내장된 모듈
from bs4 import BeautifulSoup

# ???? URL을 제시하고 xml 파일을 받을 수는 없을까
# z_beautifulsoup2.py에 제시되어 있음
with open("data/US08621662-20140107.XML", "r", encoding="utf8") as patent_xml:
    xml = patent_xml.read()             # 파일을 문자열로 읽어 오기

print(xml)

soup = BeautifulSoup(xml,"lxml")        # lxml 파서 호출

# invention-title 태그 찾기
invention_title_tag = soup.find("invention-title")
print(invention_title_tag.get_text())
