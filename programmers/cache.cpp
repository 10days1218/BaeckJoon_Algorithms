// #include <string>
// #include <vector>
// #include <queue>
#include <bits/stdc++.h>
using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    vector<string> cache(cacheSize);
    vector<int> seq(cacheSize);
    int len = cities.size();
    bool check = true;

    for (int i = 0; i < len; i++)
    {
        std::transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);
    }

    for (int i = 0; i < len; i++)
    {
        check = true;

        if (cacheSize == 0)
        {
            answer = 5 * len;
            break;
        }
        if (i < cacheSize)
        {
            cache[i] = cities[i];
            answer += 5;
            seq[i] = i;
        }

        else
        {
            for (int j = 0; j < cacheSize; j++)
            {
                if (cache[j] == cities[i])
                {
                    int tmp = j;
                    for (int k = 0; k < cacheSize; k++)
                    {
                        if (seq[k] == j)
                        {
                            for (int l = k; l < cacheSize - 1; l++)
                            {
                                seq[k] = seq[k + 1];
                            }
                            seq[cacheSize - 1] = tmp;
                            //continue;
                        }
                    }
                    answer += 1;
                    j = cacheSize + 1;
                    check = false;
                }
            }

            if (check == true)
            {
                int idx = seq[0];
                cache[idx] = cities[i];
                for (int j = 0; j < cacheSize - 1; j++)
                {
                    seq[j] = seq[j + 1];
                }
                seq[cacheSize - 1] = idx;
                answer += 5;
            }
        }
    }

    return answer;
}
int main(void)
{
    int n = 0;
    vector<string> cities = //{"Jeju", "Pangyo", "NewYork", "NewYork"};
        //{"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"};
        //{"Jeju","Pangyo","Seoul","NewYork","LA","Jeju","Pangyo","Seoul","NewYork","LA"};
        {"Jeju", "Pangyo", "Seoul", "NewYork", "LA"};

    cout << solution(n, cities) << '\n';
}