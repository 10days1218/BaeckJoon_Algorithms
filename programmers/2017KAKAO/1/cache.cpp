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
        vector<string>::iterator iter = find(cache.begin(), cache.end(), cities[i]);

        if(iter != ca)
    }
    return answer;
}
int main(void)
{
    int n = 5;
    vector<string> cities = //{"Jeju", "Pangyo", "NewYork", "NewYork"};
        //{"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"};
        //{"Jeju","Pangyo","Seoul","NewYork","LA","Jeju","Pangyo","Seoul","NewYork","LA"};
        //{"Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
        {"Jeju", "Jeju", "Jeju"};
    cout << solution(n, cities) << '\n';
}