#include <iostream>
#include <vector>
using namespace std;

int pow(int k);
int main(int argc, char **argv)
{
    int test_case;
    int T;

    //freopen("sample_input.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int k, answer = 0;
        cin >> k;
        int tc = pow(k);
        vector<int> v, res;
        for (int i = 0; i < tc; i++)
        {
            int number;
            cin >> number;
            v.push_back(number);
        }

        for (int i = tc; i > 1; i /= 2)
        {
            for (int j = 0; j < i; j += 2)
            {
                if (v[j] > v[j + 1])
                    res.push_back(v[j]);
                else
                    res.push_back(v[j + 1]);

                answer += abs(v[j] - v[j + 1]);
            }
            v = res;
            res.clear();
        }
        cout << "#" << test_case << " " << answer << '\n';
    }
    return 0;
}

int pow(int k)
{
    int answer = 1;
    for (int i = 0; i < k; i++)
        answer *= 2;

    return answer;
}