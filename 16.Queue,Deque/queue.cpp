//#10845
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    int num;
    vector<int> Queue;
    string *command;
    int front = -1;
    int back = -1;

    cin >> num;
    cin.ignore();
    command = new string[num];

    for (int i = 0; i < num; i++)
    {
        getline(cin, command[i], '\n');
    }

    for (int i = 0; i < num; i++)
    {
        if (command[i].substr(0, 4) == "push")
        {
            int value = atoi(command[i].substr(5).c_str());
            Queue.push_back(value);
            if (front == -1)
                front = 0;
            back++;
        }

        if (command[i].substr(0, 3) == "pop")
        {
            if (back == -1)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << Queue[front] << endl;
                Queue.erase(Queue.begin());
                if (back == 0)
                {
                    front = -1;
                    back = -1;
                }
                else
                    back--;
            }
        }
        if (command[i].substr(0, 4) == "size")
        {
            cout << back + 1 << endl;
        }

        if (command[i].substr(0, 5) == "empty")
        {
            if (back == -1)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        if (command[i].substr(0, 5) == "front")
        {
            if (front == -1)
                cout << -1 << endl;
            else
                cout << Queue[front] << endl;
        }

        if (command[i].substr(0, 4) == "back")
        {
            if (back == -1)
                cout << -1 << endl;
            else
                cout << Queue[back] << endl;
        }
    }
    return 0;
}