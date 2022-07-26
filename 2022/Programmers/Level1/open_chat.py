def solution(record):
    answer = []
    log = []
    user_dict = {}

    for r in record:
        o = r.split(" ")
        # 입장한 경우
        if o[0] == "Enter":
            uid, name = o[1], o[2]
            user_dict[uid] = name
            log.append([uid, "님이 들어왔습니다."])

        # 나간 경우
        elif o[0] == "Leave":
            uid = o[1]
            log.append([uid, "님이 나갔습니다."])

        # 이름을 바꾼 경우
        elif o[0] == "Change":
            uid, name = o[1], o[2]
            user_dict[uid] = name

    for l in log:
        name = user_dict[l[0]]
        answer.append(f"{name}{l[1]}")

    return answer
