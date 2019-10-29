#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool check(string bracket)
{
    int len = bracket.size();
    stack<char> s;

    for (int i = 0; i < len; i++)
    {
        if (bracket[i] == '(')
            s.push('(');

        else
        {
            if (s.size() != 0)
                s.pop();

            else
                return false;
        }
    }
    return s.empty();
}

string sperate(string p)
{
    string u, v;

    if (p == "")
        return p;

    int len = p.size();

    for (int i = 0; i < len; i++)
    {
        u += p[i];
        if (u.size() != 0 && count(u.begin(), u.end(), '(') == count(u.begin(), u.end(), ')'))
        {
            v = p.substr(i + 1);
            break;
        }
    }

    if (check(u))
    {
        string tmp = sperate(v);
        if (tmp == "")
            return u;
        else
            return u + tmp;
    }

    else
    {
        string result = "(";
        v = sperate(v);
        result = result + v + ")";
        for (int i = 1; i < u.size() - 1; i++)
        {
            if (u[i] == '(')
                result += ")";

            else
                result += "(";
        }
        return result;
    }
}

string solution(string p)
{
    string answer = "";
    if (check(p))
        answer = p;
    else
    {
        answer = sperate(p);
    }
    return answer;
}

// int main(void)
// {
//     string str = "()))((()";
//     cout << solution(str) << '\n';
// }