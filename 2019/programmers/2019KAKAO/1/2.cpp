#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

bool checkBracket(string str)
{
    stack<char> s;
    int len = (int)str.length();
    for (int i = 0; i < len; i++)
    {
        char c = str[i];
        if (c == '(')
            s.push(str[i]);

        else
        {
            if (!s.empty())
                s.pop();
            else
                return false;
        }
    }
    return s.empty();
}

string makeUV(string str)
{
    string u = "", v = "";
    int open = 0, close = 0;
    if (str == "")
        return str;

    for (int i = 0; i < str.size(); i++)
    {
        u += str[i];
        open = count(u.begin(), u.end(), '(');
        close = count(u.begin(), u.end(), ')');
        if (u.size() > 0 && open == close)
        {
            v = str.substr(i + 1);
            break;
        }
    }
    if (checkBracket(u))
    {
        string result = makeUV(v);
        if (result == "")
            return u;
        else
        {
            cout << u + result << '\n';
            return u + result;
        }
    }
    else
    {
        string result = "";
        v = makeUV(v);
        string tmp_u = str.substr(1, str.size() - 2);
        u = "";
        for (int i = 0; i < u.size() / 2; i++)
            u += "()";
        result = "(" + u + ")" + v;
        return result;
    }
}
string solution(string p)
{
    string answer = "";
    if (checkBracket(p))
        answer = p;
    else
    {
        makeUV(p);
    }
    return answer;
}

int main(void)
{
    string p = "()))((()";
    cout << solution(p) << '\n';
    return 0;
}