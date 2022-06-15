import sys

N, M = map(int, sys.stdin.readline().split())

def combination(com: list, start : int):

    if len(com) == M:
        print(' '.join(map(str, com)))
        return

    for i in range(start, N + 1):
        if i in com:
            continue

        combination(com + [i], i + 1)

combination([], 1)
