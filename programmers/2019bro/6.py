# -*- coding:utf-8 -*-
def solution(forms):
    answer = []
    strHash = {}

    for name in forms:
        length = len(name[1])
        for i in range(length - 1):
            s = name[1][i : i + 2]
            if s in strHash:
                strHash[s] += 1
            else:
                strHash[s] = 1

    for name in forms:
        for key in strHash.keys():
            if name[1].find(key) != -1 and strHash[key] >= 2:
                if (name[0] in answer) == False:
                    answer.append(name[0])

    answer.sort()
    print(answer)
    return answer


f = [
    ["jm@email.com", "제이엠"],
    ["jason@email.com", "제이슨"],
    ["woniee@email.com", "워니"],
    ["mj@email.com", "엠제이"],
    ["nowm@email.com", "이제엠"],
]

solution(f)

