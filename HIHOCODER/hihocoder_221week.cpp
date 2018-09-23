#include <iostream>
#include <cstring>

long long dp[1001][1001];

int main()
{
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    int N;
    std::cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            dp[i][j] = (j * dp[i - 1][j] % 1000000007 + j * dp[i - 1][j-1] % 1000000007);
        }
    }

    int ans = 0;

    for (int i = 1; i <= N; ++i)
    {
        ans = (ans + dp[N][i]) % 1000000007;
    }

    std::cout << ans << std::endl;

    return 0;
}

