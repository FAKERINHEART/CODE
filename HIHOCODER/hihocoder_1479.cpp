#include <iostream>
#include <vector>

using namespace std;

vector<int> G[100001];
long long value[100001];
long long sum, ans, once;

int init(int u)
{
    for (int i = 0; i < G[u].size(); i ++)
    {
        int v = G[u][i];
        value[u] += init(v);
    }

    return value[u];
}

void dfs(int u, int twice, int tmp)
{
    if (value[u] == sum / 3 && u != G[0][0])
    {
        ans += (once + twice - tmp);
        ++once;
        ++tmp;
    }

    if (value[u] == sum / 3 * 2 && u != G[0][0])
    {
        ++twice;
    }

    for (int i = 0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        dfs(v, twice, tmp);
    }
    
    return;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        for (int i = 0; i <= N; ++i)
        {
            G[i].clear();
        }

        sum = 0;

        for (int i = 1; i <= N; ++i)
        {
            int v, p;
            cin >> v >> p;
            G[p].push_back(i);
            value[i] = v;
            sum += value[i];
        }

        if (sum % 3 != 0)
        {
            cout << 0 << endl;
            continue;
        }

        ans = 0;
        once = 0;
        init(G[0][0]);
        
        dfs(G[0][0], 0, 0);
        cout << ans << endl;
    }

    return 0;
}
