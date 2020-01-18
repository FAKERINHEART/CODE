#include <iostream>
#include <vector>
#include <cstring>

int rmq[21][100001];
std::vector<int> head[100007];
int parent[100001], depth[100001];

void dfs(int u, int p,int dep)
{
    if (parent[u] != -1)
    {
        return;
    }

    parent[u] = p;
    depth[u] = dep;

    for(int i = 0; i < head[u].size(); ++i)
    {
        dfs(head[u][i], u, dep + 1);
    }
    
    return;
}

void InitRMQ(int n)
{
    for (int i = 1;i <= n; i++)
    {
        rmq[0][i] = parent[i];
    }
        
    for(int i = 1; i <= 20; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            int u = rmq[i-1][j];
            rmq[i][j] = rmq[i-1][u];
        }
    }

}

int GetDepParent(int id, int dep)
{
    dep = depth[id] - dep;

    if (dep <= 0)
    {
        return id;
    }

    for (int i = 0; dep > 0; ++i, dep /= 2)
    {
        if (dep & 1 != 0)
        {
            id = rmq[i][id];
        }
    }

    return id;
}

int GetParent(int x1, int x2)
{
    int low = 1, high = std::min(depth[x1], depth[x2]);

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if(GetDepParent(x1, mid) == GetDepParent(x2, mid))
        {
            low =  mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return GetDepParent(x1, high);
}

int main()
{
    int T, n, m;
    std::cin >> T;

    while (T--)
    {
        std::cin >> n >> m;

        for (int i = 0;i <= n; ++i)
        {
            head[i].clear();
        }
            
        for (int i = 1; i < n; ++i)
        {
            int x, y;
            std::cin >> x >> y;

            head[x].push_back(y);
            head[y].push_back(x);
        }

        memset(parent, -1, sizeof(parent));
        dfs(1, 1, 1);
        InitRMQ(n);

        for(int i = 0;i < m; i++)
        {
            int x1, x2, y1, y2;
            std::cin >> x1 >> x2 >> y1 >> y2;

            int p1 = GetParent(x1, x2);
            int p2 = GetParent(y1, y2);

            if (depth[p1] < depth[p2])
            {
                p1 = p2;
            }

            p1 = depth[p1];

            int t1 = GetDepParent(x1, p1);
            int t2 = GetDepParent(x2, p1);
            int z1 = GetDepParent(y1, p1);
            int z2 = GetDepParent(y2, p1);

            if(t1 == z1 || t1 == z2 || t2 == z1 || t2 == z2)
            {
                std::cout << "YES" << std::endl;
            }
            else
            {
                std::cout << "NO" << std::endl;
            }
        }
    }

    return 0;
}

