n = int(input())
d = []
for i in range(n):
    l = input().split(" ")
    d.append([int(i) for i in l])

dp = [[] for i in range(n)]

