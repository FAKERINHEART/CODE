#include <iostream>
#include <algorithm>
#include <cstring>

std::pair<int,int> arr[5050];
int dp[5050][5050];//N��Ӳ�Ұ���ݴ�С�������к�, dp[i][j],�ŵ�i��Ӳ��ʱ,��ѡ��j��Ӳ�ҵ����ֵ

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
                //��һ�����: ��i��Ӳ�Ҿͷ��ڵ�i-1��Ӳ�ҵ�ǰ��, ���µ�i-1��Ӳ��ʧЧ
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + arr[i].second - arr[i - 1].second);
            }

            for (int j = 0; j <= i; ++j)//�ڶ������: ��i��Ӳ�ҷ��ڵ�i-1��Ӳ�ҵĺ�R+1��λ��
            {
                //j��ʾû��ѡ����Ӳ�ҵĸ���
                int k = std::max(i - j - R - 1, 0);//��i-1��Ӳ��ʱ, ��ѡ����k��Ӳ��
                int s = std::min(i, k + R + 1);//

                dp[i][s] = std::max(dp[i][s], dp[i - 1][k] + arr[i].second);
            }

            for (int j = 1; j <= i; ++j)
            {
                //���ۺ�
                dp[i][j] = std::max(dp[i][j], dp[i][j - 1]);
            }
        }

        std::cout << dp[N][N] << std::endl;
    }

    return 0;
}
