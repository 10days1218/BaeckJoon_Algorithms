def solution(user, friends, visitors):
    friendHash1 = {}
    friendHash2 = {}
    answer = []
    score = {}
    graph = [[] for i in range(0, 10001)]
    num = 1
    for friend in friends:
        for f in friend:
            if (f in friendHash.values()) == False:
                friendHash[num] = f
                friends[f] = num
                num+= +=1 
                

    for f in friends:
            friendNum1 = friendHash2[f[0]]
            friendNum2 = friendHash2[f[1]]
            graph[friendNum1].append(friendNum2)
            graph[friendNum2].append(friendNum1)

    
    for g in graph:
        

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
