n, k = map(int, input().split(" "))
medal = []
gold, silver, bronze = 0, 0, 0


for i in range(0, n):
    medal.append(list(map(int, input().split(" "))))
    if medal[i][0] == k:
        gold, silver, bronze = medal[i][1], medal[i][2], medal[i][3]

answer = 1

for i in range(0, n):
    if medal[i][0] == k:
        continue

    if medal[i][1] > gold:
        answer += 1
    elif medal[i][1] == gold and medal[i][2] > silver:
        answer += 1
    elif medal[i][1] == gold and medal[i][2] == silver and medal[i][3] > bronze:
        answer += 1

print(answer)
