num = int(input())
count = []
string = []
for i in range(0, num):
    string.append(input())

for i in range(0, num):
    tmp1, tmp2 = string[i].split(' ')
    count.append(int(tmp1))
    string[i] = tmp2

for i in range(0, num):
    for j in string[i]:
        for k in range(0, count[i]):
            print(j, end='')
    print()
