#include <iostream>
#include <cstring>

int num[3005];
int dp[2][405][2][25];//第一位下标表示连续不同的音调位置, 第二位下标表示和旋音值, 第三位下标表示大小和旋, 第四位下标表示已经换了几次, dp表示前面差值之和
int tmp[25];//变调几次的时候, 差值之和的最小值

int sol(int a, int b, int c)
{
    int res = 0;
    res += abs(num[a] - b);
    res += abs(num[a + 1] - b - 3 - c);
    res += abs(num[a + 2] - b - 7);
    return res;
}

int main()
{
    int N, K;
    std::cin >> N >> K;

    for (int i = 1; i <= 3 * N; ++i)
    {
        std::cin >> num[i];
    }

    for (int i = 1; i <= 3 * N; i += 3)
    {
        for (int j = 0; j <= 400; ++j)
        {
            for (int k = 0; k <= K; ++k)
            {
                //不变调, 自己是小和弦, 应该是上一个相邻调的差值累加
                dp[i & 1][j][0][k] = dp[!(i & 1)][j][0][k] + sol(i, j - 200, 0);

                //变调, 自己是小和弦
                if (k > 0)
                {
                    dp[i & 1][j][0][k] = std::min(dp[i & 1][j][0][k], tmp[k - 1] + sol(i, j - 200, 0));
                }

                //不变调, 自己是大和弦, 应该是上一个相邻调的差值累加
                dp[i & 1][j][1][k] = dp[!(i & 1)][j][1][k] + sol(i, j - 200, 1);

                //变调, 自己是大和弦
                if (k > 0)
                {
                    dp[i & 1][j][1][k] = std::min(dp[i & 1][j][1][k], tmp[k - 1] + sol(i, j - 200, 1));
                }
            }
        }

        memset(tmp, 0x3f, sizeof tmp);

        for(int j = 0; j <= 400; j++)
        {
            for(int k = 0; k <= K; k++)
            {
                tmp[k] = std::min(tmp[k], dp[i & 1][j][0][k]);
                tmp[k] = std::min(tmp[k], dp[i & 1][j][1][k]);
            }
        }
    }

    std::cout << tmp[K] << std::endl;

    return 0;
}
