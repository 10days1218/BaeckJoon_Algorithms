num = int(input())
list = input()
list = list.split(' ')
list = [int(i) for i in list]
max = max(list)
total = 0
for i in list:
    total += i / max * 100

print("%.2f" % round(total / num, 2))