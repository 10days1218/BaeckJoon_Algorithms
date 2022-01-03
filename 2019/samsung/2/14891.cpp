//#14891
#include<bits/stdc++.h>
using namespace std;

struct CMD{
    int n;
    int dir;
};
string input[4];
int gear[4][8];
int k;
CMD cmd[100];

void rotate(int n, int dir){
    if(dir == 1){
        int tmp = gear[n][7];
        for(int i = 7; i -1 >= 0; i--){
            gear[n][i] = gear[n][i -1];
        }
        gear[n][0] = tmp;
    }
    else if(dir == -1){
        int tmp = gear[n][0];
        for(int i = 0; i <= 6; i++){
            gear[n][i] = gear[n][i+1];
        }
        gear[n][7] = tmp; 
    }
}

int main(void){

    for(int i = 0; i < 4; i++){
        cin  >> input[i];
        for(int j = 0; j < 8; j++){
            gear[i][j] = input[i][j] - '0';
        }
    }

    cin >> k;

    for(int i = 0; i < k; i++){
        cin >> cmd[i].n >> cmd[i].dir;
        cmd[i].n--;
    }
    
    for(int i = 0; i < k; i++){
        bool check[] = {false,false,false,false};
        CMD t;
        queue<CMD> q;
        q.push(cmd[i]);
        check[cmd[i].n] = true;

        while (!q.empty())
        {
            t = q.front();
            q.pop();
            int cur = t.n, cur_r = t.dir;
            int left = cur - 1, right = cur + 1;

            if(left >= 0 && left <= 3 && gear[left][2] != gear[cur][6] && !check[left]){
                    t.n = left, t.dir = cur_r  * (-1);
                    q.push(t);
                    check[left] = true;
            }

            if(right >= 0 && right <= 3 && gear[cur][2] != gear[right][6] && !check[right]){
                t.n = right, t.dir = cur_r * (-1);
                q.push(t);
                check[right] = true;
            }
            rotate(cur, cur_r);
        }
    }

    cout << gear[0][0]  + gear[1][0] * 2 + gear[2][0] * 4 + gear[3][0] * 8 << '\n';
    return 0;
}