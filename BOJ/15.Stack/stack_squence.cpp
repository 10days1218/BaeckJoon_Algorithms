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
    vector<char> str;
    cin >> t_case;
    int idx = 0;

    for (int i = 0; i < t_case; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int i = 1; i <= t_case; i++)
    {
        s.push(i);
        str.push_back('+');
        while (!s.empty() && s.top() == v[idx])
        {
            idx++;
            s.pop();
            str.push_back('-');
        }
    }

    if (!s.empty())
    {
        cout << "NO\n";
        return 0;
    }
    else
    {
        for (vector<int>::size_type i = 0; i < str.size(); ++i)
        {
            cout << str[i];
            cout << "\n";
        }
    }

    return 0;
}