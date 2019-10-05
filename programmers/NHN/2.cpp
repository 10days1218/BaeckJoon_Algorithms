#include <bits/stdc++.h>
using namespace std;
// typedef pair<int, int> node;
const int MAX = 100 + 1;
int N;
int cnt[MAX];
// struct cmp
// {
//     bool operator()(node x, node y)
//     {
//         /*
//         if (cnt[x.second] > cnt[y.second])
//         {
//             return cnt[x.second] > cnt[y.second];
//         }
//         else if (cnt[x.second] == cnt[y.second])
//         {
//             return x.first > y.first;
//         }
//         else if (cnt[x.second] < cnt[y.second])
//         {
//             return cnt[x.second] < cnt[y.second];
//         }
//         */
//     }
// };
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> answer;
    vector<int> nq;
    vector<int> index;
    vector<int> find_index(101, -1);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string comm;
        cin >> comm;
        if (comm == "enqueue")
        {
            int x;
            cin >> x;
            cnt[x] += 1;
            nq.push_back(x);
        }
        else if (comm == "dequeue")
        {
            if (nq.empty())
            {
                answer.clear();
                cout << -1 << '\n';
                return 0;
            }
            else
            {
                int M = *max_element(cnt, cnt + 101);
                for (int j = 1; j < 101; i++)
                {
                    if (M == cnt[j])
                    {
                        index.push_back(j); // 빈도수 많은거 저장
                    }
                }

                if (index.size() == 1)
                {
                    answer.push_back(index[0]);
                    cnt[index[0]]--;
                    for (int j = 0; j < nq.size(); j++)
                    {
                        if (nq[j] == index[0])
                        {
                            nq.erase(nq.begin() + j);
                            index.clear();
                            break;
                        }
                    }
                }
                else if (index.size() > 1)
                {
                    for (int j = 0; j < index.size(); j++)
                    {
                        for (int k = 0; k < nq.size(); k++)
                        {
                            if (index[j] == nq[k] && find_index[index[j]] == -1)
                            {
                                find_index[index[j]] = k;
                            }
                        }
                    }
                    int minIndex = *min_element(find_index.begin(), find_index.end());
                    answer.push_back(nq[minIndex]);
                    nq.erase(nq.begin() + minIndex);
                    find_index.assign(101, -1);
                }
            }
        }
    }

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }
    cout << '\n';
    return 0;
}