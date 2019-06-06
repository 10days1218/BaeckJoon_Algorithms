//#1966
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void)
{
    int num = 0;
    vector<int> N, M;
    cin >> num;
    N.resize(num);
    M.resize(num);
    queue<int> *q = new queue[num];

    for (int i = 0; i < num; i++)
    {
        cin >> N[i] >> M[i];
    }
    return 0;
}