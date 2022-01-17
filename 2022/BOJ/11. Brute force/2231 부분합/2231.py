import sys

def get_digit(num: int) -> int :
    
    sum = 0
    str_num = str(num)

    for i in str_num:
        sum += int(i)
    return sum


answer = 9223372036854775807
N = int(input())

for i in range(0, N + 1):
    digit_sum = get_digit(i)
    if N == digit_sum + i:
        answer = min(answer, i)

if answer == 9223372036854775807:
    answer = 0


print(answer)