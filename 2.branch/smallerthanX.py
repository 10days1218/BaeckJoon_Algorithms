num1, num2 = input().split()
list = str(input())
list = list.split(' ')

for i in list:
    if (int(i) < int(num2)):
        print(i, end=' ')

print()