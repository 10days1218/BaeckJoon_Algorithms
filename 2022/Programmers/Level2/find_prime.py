import math


def solution(n, k):
    answer = -1
    prime_list = []

    n = change(n, k)
    p_list = n.split("0")

    while "1" in p_list:
        p_list.remove("1")

    while "" in p_list:
        p_list.remove("")

    for p in p_list:
        if prime_number(int(p)):
            prime_list.append(p)

    answer = len(prime_list)

    return answer


# 진수 변환 함수
def change(n, k):
    rev_base = ""

    while n > 0:
        n, mod = divmod(n, k)
        rev_base += str(mod)

    return rev_base[::-1]


# 소수 확인 함수:
def prime_number(n):
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

