//#9012
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
    int num = 0;
    cin >> num;
    cin.ignore();
    stack<string> stack;
    string *str = new string[num];

    for (int i = 0; i < num; i++)
        getline(cin, str[i], '\n');

    for (int i = 0; i < num; i++)
    {
        int len = str[i].length();

        while (!stack.empty())
            stack.pop();

        for (int j = 0; j < len; j++)
        {
            if (str[i].at(j) == '(')
                stack.push("(");

            if (str[i].at(j) == ')')
            {
                if (stack.empty())
                {
                    cout << "NO" << endl;
                    j = len - 1;
                    continue;
                }
                else
                    stack.pop();
            }

            if (j == len - 1 && stack.empty() == false)
            {
                cout << "NO" << endl;
            }

            if (j == len - 1 && stack.empty())
                cout << "YES" << endl;
        }
    }
    return 0;
}