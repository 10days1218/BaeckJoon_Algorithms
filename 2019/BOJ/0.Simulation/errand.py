total = 0
x, y = 0, 0
for i in range(4):
    total += int(input())

x = int(total / 60)
y = total - x * 60

print(x)
print(y)
