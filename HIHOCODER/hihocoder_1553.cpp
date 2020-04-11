#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>

int len;
int po[100010][105];
int cnt[100010], has[100010];
int a[100010], anss[100010];
std::multiset<int> ss;

struct Query
{
    int L, R, k, ID, block;

    Query(){}

    Query(int l, int r, int k, int ID):L(l), R(r), k(k), ID(ID)
    {
        block = l / len;
    }

    bool operator<(const Query &rhs) const
    {
        if (block == rhs.block)
        {
            return R < rhs.R;
        }

        return block < rhs.block;
    }
};

Query queries[100010];

void insert(int n)
{
    --has[cnt[n]];

    if (cnt[n] > len)
    {
        ss.erase(ss.find(cnt[n]));
    }

    ++cnt[n];
    ++has[cnt[n]];

    if (cnt[n] > len)
    {
        ss.insert(cnt[n]);
    }
}

void erase(int n)
{
    --has[cnt[n]];

    if (cnt[n] > len)
    {
        ss.erase(ss.find(cnt[n]));
    }

    --cnt[n];
    ++has[cnt[n]];

    if (cnt[n] > len)
    {
        ss.insert(cnt[n]);
    }
}

int main()
{
    int T;
    std::cin >> T;
   
    for (int i = 1; i <= 100000; ++i)
    {
        po[i][0] = 1;

        for (int j = 1; j <= 100; ++j)
        {
            po[i][j] = 1LL * po[i][j - 1] * i % 1000000007;
        }
    }

    while (T--)
    {
        int n, m;
        std::cin >> n >> m;

        len = sqrt(n);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
        }

        int l, r, k;

        for(int i = 1; i <= m; i++)
        {
            std::cin >> l >> r >> k;
            queries[i] = Query(l, r, k, i);
        }

        std::sort(queries + 1, queries + m + 1);

        int L = 1, R = 1;

        memset(cnt, 0, sizeof(cnt));
        memset(has, 0, sizeof(has));

        cnt[a[1]] = 1;
        has[1] = 1;
        ss.clear();

        for (int i = 1; i <= m; ++i)
        {
            Query &q = queries[i];

            while(R < q.R) insert(a[++R]);
            while(L > q.L) insert(a[--L]);
            while(R > q.R) erase(a[R--]);
            while(L < q.L) erase(a[L++]);

            long long ans = 0;

            for (int j = 1; j <= len; ++j)
            {
                ans += 1LL * has[j] * po[j][q.k] % 1000000007;
                ans %= 1000000007;
            }

            for (std::multiset<int>::iterator iter = ss.begin(); iter != ss.end(); ++iter)
            {
                ans += po[*iter][q.k];
                ans %= 1000000007;
            }

            anss[q.ID] = ans;
        }

        for(int i = 1; i <= m; i++)
        {
            std::cout << anss[i] << std::endl;
        }
    }
    return 0;
}
