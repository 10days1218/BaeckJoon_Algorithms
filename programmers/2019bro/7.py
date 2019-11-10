def solution(user, friends, visitors):
    answer = []
    userFriend = []
    noneFriend = {}

    for f in friends:
        if f[1] == "mrko":
            userFriend.append(f[0])
            if f[0] in noneFriend:
                del noneFriend[f[0]]
        else:
            if f[0] in noneFriend == False and f[0] in userFriend == False:
                noneFriend[f[0]] = 0
            if (
                f[1] in noneFriend == False
                and f[1] in userFriend == False
                and f[1] != user
            ):
                noneFriend[f[1]] = 0

    for v in visitors:
        if v in noneFriend == False and v in userFriend == False:
            noneFriend[v] = 1
            continue
        if v in noneFriend:
            noneFriend[v] += 1

    for f in friends:
        if f[0] in 
    return answer


u = "mrko"
f = [
    ["donut", "andole"],
    ["donut", "jun"],
    ["donut", "mrko"],
    ["shakevan", "andole"],
    ["shakevan", "jun"],
    ["shakevan", "mrko"],
]
v = ["bedi", "bedi", "donut", "bedi", "shakevan"]
solution(u, f, v)
