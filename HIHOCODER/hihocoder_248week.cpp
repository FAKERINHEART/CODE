#include<iostream>
#include<string.h>

using namespace std;

int n, m, k;
int mcnt[101];
int M[101][101];

int leaves[101];
bool is_leaf[101];
int dist[101][101];

int parent[101];

void update(int node)
{
    int p = parent[node];

    for (int i = 1; i <= n; ++i)
    {
        if (dist[node][i] != -1)
        {
            dist[p][i] = dist[i][p] = dist[node][i] - 1;
        }
    }
}

int main()
{
    memset(parent, -1, sizeof(parent));

    cin >> n >> m >> k;

    for (int i = 1; i <= m; ++i)
    {
        cin >> mcnt[i];
    }
    
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= mcnt[i]; ++j)
        {
            cin >> M[i][j];
        }
    }

    memset(is_leaf, false, sizeof(is_leaf));

    for (int i = 1; i <= k; ++i)
    {
        cin >> leaves[i];
        is_leaf[leaves[i]] = true;
    }

    memset(dist, -1, sizeof(dist));

    for (int i = 1; i <= k ; ++i)
    {
        for(int j = 1; j <= k; ++j)
        {
            cin >> dist[leaves[i]][leaves[j]];
        }
    }

    for(int i = m; i > 1; --i)
    {
        int S = i, P = i - 1;
        int pos_S = 1, pos_P = 1;

        while (pos_P <= mcnt[P] && is_leaf[M[P][pos_P]] == true)
        {
            ++pos_P;
        }

        parent[M[S][pos_S]] = M[P][pos_P];

        while (pos_S <= mcnt[S])
        {
            int node1 = M[S][pos_S];

            if (pos_S == mcnt[S])
            {
                update(node1);
                break;
            }
            else
            {
                int node2 = M[S][pos_S + 1];

                if (dist[node1][node2] != 2)
                {
                    update(node1);
                    ++pos_P;

                    while (pos_P <= mcnt[P] && is_leaf[M[P][pos_P]] == true)
                    {
                        ++pos_P;
                    }
                }

                parent[node2] = M[P][pos_P];
                ++pos_S;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (parent[i] == -1)
        {
            cout << 0 << " ";
        }
        else
        {
            cout << parent[i] << " ";
        }
    }
    
    cout << endl;

    return 0;
}
