a = int(input())
num = input()

list = list(num)
total = 0
for i in range(0, a):
    total += int(list[i])

print(total)