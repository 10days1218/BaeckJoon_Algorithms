from itertools import combinations

N, S = map(int, input().split())
data = list(map(int, input().split()))

answer = 0
for  i in range(1, N + 1):
    com = list(combinations(data, i))
    for c in com:
        total = sum(c)
        if total == S:
            answer += 1

print(answer)

