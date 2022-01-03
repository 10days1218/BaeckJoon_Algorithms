def solution(s):
    answer = []
    window = 1
    string = ""
    check = ""
    idx = 0
    dic = dict()

    while window <= len(s):
        check = s[0:window]
        dic[check] = [1]
        for i in range(window, len(s), window):
            if i + window < len(s):
                tmp = s[i : i + window]
            else:
                tmp = s[i:]
            if tmp == check:
                dic[check][idx] += 1
            else:
                check = tmp
                if not check in dic:
                    dic[check] = [1]
                    idx = 0
                else:
                    dic[check].append(1)
                    idx = len(dic[check]) - 1

        for j in dic.items():
            for k in j[1]:
                if k > 1:
                    string += j[0] + str(k)
                else:
                    string += j[0]
        answer.append(len(string))
        window += 1
        string = ""
        dic = {}
        idx = 0
    answer.sort()
    print(answer[0])
    return answer[0]


S = "ababcdcdababcdcd"
# "aabbaccc"
solution(S)
