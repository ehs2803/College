"""

<class 'bytes'> 형 자료의 데이터를 해석하고 활용하는 방법에 대해 학습한다.
이 자료형은 파일의 바이너리로 읽어올 때 반환받는 데이터 형이다.
이 자료형은 출력할 때는 바이트 단위로 그 16진수 값을 출력하는데 ASCII 문자에 대해서는 해당 문자로 치환하여 출력한다.

참조 링크
# https://www.w3resource.com/python/python-bytes.php#:~:text=Bytes%20and%20bytearray%20objects%20contain,use%20the%20bytearray()%20function.


"""



# ----------- binary value를 선언하기.
code8 = 0b1000_0001
#code8 = 0x81       # 위와 같음.
print('1. binary representation:', type(code8), code8, f'{code8:#b}', f'{code8:#05x}' )
# <class 'int'> 129 0b10000001 0x081


# ----------- int를 이진수로 표현된 스트링으로 변환하기
str_code8 = bin(code8)
#str_code8 = f'{code8:#b}'   # 위와 같음.
print('2. int to string:', type(str_code8), str_code8, f'{code8:#16b}')
# <class 'str'> 0b10000001       0b10000001


# ----------- bytes object의 선언(1) - b''을 이용해 정의
a = b'\x00\01\x41\x30'      # b'\x00\x01A0'
# 바이트 오브젝트를 출력하면 바이트 단위로 출력한다.
# 이중 데이터가 8비트 ASCII 영역의 문자로 변환할 수 있는 코드는 해당 ASCII 문자로 변환해서 프린트한다.
# 나머지 8비트 데이터에 대해서는 \x 이후 16진수로 출력한다.
print("3. bytes object definition with b'':", type(a), len(a), a)
# <class 'bytes'> 4 b'\x00\x01A0'


# ----------- bytes object의 선언(2) - bytes() 함수를 이용해 정의.
# 정수로 구성된 [] 리스트를 지정하여 정의한다.
# 0~ff까지의 값에 대한 unicode character을 보인다.
b256 = bytes([v for v in range(256)])   # 0~255까지의 256바이트의 바이트 오브젝트를 선언
print("4. bytes object definition with bytes() function:", type(b256), len(b256))
# <class 'bytes'> 256
print(b256)
# b'\x00\x01\x02\x03\x04\x05\x06\x07\x08\t\n\x0b\x0c\r\x0e\x0f\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f !"#


# ----------- bytes object의 선언(3) - bytes() 함수를 이용해 정의.
# 스트링을 제공하여 정의
b = '\x00\x01A0'
c = '\x00\01\x41\x30'
bb = bytes(b, encoding='utf8')
cc = bytes(c, encoding='utf-8')
print("5.1 bytes object definition with bytes() function:", type(bb), len(bb), bb)
# <class 'bytes'> 4 b'\x00\x01A0'
print("5.2 bytes object definition with bytes() function:", type(cc), len(cc), cc)
# <class 'bytes'> 4 b'\x00\x01A0'


# ----------- bytes object를 list로 변환
d = b'01AB'                 # <class 'bytes'> 4 b'01AB' [48, 49, 65, 66]
#d = b'\x30\x31\x41\x42'     # <class 'bytes'> 4 b'01AB' [48, 49, 65, 66]
d = b'\x0a\x0d\xff'        # <class 'bytes'> 3 b'\n\r\xff' [10, 13, 255]
print('6. bytes to list:', type(d), len(d), d, list(d))
# <class 'bytes'> 3 b'\n\r\xff' [10, 13, 255]


# ----------- 한글이 들어 있는 바이트 오브젝트의 핸들링
# '한'=\xed\x95\x9c 한글문자 '한'은 utf8로 인코딩된 3바이트의 유니코드로 구성된다.
str_obj = '한'             # 한글이 포함된 string
bt_obj = bytes(str_obj, encoding='utf8')      # string to bytes object
print("7.1 hanguel string to bytes :", type(bt_obj), len(bt_obj), bt_obj)
# <class 'bytes'> 3 b'\xed\x95\x9c'
print("7.2 bytes to hanguel string :", str(bt_obj, 'utf-8'))
# 한
print("7.3 bytes to hanguel string :", str(bt_obj))
# b'\xed\x95\x9c'


bt_obj = b'01a\xed\x95\x9cA'   # a bytes object.
print('8. bt_obj:', type(bt_obj), len(bt_obj), bt_obj, str(bt_obj, 'utf-8'))
# <class 'bytes'> 7 b'01a\xed\x95\x9cA' 01a한A
