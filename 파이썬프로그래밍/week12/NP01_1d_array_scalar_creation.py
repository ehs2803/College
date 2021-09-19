"""
개요:
   1차원 어레이와 numpy scalar를 정의하는 방법에 대하여 살핀다.

"""

import numpy as np


# ---------------------------------------------------------------------------------------------
# print_att()
#   입력 파라미터 변수(ndarray)에 대한 정보를 출력하는 함수
#   입력 파라미터는 변수의 스트링을 취한다.
# ---------------------------------------------------------------------------------------------


def print_att(str_a):
    # str_a를 스트링으로 간주하고 실제 값을 evaluate 한다.
    a = eval(str_a)
    print(f"\n{str_a}={a}")

    # type(): 자료형을 반환한다.
    print(f"type({str_a})={type(a)}")

    # shape: 행렬의 모양(행x열)을 지정하는 멤버변수
    print(f"{str_a}.shape={a.shape}")

    # ndim: 행렬의 차원을 지정하는 멤버변수
    print(f"{str_a}.ndim={a.ndim}")

    # dtype: 행렬의 원소의 데이터형을 지정하는 멤버변수. 행렬은 모두 같은 데이터형으로 구성된다.
    print(f"{str_a}.dtype={a.dtype}")

    # itemsize: 한 원소를 표현하기 위해 필요한 데이터의 바이트 수
    print(f"{str_a}.itemsize={a.itemsize}")

    # size: array에 들어 있는 총 원소의 수
    print(f"{str_a}.size={a.size}\n")


#"""
# --------------------------------------------------------------------------------------------------
# 실습 1: 1차원 매트릭스.
# n개의 원소를 갖는 1차원 매트릭스, a의 shape는 a.shape=(n,), a.ndim=1이다.
#   a.shape=(3,)      # 1x3 row vector가 3x1 column vector도 아닌 방향성이 없는 1차원 데이터이다.
#                     # 1x3 row vector와 3x1 column vector는 모두 2차원(ndim=2)이다.
#   a.ndim=1          # 1차원 matrix이다.
#
#   참고: python의 sequence 자료형과 유사. string, list, tuple은 sequence 자료형이라 한다.
#        그러나, 연산에 있어서는 sequence 자료형과 다른다.
#        사례:  sequence 자료형에 대한 +연산은 python에서는 concatenation으로 실현되지만, numpy에서는 각 요소에 대한 개별 덧셉으로 이루어진다.
#
# numpy에서는;
#   배열의 방향성이 있는, 즉 row/column 벡터는 2차원 매트릭스이다.
#       shape = (1, n): 2차원 matrix, row vector
#       shape = (n, 1): 2차원 matrix, column vector
#   1차원 데이터 배열은 그 방향성은 없다.
#       shape=(n,): 1차원 매트릭스, 방향이 없으므로 아래의 (1, n)/(n, 1) 매트릭스가 사용되는 연산에 사용할 수 있다.
#       1차원 배열은 len() 함수를 이용해 그 원소의 개수를 셀 수 있다.
#
# parm = ((1, 2, 3))      # (3,) array. 1차원
# parm = (1, 2, 3)      # (3,) array. 1차원
# parm = [1, 2, 3]      # (3,) array. 1차원
# parm = [[1, 2, 3]]      # (1, 3) array. 2차원
# parm = [(1, 2, 3)]      # (1, 3) array. 2차원
# parm = [((1, 2, 3))]      # (1, 3) array. 2차원
# --------------------------------------------------------------------------------------------------

# 1) 1차원 매트릭스 선언
print("1) 1차원 매트릭스 선언")
parm = [2, 3, 4]            # a.dtype=int32, a.itemsize=4
a = np.array(parm)
print_att('a')
# a=[2 3 4]
# type(a)=<class 'numpy.ndarray'>
# a.shape=(3,)          # 1x3 row vector가 아님에 유의. 그러나 대개의 경우 큰 무리없이 활용가능하다.
# 1x3 혹은 3x1벡터가 필요한 곳에 (3,) sequence를 활용가능하다.
# a.ndim=1
# a.dtype=int32
# a.itemsize=4
# a.size=3
# number of elements=3

# 2) 1차원 매트릭스는 치환행렬을 취해도 그 내용이 변하지 않는다. 방향이 없기 때문이다..
print("2) 1차원 매트릭스는 치환행렬을 취해도 그 내용이 변하지 않는다. 방향이 없기 때문이다..")
a_T = a.T            # a_T=a.transpose() 도 같은 표현이다.
print_att('a_T')
# a_T=[2 3 4]           # transpose가 전의 값, 형식이 같다.
# type(a_T)=<class 'numpy.ndarray'>
# a_T.shape=(3,)        # 3x1 column vector가 아님에 유의.
# a_T.ndim=1
# a_T.dtype=int32
# a_T.itemsize=4
# a_T.size=3
# number of elements=3


# --------------------------------------------------------------------------------------------------
# 실습 2: 0차원 매트릭스.
# 즉, scalar. 파이썬의 int나 float와 다른 점은 여기서는 numpy.ndarray 형이라는 것이다.
# 이 경우 0차원 ndarray 데이터는 shape=()가 된다.
# --------------------------------------------------------------------------------------------------

print("3) 0차원 매트릭스 선언")
parm = 0x327928347913487592345
print('type(parm)=', type(parm))
a = np.array(parm)
print_att('a')

# 64비트 이하의 데이터에 대해서는 8비트 truncation 가능.
# parm에 대해서는 처리 불가능
parm2 = 0x1234567890abcdef
b = (np.array(parm2)).astype(np.uint8)
print_att('b')
print(f'b={b:#x}')
