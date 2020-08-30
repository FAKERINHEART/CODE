#include <iostream>
#include <cstring>
#include <string>

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::string A, B;
    std::cin >> A >> B;

    int next[B.length() + 10];

    A += '#';

    for (int i = 0; i < m; ++i)
    {
        B[i] = '1' - B[i] + '0';
    }

    int i = 0, j = -1;
    next[0] = -1;

    while (i < (int)B.length())
    {
        if (j == -1 || B[j] == B[i])
        {
            j++;
            i++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }

    long long res = 0;
    i             = 0;
    j             = 0;

    while (i < (int)A.length())
    {
        if (j == -1 || B[j] == A[i])
        {
            i++;
            j++;

            if (j >= (int)B.length())
            {
                res += (long long)(j + 1) * j / 2 + (long long)(n - i) * j;
                j = next[j];
            }
        }
        else
        {
            res += (long long)(j + 1) * j / 2 + (long long)(n - i) * j;
            j = next[j];
        }
    }

    long long k = (long long)(n + 1) * (long long)n / 2;
    printf("%.9lf\n", 1.0 * res / k);

    return 0;
}
