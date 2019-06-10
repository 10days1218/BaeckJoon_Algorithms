//#1874
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void)
{
    int t_case = 0;
    vector<int> v;
    stack<int> s;
    cin >> t_case;
    int cnt = 1;

    for (int i = 0; i < t_case; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int i = 0; i < t_case; i++)
    {
        if (s.empty() || s.top() != v[i])
        {
            while (1)
            {
                if (cnt > t_case)
                {
                    cout << "NO" << endl;
                    return 0;
                }
                s.push(cnt++);
                cout << "+" << endl;
                if (s.top() == v[i])
                {
                    s.pop();
                    cout << "-" << endl;
                    break;
                }
            }
        }
        if (s.top() == v[i])
        {
            s.pop();
            cout << "-" << endl;
        }
    }
    return 0;
}