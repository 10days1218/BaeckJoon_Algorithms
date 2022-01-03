# https://www.acmicpc.net/problem/5532

a = []
n1, n2 = 0, 0
for i in range(5):
    a.append(int(input()))

n1 = int(a[1] / a[3])
if a[1] % a[3] > 0:
    n1 += 1

n2 = int(a[2] / a[4])
if a[2] % a[4] > 0:
    n2 += 1

ans = a[0] - max(n1, n2)

print(ans)
