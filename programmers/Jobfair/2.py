def solution(bishops):
    answer = 0
    board = [[0] * 8 for i in range(8)]

    for i in bishops:
        x = ord(i[0]) - ord("A")
        y = int(i[1]) - 1
        tmp = 7 - y
        board[tmp][x] = 1
        slope = [1, -1]
        for a in slope:
            b = y - x * a
            for j in range(0, 8):
                ny = j * a + b
                if 7 - ny >= 0 and 7 - ny < 8:
                    board[7 - ny][j] = 1
                for i in range(0, 8):
                    print(board[i])
                print()

    for i in range(0, 8):
        for j in range(0, 8):
            if board[i][j] == 0:
                answer += 1
    return answer


solution(["D5", "E8", "G2"])
