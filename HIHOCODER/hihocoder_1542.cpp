#include <iostream>
#include <cstring>

bool g[1001][1001];
int N, K;
int parent[1001];

void dfs(int now)
{
    for (int i = 1; i <= N; ++i)
    {
        if (g[now][i] == false || i == K || parent[i] != 0)
        {
            continue;
        }
        
        parent[i] = now;
        
        dfs(i);
    }

    return;
}

int main()
{
    std::cin >> N >> K;
    memset(g, false, sizeof(g));
    memset(parent, 0, sizeof(parent));
    
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        g[a][b] = true;
        g[b][a] = true;
    }
    
    dfs(K);
    
    for (int i = 1; i <= N; ++i)
    {
        std::cout << parent[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
