# 1987
def dfs(x, y, count):
    global ans
    global alpha
    ans = max(ans, count)
    for i in dir:
        X = x + i[0]
        Y = y + i[1]
        if X >= 0 and X < R and Y >= 0 and Y < C:
            j = ord(maps[X][Y]) - ord("A")
            if alpha[j] == False:
                alpha[j] = True
                dfs(X, Y, count + 1)
                alpha[j] = False


R, C = input().split()
R, C = int(R), int(C)
dir = [[1, 0], [0, 1], [-1, 0], [0, -1]]
maps = []
ans = 0
for i in range(0, R):
    str = input()
    maps.append(str)
alpha = [False for i in range(26)]
i = ord(maps[0][0]) - ord("A")
alpha[i] = True
dfs(0, 0, 1)
print(ans)

# R, C = 2, 4
# maps = ["CAAB", "ADCB"]

