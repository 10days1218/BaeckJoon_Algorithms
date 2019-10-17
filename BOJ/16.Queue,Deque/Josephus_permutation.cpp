//#11866
#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    int N, M;
    queue<int> q;
    cin >> N >> M;
    int index = 0;
    int count = 0;

    for (int i = 1; i <= N; i++)
        q.push(i);

    cout << "<";

    while (!q.empty())
    {
        for (int i = 0; i < M - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();
        if (!q.empty())
            cout << ", ";
    }

    cout << ">" << endl;
    return 0;
}