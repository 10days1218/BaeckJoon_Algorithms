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
        check = true;
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

            if (check = true)
            {
                int idx = seq[0];
                cache[idx] = cities[i];
                for (int j = 0; j < cacheSize - 1; j++)
                {
                    seq[j] = seq[j + 1];
                }
                seq[cacheSize - 1] = idx;
                answer += 5;
                //check = false;
            }
        }

        // for (int t = 0; t < cacheSize; t++)
        //     cout << cache[t] << " ";

        // for (int t = 0; t < cacheSize; t++)
        //     cout << seq[t] << " ";
        // cout << '\n';
    }

    return answer;
}
int main(void)
{
    int n = 2;
    vector<string> cities = {"Jeju", "Pangyo", "NewYork", "NewYork1"};
    //{"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"};
    //{"Jeju","Pangyo","Seoul","NewYork","LA","Jeju","Pangyo","Seoul","NewYork","LA"};

    cout << solution(n, cities) << '\n';
}

/*
[Jeju, Pangyo, Seoul, NewYork, LA, Jeju, Pangyo, Seoul, NewYork, LA]	
3	[Jeju, Pangyo, Seoul, Jeju, Pangyo, Seoul, Jeju, Pangyo, Seoul]	
2	[Jeju, Pangyo, Seoul, NewYork, LA, SanFrancisco, Seoul, Rome, Paris, Jeju, NewYork, Rome]	60
5	[Jeju, Pangyo, Seoul, NewYork, LA, SanFrancisco, Seoul, Rome, Paris, Jeju, NewYork, Rome]	52
2	[Jeju, Pangyo, NewYork, newyork]	16
0	[Jeju, Pangyo, Seoul, NewYork, LA] */
