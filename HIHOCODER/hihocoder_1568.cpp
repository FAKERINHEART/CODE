#include <iostream>

int dp[605][305][305];//到i位置为止, 一共有j个左括号, bad为l

int main()
{
    int n, k;
    std::cin >> n >> k;

    dp[0][0][0] = 1;

    for (int i = 0; i <= 2 * n; ++i)
    {
        for (int j = 0; j <= std::min(n, i); ++j)
        {
            for (int l = 0; l <= j; ++l)
            {
                //i+1位置上如果是多了一个左括号, 那么bad+1
                dp[i + 1][j + 1][l + 1] += dp[i][j][l];
                dp[i + 1][j + 1][l + 1] %= 1000000007;

                //i+1为止上如果是多了一个右括号, 那么bad-1
                dp[i + 1][j][std::max(l - 1, 0)] += dp[i][j][l];
                dp[i + 1][j][std::max(l - 1, 0)] %= 1000000007;

                //std::cout << i << ", " << j << ", " << l << ": " << dp[i][j][l] << std::endl;
            }
        }
    }

    std::cout << dp[2 *n][n][k] << std::endl;

    return 0;
}
