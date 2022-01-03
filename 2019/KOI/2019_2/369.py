n = int(input())
ans = 0
for i in range(1, n + 1):
    number = str(i)
    for c in number:
        if c == "3" or c == "6" or c == "9":
            ans += 1

print(ans)
