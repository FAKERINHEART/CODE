#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 300000 + 5;
const long long mod = 1e9 + 7;

int n,m;
long long fac[maxn];

long long mod_pow(long long a,long long n,long long mod)
{
    long long ret = 1;

    while (n > 0)
    {
        if (n & 1)
        {
            ret = ret * a % mod;
        }

        a = a * a % mod;
        n >>= 1;
    }

    return ret;
}


int main()
{
    std::cin >> n >> m;
    fac[0] = 1;

    for (int i = 1; i <= n * m; ++i)
    {
        fac[i] = fac[i - 1] * i % mod;
    }

    long long ans = fac[n * m];

    for (int i = 1; i < m; ++i)
    {
        ans = (ans * fac[i]) % mod;
    }

    for (int i = n; i < n + m; ++i)
    {
        ans = (ans * mod_pow(fac[i], mod - 2, mod)) % mod;
    }

    cout << ans << endl;

    return 0;
}
