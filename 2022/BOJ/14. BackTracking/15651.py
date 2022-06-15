import sys

N, M = map(int, sys.stdin.readline().split())


def combination(com: list):

    if len(com) == M:
        print(" ".join(map(str, com)))
        return

    for i in range(1, N + 1):
        combination(com + [i])


combination([])