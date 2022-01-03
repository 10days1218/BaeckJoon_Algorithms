//#2990 트라이?
#include <bits/stdc++.h>
using namespace std;

vector<string> db;
vector<string> search_list;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        db.push_back(tmp);
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        string tmp;
        cin >> tmp;
        search_list.push_back(tmp);
    }

    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < db[j].size(); k++)
            {
                count++;
                if (search_list[i][k] != db[j][k])
                {
                    break;
                }
            }
            if (db[j] == search_list[i])
            {
                count++;
                break;
            }
        }
        cout << count << '\n';
        count = 0;
    }

    return 0;
}