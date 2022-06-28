import sys

n = int(sys.stdin.readline())

answer = 0
board = [0] * n


def n_queen(x: int):
    global answer

    def is_promising(x: int):
        for i in range(x):
            if board[x] == board[i] or abs(x - i) == abs(board[i] - board[x]):
                return False

        return True

    if x == n:
        answer += 1
        return

    for i in range(n):
        board[x] = i
        if is_promising(x):
            n_queen(x + 1)


n_queen(0)
print(answer)
