#include <iostream>

int N, g[21][401][401], a[201][201], ans;
 
int check(int now, int x, int y)
{
    x = std::max(x, 0);
    x = std::min(x, N * 2 - 1);
    y = std::max(y, 0);
    y = std::min(y, N * 2 - 1);

    return g[now][x][y];
}

int solve(int now, int xl, int yl, int xr, int yr)
{
    return check(now, xr, yr) - check(now, xl - 1, yr) - check(now, xr, yl - 1) + check(now, xl - 1, yl - 1);
}

int main()
{
    int Q, i, j, K;

    std::cin >> N;

    for (int l = 1; l <= N; ++l)
    {
        for (int m = 1; m <= N; ++m)
        {
            std::cin >> a[l][m];
        }
    }

    for (int l = 1; l <= 20; ++l)
    {
        for (int m = 1; m <= N; ++m)
        {
            for (int n = 1; n <= N; ++n)
            {
                if (a[m][n] == l)
                {
                    g[l][m + n - 1][N - m + n] = 1;
                }
            }
        }

        for (int m = 1; m <= 2 * N - 1; ++m)
        {
            for (int n = 1; n <= 2 * N - 1; ++n)
            {
                g[l][m][n] += g[l][m - 1][n] + g[l][m][n - 1] - g[l][m - 1][n - 1];
            }
        }
    }

    std::cin >> Q;

    while (Q--)
    {
        std::cin >> i >> j >> K;
        int x = i + j - 1;
        int y = N - i + j;

        ans = 0;

        for (int l = 1; l <= 20; ++l)
        {
            if (K % l == 0)
            {
                ans += solve(l, x - K, y - K, x + K, y + K);
            }
        }

        std::cout << ans << std::endl;
    }
}
