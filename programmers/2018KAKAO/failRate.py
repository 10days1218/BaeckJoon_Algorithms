def solution(N, stages):
    answer = []
    stage = [0 for i in range(N + 2)]
    fails = [[0, 0] for i in range(N + 2)]
    for i in stages:
        stage[i] += 1

    for i in range(1, N + 1):
        fails[i][0] = i
        for j in range(i, N + 2):
            fails[i][1] += stage[j]
        if fails[i][1] != 0
            fails[i][1] = stage[i] / fails[i][1]
        else:
            fails[i][1] = 0

    del fails[0]
    fails = [tuple(l) for l in fails]
    fails = sorted(fails, key=lambda fail: fail[1], reverse=True)

    for i in fails:
        if i[0] != 0:
            answer.append(i[0])

    return answer


N = 5
S = [2, 1, 2, 6, 2, 4, 3, 3]
solution(N, S)
