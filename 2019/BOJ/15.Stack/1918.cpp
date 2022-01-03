//https://www.acmicpc.net/problem/1918
#include <bits/stdc++.h>
using namespace std;

int getPriority(char oper);
int main(void)
{
    string expression;
    string answer;
    stack<char> stack;
    cin >> expression;

    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '(' || expression[i] == ')')
        {
            if (stack.size() == 0)
                stack.push(expression[i]);

            else
            {
                if (expression[i] == '(')
                    stack.push(expression[i]);

                else if (expression[i] == ')')
                {
                    while (!stack.empty() && stack.top() != '(')
                    {
                        answer += stack.top();
                        stack.pop();
                    }
                    stack.pop();
                }

                else
                {
                    while (!stack.empty() && getPriority(stack.top()) >= getPriority(expression[i]))
                    {
                        answer += stack.top();
                        stack.pop();
                    }
                    stack.push(expression[i]);
                }
            }
        }

        else
            answer += expression[i];
    }

    while (!stack.empty())
    {
        answer += stack.top();
        stack.pop();
    }

    cout << answer << '\n';

    return 0;
}

int getPriority(char oper)
{
    if (oper == '+' || oper == '-')
        return 1;

    else if (oper == '*' || oper == '/')
        return 2;

    else if (oper == '(' || oper == ')')
        return 0;

    return -1;
}