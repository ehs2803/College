"""

A Very Simple File Encrypter using XOR Operation and bit/byte Swapping
1. 파일의 각 바이트 데이터를 주어진 8비트의  암호 코드(변수이름 code8)와 XOR 연산을 행한다.
   연산을 행한 각 바이트 데이터를 임시변수 xor_data라 하자.

2. 이 데이터를 연속된 다음 자리와 자리바꿈을 하여 파일로 저장한다.
    1) 예를 들어 0x1234 => 0x3412로 저장된다.
    2) 상황에 따라 자리 바꿈의 정보를 미리 지정된 테이블에 따라 지정할 수도 있다.
    예를 들어 짝수단위로(예: 4바이트 단위) 자리 바꿈이 일어난다면, 3->0, 2->1 혹은 1->3, 0->2
    3) 각 바이트의 내부에서 bit swapping 방식도 가능할 것이다.

os.system('chcp 65001')     # utf-8 기반의 한글이 출력되는 페이지 모드로 설정한다.
os.system('dir')

"""
import os


data = 0b1010_1100
print('1. data:', type(data), data, f'{data:#x}')

code8 = 0b1000_0000
print('2. code8', type(code8), code8, f'{code8:#x}')

xor_data = data ^ code8
print('3. xor_data', type(xor_data), xor_data, f'{xor_data:#x}')

res_data = xor_data ^ code8
print('4. res_data', type(res_data), res_data, f'{res_data:#x}')

exit()


