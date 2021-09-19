from bs4 import BeautifulSoup
with open("data/p02_researcher.xml", "r", encoding="utf-8") as researcher_xml:
    xml = researcher_xml.read()

parser = "html.parser"
parser = "lxml"

soup = BeautifulSoup(xml, features=parser)

print(soup.prettify())
#print(soup)    # 알아보기 불편

print('\n----------')

for i, element in enumerate(soup.findAll('researcher')):
    if i % 2 == 1:
        print(element['researcherid'])
        #print(element['researcherID'])      # 오류. 속성은 소문자.
        # 원본은 대문자로 선언되었으나, 출력해 보면 <researcher researcherid="0001"> 소문자로 바뀌어져 있다.
        print(element.na.get_text())
        print(element.salary)   # salary tag를 모두 출력.
        print(element.salary.get_text())
        print(element.salary['format'])
    else:
        pass
