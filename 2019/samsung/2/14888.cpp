//#14888
#include<bits/stdc++.h>
using namespace std;

int n;
int number[11];
int op[4];
int ret_max = INT_MIN, ret_min = INT_MAX;

void dfs(int ret,int count){
    if(count == n-1){
        if(ret > ret_max)
            ret_max = ret;
        if(ret < ret_min)
            ret_min = ret;
        return;
    }

    for(int i = 0; i < 4; i++){
        if(op[i] != 0){
            op[i]--;
            if(i == 0){
                dfs(ret + number[count + 1], count + 1);
            }
            else if(i == 1){
                dfs(ret - number[count + 1], count + 1);
            }
            else if(i == 2){
                dfs(ret * number[count + 1], count + 1);
            }
            else if(i == 3){
                dfs(ret / number[count + 1], count + 1);
            }
            op[i]++;
        }
    }
}
int main(void){
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> number[i];
    }

    for(int i = 0; i < 4; i++){
        cin >> op[i];
    }

    dfs(number[0], 0);

    cout << ret_max << '\n' << ret_min << '\n';

    return 0;
}