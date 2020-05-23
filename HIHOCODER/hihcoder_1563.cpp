#include <iostream>

int a[300010];
long long sum[300010];
long long dis[300010];

int check(int p, int d)
{
    return sum[p + d] - sum[p - d - 1];
}

int main()
{
    int N, M;
    std::cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        std::cin >> a[i];

        a[2 * N + i] = a[N + i] = a[i];
    }

    for (int i = 1; i <= 3 * N; ++i)
    {
        sum[i] = sum[i - 1] + (a[i] == 0);
        dis[i] = dis[i - 1] + (a[i] == 0) * i;
    }

    if (sum[N] < M)
    {
        std::cout << -1 << std::endl;

        return 0;
    }

    long long ans = 1LL << 60;

    for (int i = N + 1; i <= 2 * N; ++i)
    {
        int l = 0;
        int r = N / 2;

        //开始二分枚举半径
        while (l < r)
        {
            int mid = (l + r) / 2;

            if (sum[i + mid] - sum[i - mid - 1] >= M)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        long long num  = sum[i + l] - sum[i - l - 1];
        long long now = (i * (sum[i] - sum[i - l - 1]) - (dis[i] - dis[i - l - 1])) + ((dis[i + l] - dis[i]) - i * (sum[i + l] - sum[i])) - l * (num - M);

        ans = std::min(ans, now);
    }

    std::cout << ans << std::endl;

    return 0;
}

