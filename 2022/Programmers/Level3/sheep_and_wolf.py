visited = [0] * (1 << 17)
answer = 0
def dfs(node:int, state:int, info:list, edges:list):
    global answer
    
    if visited[state]: # 이미 방문한 경로인 경우
        return
    
    print(bin(state), node)
    
    visited[state] = True
    
    wolf, num = 0, 0
    
    # 늑대, 양 세기
    for i in range(len(info)):
        if state & 1 << i: # 방문한 노드라면
            num += 1
            wolf += info[i]
            
    if wolf * 2 >= num:
        return
    
    # 최대 양의 개수 구하기
    answer = max(answer, num - wolf)
    
    # 다음 노드 탐색
    for edge in edges:
        p, c = edge[0], edge[1]
        if p != node:
            continue
        
        if not (state & 1 << c):
            dfs(c, state | 1 << c, info, edges)
        

def solution(info, edges):
    
    dfs(0, 1, info, edges)
    return answer

if __name__ == "__main__":

    info = [0,0,1,1,1,0,1,0,1,0,1,1]
    edges = [[0,1],[1,2],[1,4],[0,8],[8,7],[9,10],[9,11],[4,3],[6,5],[4,6],[8,9]]
    solution(info, edges)