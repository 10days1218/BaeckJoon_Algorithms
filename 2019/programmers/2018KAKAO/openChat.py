def solution(record):
    answer = []
    log = []
    userMap = dict()
    for i in record:
        records = i.split(" ")
        if records[0] == "Enter":
            log.append([records[1], "님이 들어왔습니다."])
            userMap[records[1]] = records[2]
        if records[0] == "Leave":
            log.append([records[1], "님이 나갔습니다."])
        if records[0] == "Change":
            userMap[records[1]] = records[2]

    for l in log:
        answer.append(userMap[l[0]] + l[1])
    return answer


rec = [
    "Enter uid1234 Muzi",
    "Enter uid4567 Prodo",
    "Leave uid1234",
    "Enter uid1234 Prodo",
    "Change uid4567 Ryan",
]
print(solution(rec))
