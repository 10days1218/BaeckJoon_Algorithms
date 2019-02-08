num = int(input())
s1, s2, s3 = input().split(' ')
list = [int(s1), int(s2), int(s3)]
max = max(list)
total = 0
for i in list:
    if (int(i / max) != 1):
        total += i / max * 100
    else:
        total += max

print(round(total / num, 2))
