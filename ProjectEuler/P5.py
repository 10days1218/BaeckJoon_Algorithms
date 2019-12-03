# http://euler.synap.co.kr/prob_detail.php?id=5


def gcd(x, y):
    while y:
        x, y = y, x % y
    return x


def lcm(x, y):
    return x * y / gcd(x, y)


answer = 1

for i in range(1, 21):
    answer = lcm(answer, i)

print(answer)
