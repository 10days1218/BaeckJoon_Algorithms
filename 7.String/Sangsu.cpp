#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    string str1, str2;
    int num1, num2, max_num;

    cin >> str1 >> str2;

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    num1 = atoi(str1.c_str());
    num2 = atoi(str2.c_str());
    max_num = max(num1, num2);

    cout << max_num << endl;

    return 0;
}