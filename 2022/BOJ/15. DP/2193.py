N = int(input())

answer = 0
dp = [0, 1, 1]


if N == 1 or N == 2:
    answer = dp[N]

else:
    for i in range(3, N + 1):
        tmp = dp [i - 1] + dp [i - 2]
        dp.append(tmp)
        answer = dp[-1]

print(answer)