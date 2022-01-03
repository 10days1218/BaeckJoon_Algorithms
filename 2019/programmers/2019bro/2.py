import re


def solution(logs):
    answer = [0 for i in range(24)]
    logs = logs.split("\n")
    p = re.compile("^([0-9]|0[0-9]|1[0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]$")
    for log in logs:
        log = log.split(" ")
        m = p.match(log[1])
        if m:
            # print(m.group())
            date = m.group().split(":")
            hour = int(date[0]) + 9
            if hour >= 24:
                hour -= 24
            answer[hour] += 1
    print(answer)
    return answer


l = "2019/05/01 00:59:19\n2019/06/01 01:35:20\n2019/08/01 02:01:22\n2019/08/01 02:01:23\n2019/08/02 03:02:35\n2019/10/03 04:05:40\n2019/10/04 06:23:10\n2019/10/10 08:23:20\n2019/10/12 08:42:24\n2019/10/23 08:43:26\n2019/11/14 08:43:29\n2019/11/01 10:19:02\n2019/12/01 11:23:10"
solution(l)
