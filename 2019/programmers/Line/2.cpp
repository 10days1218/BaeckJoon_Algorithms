#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    string str;
    int k, tmp;
    getline(cin, str);
    cin >> k;

    stringstream ss(str);
    vector<int> v;
    vector<int> answer;
    while (ss >> tmp)
    {
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());
    do
    {
        string temp;
        for (int i = 0; i < v.size(); i++)
        {
            temp += to_string(v[i]);
        }
        int p = atoi(temp.c_str());
        answer.push_back(p);
    } while (next_permutation(v.begin(), v.end()));

    sort(answer.begin(), answer.end());
    cout << answer[k - 1] << '\n';

    return 0;
}