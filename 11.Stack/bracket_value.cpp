//#2504
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    stack<string> stack;
    string str;

    getline(cin, str, '\n');
    int len = str.length();

    for (int i = 0; i < len; i++)
    {
        if (str.at(i) == "(" || str.at(i) == "[")
            stack.push(str.at(i));

        if (str.at(i) == ")")
        {
            if (stack.top() == "(")
            {
                stack.pop();
                stack.push("2");
            }
            else
            {
                if ()
            }
        }

        if (str.at(i) == "]")
        {
            if (stack.top() == "[")
            {
                stack.pop();
                stack.push("3");
            }
        }
    }

    return 0;
}