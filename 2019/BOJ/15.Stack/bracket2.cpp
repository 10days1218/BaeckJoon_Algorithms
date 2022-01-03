//#4949
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    stack<string> s;
    vector<string> str;
    string tmp;
    //int i = 0;

    while (1)
    {
        string tmp;
        getline(cin, tmp, '\n');
        if (tmp.at(0) == '.')
            break;
        str.push_back(tmp);
    }

    for (int i = 0; i < str.size(); i++)
    {
        int len = str[i].length();
        for (int j = 0; j < len; j++)
        {
            if (str[i].at(j) == '(')
                s.push("(");

            if (str[i].at(j) == '[')
                s.push("[");

            if (str[i].at(j) == ')')
            {
                if (s.empty() || s.top() == "[")
                {
                    cout << "no" << '\n';
                    j = len - 1;
                    continue;
                }

                if (s.top() == "(")
                    s.pop();
            }

            if (str[i].at(j) == ']')
            {

                if (s.empty() || s.top() == "(")
                {
                    cout << "no" << '\n';
                    j = len - 1;
                    continue;
                }

                if (s.top() == "[")
                    s.pop();
            }

            if (j == len - 1 && s.empty() == false)
                cout << "no" << '\n';
            if (j == len - 1 && s.empty())
                cout << "yes" << '\n';
        }
        while (!s.empty())
            s.pop();
    }
    return 0;
}