def solution(sticker):
    answer = 0
    MAX = len(sticker)
    dp = [[0] * 2 for i in range(MAX)]
    # 0이 뜯지 않을 때, 1이 뜯을 때
    dp[0][0] = 0
    dp[0][1] = sticker[0]

    for i in range(1, MAX):
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1])
        dp[i][1] = dp[i - 1][0] + sticker[i]

    answer = max(dp[MAX - 1][0], dp[MAX - 1][1])

    return answer
