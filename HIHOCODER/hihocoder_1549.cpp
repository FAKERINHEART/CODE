# include <iostream>
# include <cstring>

int n, k;
int a[100005];

long long quick_mi(long long x, long long y)
{
    long long res = 1;

    while (y)
    {
        if (y & 1)
        {
            res = res * x % 1000000007;
        }

        x = x * x % 1000000007;
        y /= 2;
    }

    return res;
}

long long C(long long x, long long y)
{
    if (x > y)
    {
        return 0;
    }

    long long res = 1;

    for (int i = 1; i <= y; ++i)
    {
        res = (res * i) % 1000000007;
    }
        
    long long mj = 1, mnj = 1;

    for (int i = 1; i <= x; ++i)
    {
        mj = (mj * i) % 1000000007;
    }
        
    for (int i = 1; i <= (y - x); ++i)
    {
        mnj = (mnj * i) % 1000000007;
    }

    mj = quick_mi(mj, 1000000007 - 2);
    mnj = quick_mi(mnj, 1000000007 - 2);

    res = (res * mj % 1000000007) * mnj % 1000000007;

    return res;
}

long long slove(int x, int n)
{
    return (C(k, n) - C(k, x) + 1000000007 ) % 1000000007;
}

int main()
{
    int T;
    std::cin >> T;

    while (T--)
    {
        std::cin >> n >> k;

        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
        }
        
        long long ans = 0;

        for (int i = 0; i < 20; ++i)
        {
            int zero = 0;

            for (int j = 0; j < n; ++j)
            {
                if ((a[j]>>i) & 1)
                {
                    continue;
                }
                
                ++zero;
            }

            ans = (ans + (1LL << i) * slove(zero, n) % 1000000007) % 1000000007;
        }
        
        std::cout << ans << std::endl;
    }
    return 0;
}
