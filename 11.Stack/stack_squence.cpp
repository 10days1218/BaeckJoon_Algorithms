//#1874
#include <iotream>
#include <stack>
#include <vector>
using namespace std;

int main(void)
{
    int t_case = 0;
    vector<int> v;
    vector<int> v_sequece;
    stack<int> s;
    cin >> t_case;

    for (int i = 0; i < t_case; i++)
    {
        int tmp;
        cin >> tmp;
        v.push(tmp);
        v.push(i + 1);
    }

    for (int i = 0; i < t_case; i++)
    {
        if (i + 1 != v(i))
        {
            s.push(i + 1);
            cout << "-" << endl;
        }
        else
        {
            ;
        }
    }

    return 0;
}