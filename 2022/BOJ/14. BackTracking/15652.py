import sys

N, M = map(int, sys.stdin.readline().split())


def combi4(com: list):

    if len(com) == M:
        print(" ".join(map(str, com)))
        return

    for i in range(1, N + 1):
        if len(com) > 0 and i < com[-1]:
            continue
        combi4(com + [i])


combi4([])
