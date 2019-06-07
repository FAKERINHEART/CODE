#include <iostream>
#include <vector>

std::vector<int> mp[2001];
long long N;
long long F[2001];
long long IN[2001];
long long IP[2001];
long long C[2001];

long long dfs(int x)
{
    long long dp[20001];
    dp[0]=0;

    for (int i = 1;i <= IN[x]; ++i)
    {
        dp[i]=1e16;
    }
    
    for (int i = 0; i < mp[x].size(); ++i)
    {
        int v = mp[x][i];
        long long tmp= dfs(v);

        for(int j = IN[x]; j > 0; --j)
        {
            dp[j] = std::min(dp[j], dp[std::max(j - IP[v], 0LL)] + C[v] + tmp);
        }
    }
    return dp[IN[x]];
}

int main()
{
    std::cin >> N;
    int root;

    for (int i = 1; i <= N; ++i)
    {
        std::cin >> F[i] >> IN[i] >> IP[i] >> C[i];
        if (F[i] == 0)
        {
            root = i;
        }

        mp[F[i]].push_back(i);
    }

    long long ans = dfs(root);

    if (ans >= 1e16)
    {
        std::cout << -1 << std::endl;
    }
    else
    {
        std::cout << ans + C[root] << std::endl;
    }
    
    return 0;
}
