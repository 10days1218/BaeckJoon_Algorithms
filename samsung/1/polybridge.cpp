//#17472
#include <bits/stdc++.h>
using namespace std;
/*
1. 섬에 번호 붙이기
2. 다른 섬과 이어지는 다리 만들기
3. 최소 스패닝 트리 만들기
    - union-find로 사이클 생성을 확인 
    - 사이클 생성 확인 방법
    find 함수를 이용해서 부모가 같은지 확인
    1. 부모가 같은 경우 -> 연결 하지 않음
    2. 부모가 다른 경우 -> 연결(union)
4. 모든 섬과 연결 되어 있는지 확인
    - 모두 부모가 같은지 확인 한다.
*/

struct POS
{
    int y;
    int x;
};

struct BRIDGE
{
    int src;
    int dest;
    int len;
};

bool operator<(const BRIDGE t, const BRIDGE u)
{
    return t.len < u.len;
}

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m;
int maps[10][10];
int parent[7];
vector<POS> islandEdge[7];
vector<BRIDGE> bridge;

void make_island(int y, int x, int num)
{
    maps[y][x] = num;
    // bool water = false;
    queue<POS> q;
    POS p;
    p.y = y, p.x = x;
    q.push(p);

    while (!q.empty())
    {
        bool water = false;
        p = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int ny = p.y + dy[dir], nx = p.x + dx[dir];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;

            if (maps[ny][nx] == -1)
            {
                maps[ny][nx] = num;
                POS t;
                t.y = ny, t.x = nx;
                q.push(t);
            }

            else if (maps[ny][nx] == 0)
            {
                water = true;
            }
        }
        if (water)
        {
            POS t;
            t.y = p.y, t.x = p.x;
            islandEdge[num].push_back(t);
        }
    }
}

void make_bridge(POS p)
{
    int id = maps[p.y][p.x];

    for (int dir = 0; dir < 4; dir++)
    {
        int ny = p.y, nx = p.x;
        int len = 0;
        int dest = 0;

        while (1)
        {
            ny += dy[dir], nx += dx[dir];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || maps[ny][nx] != 0)
                break;
            len++;
        }

        if (ny >= 0 && ny < n && nx >= 0 && nx < m)
        {
            dest = maps[ny][nx];
        }

        if (len >= 2 && dest)
        {
            BRIDGE t;
            t.src = id, t.dest = dest, t.len = len;
            bridge.push_back(t);
        }
    }
}

int find(int p)
{
    while (parent[p] != p)
    {
        p = parent[p];
    }
    return p;
}
int main(void)
{
    int island_cnt = 1;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maps[i][j];
            if (maps[i][j])
                maps[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maps[i][j] == -1)
            {
                parent[island_cnt] = island_cnt;
                make_island(i, j, island_cnt);
                island_cnt++;
            }
        }
    }

    for (int i = 1; i < island_cnt; i++)
    {
        for (int j = 0; j < islandEdge[i].size(); j++)
        {
            make_bridge(islandEdge[i][j]);
        }
    }

    sort(bridge.begin(), bridge.end());

    int ans = 0;
    for (int i = 0; i < bridge.size(); i++)
    {
        if (find(bridge[i].src) != find(bridge[i].dest))
        {
            ans += bridge[i].len;
            parent[find(bridge[i].src)] = find(bridge[i].dest);
        }
    }

    int start = find(1);
    for (int i = 2; i < island_cnt; i++)
    {
        if (start != find(i))
        {
            ans = -1;
        }
    }
    cout << ans << '\n';
    return 0;
}