num = int(input())

count = 0

if num < 100:
    count = num

else:
    count = 99
    for i in range(100, num + 1):
        n1 = int(i / 100)
        n2 = int((i % 100) / 10)
        n3 = i - n1 * 100 - n2 * 10
        if ((n1 - n2) == (n2 - n3)):
            count += 1

print(count)
