#2577
num1 = int(input())
num2 = int(input())
num3 = int(input())
str1 = str(num1 * num2 * num3)

for i in range(0, 10):
    print(str1.count(str(i)))
