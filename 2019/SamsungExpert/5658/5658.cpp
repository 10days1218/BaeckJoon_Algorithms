//#5658
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <functional>
using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    int n, k;
    vector<int> v;
    string pw;
    //freopen("input.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n >> k;
        cin >> pw;

        for (int i = 0; i < n / 4; i++)
        {
            for (int i = 0; i < n; i += n / 4)
            {
                string num;
                int nHex;
                num = pw.substr(i, n / 4);
                stringstream convert(num);
                convert >> hex >> nHex;
                vector<int>::iterator iter;
                iter = find(v.begin(), v.end(), nHex);
                if (iter == v.end())
                {
                    v.push_back(nHex);
                }
            }
            string tmp = pw.substr(n - 1, 1);
            string t_str = tmp;
            t_str += pw.substr(0, n - 1);
            pw = t_str;
        }
        sort(v.begin(), v.end(), greater<int>());
        cout << '#' << test_case << ' ' << v[k - 1] << '\n';
        v.clear();
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}