#include <iostream>
#include <algorithm>
#include <cstring>

std::pair<int,int> arr[5050];
int dp[5050][5050];//N个硬币按年份从小到大排列后, dp[i][j],放第i个硬币时,能选出j个硬币的最大值

int main()
{
    int T;
    std::cin >> T;

    while(T--)
    {
        int N, R;
        std::cin >> N >> R;

        for (int i = 1; i <= N; ++i)
        {
           std::cin >> arr[i].first;
        }

        for (int i = 1; i <= N; ++i)
        {
            std::cin >> arr[i].second;
        }

        sort(arr + 1, arr + N + 1);
        memset(dp, 0, sizeof(dp));
        dp[1][1] = arr[1].second;

        for (int i = 2; i <= N; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                //第一种情况: 第i个硬币就放在第i-1个硬币的前面, 导致第i-1个硬币失效
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + arr[i].second - arr[i - 1].second);
            }

            for (int j = 0; j <= i; ++j)//第二种情况: 第i个硬币放在第i-1个硬币的后R+1个位置
            {
                //j表示没被选出来硬币的个数
                int k = std::max(i - j - R - 1, 0);//第i-1个硬币时, 被选出来k个硬币
                int s = std::min(i, k + R + 1);//

                dp[i][s] = std::max(dp[i][s], dp[i - 1][k] + arr[i].second);
            }

            for (int j = 1; j <= i; ++j)
            {
                //向后聚合
                dp[i][j] = std::max(dp[i][j], dp[i][j - 1]);
            }
        }

        std::cout << dp[N][N] << std::endl;
    }

    return 0;
}
