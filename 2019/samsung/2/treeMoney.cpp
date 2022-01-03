//#16235
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int maps[11][11];
int add[11][11];
const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
struct TREE
{
    int y;
    int x;
    int age;
};

queue<TREE> new_tree;
queue<TREE> trees;

int main(void)
{
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> add[i][j];
            maps[i][j] = 5;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int r, c, a;
        TREE tree;
        cin >> tree.y >> tree.x >> tree.age;
        trees.push(tree);
    }

    while (k--)
    {
        queue<TREE> dead,five,total;

        while(!new_tree.empty()){
            TREE t = new_tree.front();
            new_tree.pop();
            int r = t.y, c = t.x  ;
            if(maps[r][c] >= t.age){
                maps[r][c] -= t.age;
                t.age++;
                total.push(t);
            }
            else{
                dead.push(t);
            }
        }

        int cnt = trees.size();
        while(!trees.empty()){
            TREE t = trees.front();
            trees.pop();
            int r = t.y, c = t.x  ;
            if(maps[r][c] >= t.age){
                maps[r][c] -= t.age;
                t.age++;
                total.push(t);
                if(t.age % 5 == 0){
                    five.push(t);
                }
            }
            else{
                dead.push(t);
            }
        }
        
        while(!dead.empty()){
            TREE t  = dead.front();
            dead.pop();
            int r = t.y, c = t.x, a = t.age;
            maps[r][c] += a / 2;
        }

        while(!five.empty()){
            TREE t = five.front();
            five.pop();
            for(int dir = 0; dir < 8; dir++){
                int ny = t.y + dy[dir], nx = t.x + dx[dir];
                if(ny <= 0 || ny > n || nx <= 0 || nx > n)
                    continue;
                TREE n;
                n.y = ny, n.x = nx, n.age = 1;
                new_tree.push(n);
            }
        }

        for(int r = 1; r <= n; r++){
            for(int c = 1; c <= n; c++){
                maps[r][c] += add[r][c];
            }
        }
        trees = total;
    }

    cout << new_tree.size() + trees.size() << '\n';

    return 0;
}