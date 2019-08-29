def solution(msg):
    answer = []
    dic = {}
    idx = 1
    cnt = 1

    for i in range(65, 91):
        dic[chr(i)] = idx
        idx += 1

    sub = 1
    while True:
        subStr = msg[0:sub]
        value = dic.get(subStr, 0)

        if value == 0:
            dic[subStr] = idx
            msg = msg[sub - 1 :]
            idx += 1
            cnt += 1
            sub = 1

        else:
            if len(answer) < cnt:
                answer.append(value)
            else:
                answer[cnt - 1] = value
            sub += 1

        if len(msg) < sub:
            break

    return answer


test = "ABABABABABABABAB"
# "TOBEORNOTTOBEORTOBEORNOT"
# "KAKAO"
print(solution(test))
