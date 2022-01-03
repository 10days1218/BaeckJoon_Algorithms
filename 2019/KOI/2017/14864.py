# https://www.acmicpc.net/problem/14864
import sys

flag = True
n, m = map(int, sys.stdin.readline().split())

lists = [i for i in range(n + 1)]

for i in range(0, m):
    a, b = map(int, sys.stdin.readline().split())
    lists[a], lists[b] = lists[a] + 1, lists[b] - 1


check = [False] * (m + 1)

for i in range(1, n + 1):
    j = lists[i]
    if check[j] == False:
        check[j] = True
        continue
    if check[j] == True:
        flag = False
        break

if flag:
    for i in range(1, n + 1):
        print(lists[i], end=" ")
    print()
else:
    print(-1)

