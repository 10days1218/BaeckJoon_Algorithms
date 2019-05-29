//#2504
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int innerLoop(stack<string> *stack, string s1, string s2, int value);
int main(void)
{
    stack<string> stack;
    string str;
    int answer = 0;

    getline(cin, str, '\n');
    int len = str.length();

    for (int i = 0; i < len; i++)
    {
        if (answer == -1)
        {
            cout << 0 << endl;
            return 0;
        }

        if (str.at(i) == '(')
        {
            stack.push("(");
        }

        if (str.at(i) == '[')
        {
            stack.push("[");
        }

        if (str.at(i) == ')')
        {
            if (!stack.empty() && stack.top() == "(")
            {
                stack.pop();
                stack.push("2");
            }
            else
            {
                answer = innerLoop(&stack, "(", "[", 2);
            }
        }

        if (str.at(i) == ']')
        {
            if (!stack.empty() && stack.top() == "[")
            {
                stack.pop();
                stack.push("3");
            }
            else
            {
                answer = innerLoop(&stack, "[", "(", 3);
            }
        }
    }

    answer = 0;

    while (!stack.empty())
    {
        if (stack.top() == "(" || stack.top() == "[")
        {
            cout << 0 << endl;
            return 0;
        }
        else
        {
            answer += atoi(stack.top().c_str());
            stack.pop();
        }
    }

    cout << answer << endl;

    return 0;
}

int innerLoop(stack<string> *stack, string s1, string s2, int value)
{
    int total = -1;

    while (!stack->empty())
    {
        string c_top = stack->top();
        if (c_top == s1)
        {
            stack->pop();
            total *= value;
            stack->push(to_string(total));
            break;
        }
        if (c_top == s2)
        {
            return -1;
        }
        else
        {
            if (total == -1)
                total = 0;
            total += atoi(c_top.c_str());
            stack->pop();
        }
    }
    return total;
}