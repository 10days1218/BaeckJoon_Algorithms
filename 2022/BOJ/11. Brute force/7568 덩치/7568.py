import sys

data = []

N = int(sys.stdin.readline())

answer = [1] * N

for i in range(N):
    x, y = map(int, sys.stdin.readline().split())
    data.append((x,y))


for i in range(0, N):
    for j in range(0, N):
        d1, d2 = data[i], data[j]
        if d1[0] < d2[0] and d1[1] < d2[1]:
            answer[i] += 1

print(*answer)