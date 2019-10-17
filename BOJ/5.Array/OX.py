#8958
num = int(input())
arr = []
for i in range(0, num):
    arr.append(input())

total = 0
score = 0
for i in arr:
    for j in i:
        if j == 'O':
            score += 1
            total += score
        if j == 'X':
            score = 0
    print(total)
    total = 0
    score = 0
