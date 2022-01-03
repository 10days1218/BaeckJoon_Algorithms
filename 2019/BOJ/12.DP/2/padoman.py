test_case = int(input())
dp = [1 for i in range(3)]

for i in range(test_case):
    n = int(input())
    for i in range(3, n):
        dp.append(dp[i - 3] + dp[i - 2])
    print(dp[n - 1])
    dp.clear()
    dp = [1 for i in range(3)]

