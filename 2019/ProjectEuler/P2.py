# http://euler.synap.co.kr/prob_detail.php?id=2
a = 0
b = 1
sum = result = 0
while result < 4000000:
    result = a + b
    a = b
    b = result
    if result % 2 == 0:
        sum += result
print(sum)
