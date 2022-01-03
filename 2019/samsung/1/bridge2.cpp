#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
int N, M;
int field[11][11];

#define NOT_FOUND -1
#define WATER 0
//섬은 1~6의 숫자 값을 갖는다.
struct Pos
{
    int x, y;
};
struct Bridge
{
    int src, dest, len;
    bool operator<(const struct Bridge &rhs) const
    {
        return len < rhs.len;
    }
};
bool isin(Pos p)
{
    return p.x >= 0 && p.y >= 0 && p.x < N && p.y < M;
}
struct Island
{
    vector<Pos> edge; //물과 맞닿아있는 지점 좌표(다리 지을 수 있는지 체크용)
};
vector<Bridge> bridges;
Island islands[7];
const Pos d[4] = {{0, +1}, {+1, 0}, {-1, 0}, {0, -1}};

void find_island(Pos pos, int id) //섬들에 번호를 붙여주는 함수
{
    field[pos.x][pos.y] = id;
    int water = 0;
    for (int k = 0; k < 4; k++)
    {
        Pos nx = {pos.x + d[k].x, pos.y + d[k].y};
        if (isin(nx))
        {
            if (field[nx.x][nx.y] == NOT_FOUND)
            {
                find_island(nx, id);
            }
            else if (field[nx.x][nx.y] == WATER)
            {
                water++;
            }
        }
    }
    if (water)
    {
        islands[id].edge.push_back(pos); //물과 맞닿아있는 지점 좌표
    }
}
void try_bridge(const Pos pos)
{
    const int id = field[pos.x][pos.y];
    for (int k = 0; k < 4; k++)
    {
        Pos p = {pos.x + d[k].x, pos.y + d[k].y};
        int len = 0;
        int dest = 0;
        while (isin(p) && field[p.x][p.y] == 0)
        {
            p.x += d[k].x;
            p.y += d[k].y;
            len++;
        }
        if (isin(p))
        {
            dest = field[p.x][p.y];
        }
        if (len >= 2 && dest)
        {
            bridges.push_back({id, dest, len});
        }
    }
}
int dsu[7];
int dsu_find(int p)
{
    while (dsu[p] != p)
    {
        p = dsu[p];
    }
    return p;
}
int main()
{
    int island_cnt = 1;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> field[i][j];
            if (field[i][j])      //field [i][j] == 1
                field[i][j] = -1; //<-- ?
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (field[i][j] == NOT_FOUND) //섬에 번호 붙여주기
            {
                dsu[island_cnt] = island_cnt;
                find_island({i, j}, island_cnt++); //섬의 개수
            }
        }
    }
    for (int i = 1; i < island_cnt; i++)
    {
        for (Pos p : islands[i].edge)
        {
            try_bridge(p);
        }
    }

    // 최소 스패닝 트리 만들기
    sort(bridges.begin(), bridges.end());
    int total_len = 0;
    for (auto b : bridges)
    {

        if (dsu_find(b.src) != dsu_find(b.dest))
        {
            total_len += b.len;
            // Disjoint Set Merge
            dsu[dsu_find(b.src)] = dsu_find(b.dest); //연결
        }
    }

    // 최소 스패닝 트리에 모든 섬이 포함되었는지 확인
    int dsu_first = dsu_find(1);
    for (int i = 2; i < island_cnt; i++)
    {
        if (dsu_first != dsu_find(i))
        {
            total_len = -1;
        }
    }
    cout << total_len << endl;
    return 0;
}
