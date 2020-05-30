#include <iostream>
#include <vector>

int n, a[100001], parent[100001];
std::vector<int> g[100001];
long long p[100001], ans;

void dfs(int x)
{
    for (int i = 0; i < (int)g[x].size(); ++i)
    {
        int y = g[x][i];
        dfs(y);
        p[x] = std::max(p[x], p[y]);
    }

    for (int i = 0; i < (int)g[x].size(); ++i)
    {
        int y = g[x][i];
        ans += p[x] - p[y];
    }

    p[x] += a[x];

    return;
}

int main()
{
    std::cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
    }

    for (int i = 1; i < n; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        parent[b] = a;
        g[a].push_back(b);
    }

    int root = 1;

    for (int i = 1; i <= n; ++i)
    {
        if (parent[i] == 0)
        {
            root = i;
            break;
        }
    }
    
    dfs(root);

    std::cout << ans << std::endl;

    return 0;
}

