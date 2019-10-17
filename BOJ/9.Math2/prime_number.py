# 1978

num = int(input())
list = []
count = 0
count_p = 0

list = input().split(' ')
list = [int(i) for i in list]

for i in list:
    for j in range(1,i+1):
        if i % j == 0:
            count_p += 1
          
    if count_p == 2:
        count += 1
    count_p = 0

print(count)
        