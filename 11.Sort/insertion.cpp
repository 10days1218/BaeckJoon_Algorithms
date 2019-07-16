//#2750
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int num, key, i, j = 0;
    vector<int> v;
    cin >> num;
    v.resize(num);

    for (int i = 0; i < num; i++)
    {
        cin >> v[i];
    }

    for (i = 1; i < num; i++)
    {
        key = v[(j = i)];
        while (--j >= 0 && key < v[j])
        {
            v[j + 1] = v[j];
            v[j] = key;
        }
    }

    for (int i = 0; i < num; i++)
        cout << v[i] << " ";
    cout << '\n';

    return 0;
}