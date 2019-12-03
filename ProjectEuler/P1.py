# http://euler.synap.co.kr/prob_detail.php?id=1

number = [1 for i in range(1000)]
answer = 0
for i in range(3, 1000, 3):
    if number[i] == 1:
        number[i] = 0

for i in range(5, 1000, 5):
    if number[i] == 1:
        number[i] = 0

for i in range(1, 1000):
    if number[i] == 0:
        answer += i

print(answer)
