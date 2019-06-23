#include <iostream>
#include <cstring>

int mat[251][251];
int sum[251][251];
int sub_sum[251];

int main()
{
    int N, M, K;
    std::cin >> N >> M >> K;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            std::cin >> mat[i][j];
            sum[i][j] = sum[i - 1][j] + mat[i][j];
        }
    }

    int ans = -1;

    for (int len = 1; len <= N; ++len)
    {
        for (int i = 1; i + len - 1 <= N; i ++)
        {
            sub_sum[0] = 0;

            for (int j = 1; j <= M; j ++)
            {
                sub_sum[j] = sum[i + len - 1][j] - sum[i - 1][j];
                sub_sum[j] += sub_sum[j - 1];
            }

            int p1 = 1, p2 = 1;

            while (p2 <= M)
            {
                while (sub_sum[p2] - sub_sum[p1 - 1] <= K && p2 <= M)
                {
                    ++p2;
                }
                
                if (sub_sum[p2 - 1] - sub_sum[p1 - 1] <= K)
                {
                    ans = std::max(ans, (p2 - p1) * len);
                }
                
                while (sub_sum[p2] - sub_sum[p1 - 1] > K && p1 <= p2)
                {
                    ++p1;
                }
            }
        }
    }

    if(ans == 0)
    {
        ans = -1;
    }

    std::cout << ans << std::endl;

    return 0;
}
