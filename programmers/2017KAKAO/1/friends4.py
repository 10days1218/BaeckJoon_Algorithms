def solution(m, n, board):
    answer = 0
    dir_X = [0, 1, 1]
    dir_Y = [1, 0, 1]
    newX = [0 for x in range(3)]
    newY = [0 for x in range(3)]
    board = [list(i) for i in board]
    temp_board = [[0 for x in range(m)] for y in range(n)]
    final_board = [[0 for x in range(n)] for y in range(m)]
    test = [[i for i in board[j]] for j in range(m)]
    check = False

    while True:
        for i in range(0, m - 1):
            for j in range(0, n - 1):
                for k in range(0, 3):
                    newX[k] = i + dir_X[k]
                    newY[k] = j + dir_Y[k]

                if (
                    (test[i][j] == test[newX[0]][newY[0]])
                    and (test[newX[0]][newY[0]] == test[newX[1]][newY[1]])
                    and (test[newX[1]][newY[1]] == test[newX[2]][newY[2]])
                ):
                    board[i][j] = " "
                    board[newX[0]][newY[0]] = " "
                    board[newX[1]][newY[1]] = " "
                    board[newX[2]][newY[2]] = " "
                    check = True

        print(board)

        if check == False:
            break

        for j in range(0, n):
            for i in range(0, m):
                temp_board[j][i] = board[i][j]

        for i in range(0, n):
            cnt = temp_board[i].count(" ")
            if cnt != 0:
                for j in range(0, cnt):
                    temp_board[i].remove(" ")
                for j in range(0, cnt):
                    temp_board[i].insert(0, " ")

        for i in range(0, m):
            for j in range(0, n):
                final_board[i][j] = temp_board[j][i]

        for i in range(0, m):
            answer += final_board[i].count(" ")

        check = False
        # print(final_board)
    return answer


test1 = ["CCBDE", "AAADE", "AAABF", "CCBBF"]
# test1 = ["TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"]
ans = solution(4, 5, test1)
print(ans)

