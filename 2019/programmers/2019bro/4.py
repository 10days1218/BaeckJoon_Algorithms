def solution(infos, actions):
    answer = []
    order = []
    infoDict = {}
    loginCheck = False

    for i in infos:
        i = i.split(" ")
        infoDict[i[0]] = i[1]

    for i, action in enumerate(actions):
        cmd = action.split(" ")
        if cmd[0] == "LOGIN":
            if loginCheck == False:
                if infoDict[cmd[1]] == cmd[2]:
                    answer.append(True)
                    loginCheck = True
                else:
                    answer.append(False)
            else:
                answer.append(False)
        if cmd[0] == "ADD":
            if loginCheck:
                answer.append(True)
                order.append(cmd[1])
            else:
                answer.append(False)
        if cmd[0] == "ORDER":
            if len(order) > 0:
                answer.append(True)
                order.clear()
            else:
                answer.append(False)

    return answer
