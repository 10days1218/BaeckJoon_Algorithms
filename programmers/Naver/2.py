def solution(drum):
    answer = 0
    n = len(drum[0])
    start = 0
    x, y = 0, 0
    check = False
    count = 0
    while start < n:
        if check == False:
            y, x = 0, start
            check = True
            continue

        if drum[y][x] == "#" and y + 1 < n:
            y += 1
        if drum[y][x] == ">" and x + 1 < n:
            x += 1
        if drum[y][x] == "<" and x - 1 >= 0:
            x -= 1
        if drum[y][x] == "*" and y + 1 < n:
            count += 1
            y += 1

        if count == 2:
            start += 1
            count = 0
            check = False
            continue

        if y == n - 1:
            answer += 1
            start += 1
            count = 0
            check = False

    return answer


d = ["######", ">#*###", "####*#", "#<#>>#", ">#*#*<", "######"]
solution(d)

