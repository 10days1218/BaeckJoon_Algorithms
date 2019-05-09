/*
#2292 
*/
#include <iostream>

// 2 +   6(1*6) -1 = 7  2번
// 8 +  12(2*6) -1 = 19 3번
// 20 + 18(3*6) -1 = 37 4번
// 38 + 24(4*6) -1 = 61 5번
int cal(int num);

int main(void){
    int num = 0;
    int total = 0
    cin>>num;

    if( num == 1){
        cout<<'1';
        return;
    }

    else{
        total = cal(num);
        cout<<total;
        return 0;
    }


    return 0;

}

int cal(int num){

}
