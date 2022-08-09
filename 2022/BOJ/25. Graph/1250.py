import sys
from queue import Queue


def dfs(x: int):
    visited[x] = True
    print(x, end=" ")

    for i in range(1, N + 1):
        if graph[x][i] and not visited[i]:
            dfs(i)


def bfs(start: int):
    q = Queue()
    q.put(start)
    visited[start] = True

    while not q.empty():
        # 자동으로 pop
        x = q.get()
        print(x, end=" ")

        for i in range(1, N + 1):
            if graph[x][i] and not visited[i]:
                q.put(i)
                visited[i] = True


N, M, V = map(int, sys.stdin.readline().split())
visited = [False for _ in range(N + 1)]  # visited = [False] * (N + 1)
graph = [[0 for _ in range(N + 1)] for _ in range(N + 1)]

for i in range(M):
    n, m = map(int, sys.stdin.readline().split())
    graph[n][m] = 1
    graph[m][n] = 1


dfs(V)
print()

visited = [False] * (N + 1)

bfs(V)
print()

