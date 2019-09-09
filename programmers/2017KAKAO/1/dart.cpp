#include <string>
using namespace std;

int solution(string dartResult)
{
    int list[3] = {0};
    int count = 0;
    int answer = 0;

    int len = dartResult.length();

    for (int i = 0; i < len; i++)
    {
        if (dartResult.at(i) >= '0' && dartResult.at(i) <= '9')
        {
            if (i > 0 && dartResult.at(i - 1) >= '0' && dartResult.at(i - 1) <= '9')
            {
                int tmp = (int)dartResult.at(i) - '0';
                list[count - 1] = list[count - 1] * 10 + tmp;
            }
            else
            {
                list[count] = (int)dartResult.at(i) - '0';
                count++;
            }
        }

        if (dartResult.at(i) == 'S')
            ;

        if (dartResult.at(i) == 'D')
        {
            int index = count - 1;
            list[index] *= list[index];
        }

        if (dartResult.at(i) == 'T')
        {
            int index = count - 1;
            list[index] *= list[index] * list[index];
        }

        if (dartResult.at(i) == '*')
        {
            int index = count - 1;
            if (index == 0)
                list[index] *= 2;
            else
            {
                for (int j = index - 1; j <= index; j++)
                    list[j] *= 2;
            }
        }
        if (dartResult.at(i) == '#')
        {
            int index = count - 1;
            list[index] *= -1;
        }
    }

    for (int i = 0; i < count; i++)
        answer += list[i];

    return answer;
}