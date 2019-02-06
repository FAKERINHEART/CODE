#include <iostream>
#include <cstring>

long long dp[100005][3][2];

int main()
{
    int N;

    std::cin >> N;

    if (N == 0)
    {
        return 1;
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                dp[i + 1][0][k] = (dp[i + 1][0][k] + dp[i][j][k]) % 1000000007;//末尾加O, 则末尾连续L为0

                if (j < 2)
                {
                    dp[i + 1][j + 1][k] = (dp[i + 1][j + 1][k] + dp[i][j][k]) % 1000000007;
                }

                if (k < 1)
                {
                    dp[i + 1][0][k + 1] = (dp[i + 1][0][k + 1] + dp[i][j][k]) % 1000000007;//末尾加A, 则末尾连续L为0
                }
            }
        }
    }

    long long result = 0;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result = (result + dp[N][i][j]) % 1000000007;
        }
    }

    std::cout << result << std::endl;

    return 0;
}

