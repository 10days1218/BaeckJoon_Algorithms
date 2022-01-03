#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

int n;
map<string, int> m;
int main()
{
    cin >> n;
    string str;
    string card;
    cin.ignore(256, '\n');
    getline(cin, str);
    stringstream sst(str);
    int cnt = 0;
    bool check = true;
    int count = 0;
    int total = 0;

    while (sst >> card)
    {
        if (m.find(card) == m.end())
        {
            m.insert({card, 1});
        }
        else
        {
            m.find(card)->second++;
        }
    }

    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        total += it->second;
        if (cnt == 0)
        {
            cnt = it->second;
            continue;
        }
        if (cnt == it->second)
            continue;
        if (cnt - 1 == it->second)
        {
            count++;
        }
        else
        {
            check = false;
        }
    }

    if (check && count <= 1)
    {
        cout << "Y" << '\n';
        total = count == 1 ? total + 1 : total;
        cout << total << '\n';
        cout << m.size() << '\n';
    }

    else
    {
        cout << "N" << '\n';
        cout << total << '\n';
        cout << m.size() << '\n';
    }

    return 0;
}