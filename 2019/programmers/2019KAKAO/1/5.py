def solution(n, build_frame):
    answer = []
    for i, build in enumerate(build_frame):
        x, y, b, check = build[0], build[1], build[2], build[3]
        if(check == 1):
            if(b == 0):
                if(y == 0):
                    answer.append([x,y,0])
                else:
            if(b == 1):
                

    return answer
