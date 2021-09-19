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
import numpy as np

# 사전에 지켜야할 변수명
input_file = "lenna.tif"      #파일 명
encoded_fname = '_' + input_file
decoded_fname = '__' + input_file


def print_num(num):
    print(f'{num:#,}(', end='')  # 1) 1000 단위로 , 구분하여 숫자 출력하기

    # 10000이하의 자릿수에 대해서 아라비아 숫자와 한글 (만, 천, 백) 혼용하기
    a10000 = int(num / 10000)
    if a10000 > 1:
        print(f'{a10000}만', end='')
    elif a10000 == 1:
        print(f'만', end='')
    else:
        pass

    for div, han in zip([1000, 100, 10], ['천', '백', '십']):
        a_1234 = num % (div * 10)
        a = int(a_1234 / div)
        if a > 1:
            print(f'{a}{han}', end='')
        elif a == 1:
            print(f'{han}', end='')
        else:
            pass
    a = a_1234 % 10
    if a > 0:
        print(f'{a})')
    else:
        print(')')

int_list = [12334567891, 20500, 1100007, 900001, 9028, 100, 15, 8, 0]
for i in int_list:
    print_num(i)

exit()

key = 0x1001_0011

# 각 바이트에 대해 key 값으로 xor한 후 상하위 4비트(nibble)를 서로 swapping 하여 반환한다.
# array_to_encode: ndarray to encode
# key: key code
def encode(array_to_encode, key):
    data = key ^ array_to_encode
    ret = np.right_shift(data, 4) + np.left_shift(data, 4)
    return ret

# 각 바이트에 대해 상하위 4비트(nibble)를 서로 swapping 한 후 key 값으로 xor 연산하여 반환한다.
# array_to_encode: ndarray to encode
# key: key code
def decode(array_to_encode, key):
    data = np.right_shift(array_to_encode, 4) + np.left_shift(array_to_encode, 4)
    ret = key ^ data
    return ret


# -------------------------------------------------------------------------------------
# 단계 1: 암호화 과정
# -------------------------------------------------------------------------------------
print('\nEncoding...')

# 1) 파일 전체를 한개의 변수로 읽어 낸다.
f_in = open(input_file, "rb")
bt_obj = f_in.read()    # whole byte objects
f_in.close()

# 2) 읽어 낸 bytes object를 1차원 ndarray 데이터로 바꾼다.
# 각 원소는 uint8 형으로 만들어야 한다.
print('1.2) bt_obj', type(bt_obj), len(bt_obj))
bt_obj_np = np.array(list(bt_obj), np.uint8)
print(type(bt_obj_np), bt_obj_np.shape, bt_obj_np.itemsize*bt_obj_np.size)

# 3) 8비트 key를 0차원 uint8 ndarry 데이터로 바꾼다.
# 그래야  ndarry 데이터와 손쉽게 연산할 수 있다.
#key8 = (key * np.ones(())).astype(np.uint8)    #
key8 = np.array(key, np.uint8)      # 0 dimensional ndarray data of uint8 type
print('1.3) key8:', type(key8))

# 4) 단 한 줄의 표현으로 모든 데이터와 xor 연산을 수행한다.
# 아래는 둘 중의 큰 데이터 형식으로 결과가 반환된다.
# 결과가 uint8이 되길 원하면 두 항이 모두 uint8이 되어야 한다.

coded_data = encode(bt_obj_np, key8)
print('1.4) coded_data:', type(coded_data), coded_data.shape, coded_data.itemsize*coded_data.size)

# 5) 암호화된 데이터를 저장한다.
f_out = open(encoded_fname, "wb")   # 암호화된 파일이름은 원본 앞에 _이 붙는다.
coded_data = list(coded_data)       # list 자료형으로 저장해도 된다.
f_out.write(coded_data)             # 아니면, 그냥 ndarray로 저장해도 된다.
f_out.close()



# -------------------------------------------------------------------------------------
# 단계 2: 복호화 과정
# -------------------------------------------------------------------------------------
print('\nDecoding...')

# 1) 암호화된 파일을 다시 읽어들인다.
f_in = open(encoded_fname, "rb")
bt_obj2 = f_in.read()    # whole byte objects
f_in.close()

# 2) 읽어낸 bytes object를 1차원 ndarray 데이터로 바꾼다.
# 각 원소는 uint8 형으로 만들어야 한다.
bt_obj2_np = np.array(list(bt_obj2), np.uint8)
print('2.2) bt_obj2',type(bt_obj2_np), bt_obj2_np.shape, bt_obj2_np.itemsize*bt_obj2_np.size)

# 3) key8은 단계 1에서 정의한 것을 그대로 사용한다.

# 4) 단 한 줄의 표현으로 모든 데이터와 xor 연산을 수행한다.
# 아래는 둘 중의 큰 데이터 형식으로 결과가 반환된다.
# 결과가 uint8이 되길 원하면 두 항이 모두 uint8이 되어야 한다.
decoded_data = decode(bt_obj2_np, key8)
print('2.4) decoded_data:', type(decoded_data), decoded_data.shape, decoded_data.itemsize*decoded_data.size)

# 5) 복원된 파일을 저장한다. --- ndarray로 저장한다...
f_out = open(decoded_fname, "wb")        # 복원된 파일은 원본 파일 이름의 앞에 __이 붙는다.
f_out.write(decoded_data)    # whole byte objects
f_out.close()

# 6) 복원된 파일을 저장한다. --- byte object로 저장한다...
#decoded_object = bytes(list(decoded_data))     # 리스트로부터 바이트 오브젝트를 만들 수 있다.
decoded_object = bytes(decoded_data)            # ndarray로도 바이트 오브젝트를 만들 수 있다.
print('2.6) decoded_object:', type(decoded_object), len(decoded_object))
f_out = open(decoded_fname, "wb")        # 복원된 파일은 원본 파일 이름의 앞에 __이 붙는다.
f_out.write(decoded_object)    # whole byte objects
f_out.close()


# -------------------------------------------------------------------------------------
# 단계 3: 원본과 복원된 데이터가 같은지 비교한다.
# -------------------------------------------------------------------------------------
print('\nComparing...')

# 1) ndarray 데이터 관점에서 비교한다.
# array_equal - 두 어레이가 모두 같은 값을 갖고 있는지 확인하는 함수
ret = np.array_equal(bt_obj_np, decoded_data)
print("3.1) array_equal(bt_obj_np, decoded)=", ret)


# 2) byte objects 관점에서의 비교
if bt_obj == decoded_object:       # 원본의 object vs decoded_object
    print('3.2) The two byte objects are equal.')

# 3) 파일 관점에서 비교한다.
#os.system('dir')

exit()






"""
# bytes' object is iterable.
for bt in bt_obj:  # bt_obj는 byte object이지만 bt는 int type이다.
    #print(type(byte), byte, ord(byte), hex(ord(byte)))
    print(type(bt), bt, hex(bt), f'{bt:#02x}')
file.close()



while byte:     # byte=false at end of file.
    print(type(byte), byte, ord(byte), hex(ord(byte)), f'{ord(byte):#2x}')
    #print(hex(byte))    # 'bytes' object cannot be interpreted as an integer
    byte = file. read(1)
#file. close()


ord(): Returns an integer representing the Unicode code point of the given Unicode character.
print('\n한:', ord('한'), f'{ord("한"):#2x}')

# 한꺼번에 처리한다.
file = open("2_sample.txt", "rb")
# 같은 파일을 2번 열지 않으려면 파일을 닫지 말고 아래 seek()를 수행하면 된다.
#file.seek(0) # 포인터를 0으로 향하게 만든다.
#file.seek(1)        # 맨 처음 바이트는 건너뛰고 1번 부터 액세스하게 만든다.

max_bytes = 10000
bt_obj = file. read(max_bytes)    # byte object
print('\nbt_obj:', type(bt_obj), len(bt_obj), bt_obj)

print("\n'bytes' object is index accessable.")
for i in range(len(bt_obj)):
    print(f'bt_obj[{i}]:', type(bt_obj[i]), f'{bt_obj[i]:#2x}')

print("\n'bytes' object is iterable.")
for bt in bt_obj:  # bt_obj는 byte object이지만 bt는 int type이다.
    #print(type(byte), byte, ord(byte), hex(ord(byte)))
    print(type(bt), bt, hex(bt), f'{bt:#02x}')
file. close()
"""



