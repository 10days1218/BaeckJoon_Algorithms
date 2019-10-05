#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int n;
string play;
vector<int> v;
int main()
{
    string str;
    cin >> n;
    v.assign(n);
    vector<vector<int>> follower(n);
    cin.ignore(256, '\n');
    getline(cin, play);
    stringstream sst(play);
    bool check = false;

    while (sst >> str)
    {
        if (str == "A")
        {
        }
        if (str == "J")
        {
        }
        if (str == "Q")
        {
        }
        if (str == "K")
        {
        }
    }

    return 0;
}