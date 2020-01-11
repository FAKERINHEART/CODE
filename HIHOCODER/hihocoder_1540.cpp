#include <iostream>

int dp[100001][6][6][2];//dp[n][i][j][k], 对于前n个人, 当n-1处于i名, n处于j名, k为i是否小于j时的总信心值
int a[100001][6];

int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        int n;
        std::cin >> n;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                std::cin >> a[i][j];
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                for (int k = 0; k < 5; ++k)
                {
                    for (int v = 0; v < 2; ++v)
                    {
                        dp[i][j][k][v] = 1 << 30;
                    }
                }
            }            
        }

        dp[2][0][1][1] = a[1][0] + a[2][1];
        dp[2][1][0][0] = a[1][1] + a[2][0];

        int ans = 1 << 30;

        for (int i = 2; i < n; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                for (int k = 0; k < 5; ++k)
                {
                    int tmp1, tmp2;
                    tmp1 = a[i][k + 1] - a[i][k];
                    tmp2 = a[i - 1][j + 1] - a[i - 1][j];

                    for (int v = 0; v < 2; ++v)
                    {
                        if (dp[i][j][k][v] == 1 << 30)
                        {
                            continue;
                        }
                        //j, k < 2
                        dp[i + 1][k][2][1] = std::min(dp[i + 1][k][2][1], dp[i][j][k][v] + a[i + 1][2]);
                        //j, k > 0
                        dp[i + 1][k + 1][0][0] = std::min(dp[i + 1][k + 1][0][0], dp[i][j][k][v] + a[i + 1][0] + tmp1 + tmp2);

                        if (v == 0)
                        {
                            //k < 1 < j
                            dp[i + 1][k][1][1] = std::min(dp[i + 1][k][1][1], dp[i][j][k][v] + a[i + 1][1] + tmp2);
                        }
                        else
                        {
                            //j < 1 < k
                            dp[i + 1][k + 1][1][0] = std::min(dp[i + 1][k + 1][1][0], dp[i][j][k][v] + a[i + 1][1] + tmp1);
                        }
                    }
                }
            }
        }

        for (int j = 0; j < 5; ++j)
        {
            for (int k = 0; k < 5; ++k)
            {
                for (int v = 0; v < 2; ++v)
                {
                    ans = std::min(ans, dp[n][j][k][v]);
                }
            }
        }
        
        std::cout << ans << std::endl;
    }
    return 0;
}

