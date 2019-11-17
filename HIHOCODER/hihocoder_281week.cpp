#include <iostream>
#include <cstring>

int num[3005];
int dp[2][405][2][25];//��һλ�±��ʾ������ͬ������λ��, �ڶ�λ�±��ʾ������ֵ, ����λ�±��ʾ��С����, ����λ�±��ʾ�Ѿ����˼���, dp��ʾǰ���ֵ֮��
int tmp[25];//������ε�ʱ��, ��ֵ֮�͵���Сֵ

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
                //�����, �Լ���С����, Ӧ������һ�����ڵ��Ĳ�ֵ�ۼ�
                dp[i & 1][j][0][k] = dp[!(i & 1)][j][0][k] + sol(i, j - 200, 0);

                //���, �Լ���С����
                if (k > 0)
                {
                    dp[i & 1][j][0][k] = std::min(dp[i & 1][j][0][k], tmp[k - 1] + sol(i, j - 200, 0));
                }

                //�����, �Լ��Ǵ����, Ӧ������һ�����ڵ��Ĳ�ֵ�ۼ�
                dp[i & 1][j][1][k] = dp[!(i & 1)][j][1][k] + sol(i, j - 200, 1);

                //���, �Լ��Ǵ����
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
