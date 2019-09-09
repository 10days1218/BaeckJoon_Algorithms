from itertools import combinations


def solution(relation):
    answer = 0
    combi, unique, delList = [], [], []
    col = len(relation[0])
    row = len(relation)
    for i in range(1, col + 1):
        combi.extend([set(k) for k in combinations([j for j in range(col)], i)])

    for com in combi:
        checkSet = set()
        for i in range(0, row):
            tmp = ""
            for j in com:
                tmp += relation[i][j]
            checkSet.add(tmp)
        if len(checkSet) == row:
            unique.append(com)

    for i in unique:
        for idx, j in enumerate(unique):
            if i.issubset(j) and i != j and delList.count(j) == 0:
                delList.append(unique[idx])
    # print(unique)
    answer = len(unique) - len(delList)
    return answer


relations = [
    ["100", "ryan", "music", "2"],
    ["200", "apeach", "math", "2"],
    ["300", "tube", "computer", "3"],
    ["400", "con", "computer", "4"],
    ["500", "muzi", "music", "3"],
    ["600", "apeach", "music", "2"],
]
solution(relations)
