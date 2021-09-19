import file_analysis as fa
import os
a='c:\\Windows\\'
#''' 이미 만들어진 txt파일 분석 시 5~8줄 주석문 처리필요
os.chdir(a)
os.system('chcp 65001')
os.system('dir > test.txt')
a=a+'\\test.txt'
#'''
lines = fa.read(a) #txt파일 열어서 내용 저장

contents = fa.readContent(lines) #분석할 의미있는 내용만 저장

DIR = fa.readDIR(contents) #폴더 정보 저장

FILE = fa.readFILE(contents) #파일 정보 저장

fa.writeContent(DIR, FILE) #출력