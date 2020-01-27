#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    // freopen("sample_input.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int number = 0, minValue = 987654321, maxValue = -12345678;
        for (int i = 0; i < 10; i++)
        {
            cin >> number;
            int sum = 0;
            while (number != 0)
            {
                sum += number % 10;
                number /= 10;
            }

            if (minValue > sum)
                minValue = sum;
            if (maxValue < sum)
                maxValue = sum;
        }

        cout << '#' << test_case << " " << maxValue << " " << minValue << "\n";
    }
    return 0;
}