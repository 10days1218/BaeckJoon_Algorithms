num1 = int(input())
list = []
score = ""
aver = 0
count = 0
s = []
for i in range(0, num1):
    score = input()
    list.append(score)

for i in range(0, num1):
    s = list[i].split(' ')
    s = [int(i) for i in s]
    aver = (sum(s) - s[0]) / s[0]
    for j in s[1:]:
        if (j > aver):
            count += 1
    print("%.3f" % round(count / s[0] * 100, 3) + "%")
    count = 0
