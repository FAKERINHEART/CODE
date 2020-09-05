#include <iostream>
#include <cstring>

int digit_num, current_second, ans_second;
bool digit_visited[10];
int digit[10], digit_now[10], digit_result[10];

void getDig(const int &x)
{
    if (digit_visited[x / 10] == false)
    {
        digit_visited[x / 10] = true;
        digit[digit_num++] = x / 10;
    }

    if (digit_visited[x % 10] == false)
    {
        digit_visited[x % 10] = true;
        digit[digit_num++] = x % 10;
    }

    return;
}

bool isValid(int &temp)
{
    int h = digit_now[0] * 10 + digit_now[1];
    int m = digit_now[2] * 10 + digit_now[3];
    int s = digit_now[4] * 10 + digit_now[5];
    temp  = h * 3600 + m * 60 + s;

    return h < 24 && m < 60 && s < 60;
}

void dfs(const int &pos)
{
    if (pos == 6)
    {
        int temp;

        if (isValid(temp) == false)
        {
            return;
        }

        temp -= current_second;

        if (temp <= 0)
        {
            temp = 24 * 3600 + temp;
        }

        if (temp < ans_second)
        {
            ans_second = temp;

            for (int i = 0; i < 6; ++i)
            {
                digit_result[i] = digit_now[i];
            }
        }

        return;
    }

    for (int i = 0; i < digit_num; ++i)
    {
        digit_now[pos] = digit[i];
        dfs(pos + 1);
    }

    return;
}

int main()
{
    int T;
    std::cin >> T;

    while (T--)
    {
        int HH, MM, SS;
        scanf("%d:%d:%d", &HH, &MM, &SS);

        digit_num = 0;
        memset(digit_visited, false, sizeof(digit_visited));

        getDig(HH);
        getDig(MM);
        getDig(SS);

        current_second = HH * 3600 + MM * 60 + SS;
        ans_second = 100000;

        dfs(0);

        for (int i = 0; i < 6; ++i)
        {
            std::cout << digit_result[i];

            if (i == 1 || i == 3)
            {
                std::cout << ":";
            }
        }

        std::cout << std::endl;
    }

    return 0;
}
