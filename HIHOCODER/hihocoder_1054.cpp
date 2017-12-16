#include <iostream>
#include <cstring>

using namespace std;

int mark[10][10];
int n;

bool graph[10][10], used[10];
int pos[10];
int ans;

void dfs(int cur)
{
    if (cur > 4)
    {
        int k = 0;
        
        for (int i = 2; i < cur; ++i)
        {
            if(graph[pos[i-1]][pos[i]] == true)
            {
                ++k;
            }
        }
        
        if(k == n) ans++;
    }

    for (int i = 1; i <= 9; ++i)
    {
        if (used[i] == false)
        {
            // e.g. 访问了13, 而2没有访问
            if (mark[i][pos[cur-1]] != 0 && used[mark[i][pos[cur-1]]] == false)
            {
                continue;
            }
            
            used[i] = true;
            pos[cur] = i;
            dfs(cur + 1);
            used[i] = false;
        }
    }
    
    return;
}

int main()
{
    mark[1][3] = 2;
    mark[1][7] = 4;
    mark[1][9] = 5;
    mark[2][8] = 5;
    mark[3][7] = 5;
    mark[3][9] = 6;
    mark[4][6] = 5;
    mark[7][9] = 8;

    for (int i = 1; i <= 9; ++i)
    {
        for(int j = i + 1; j <= 9; ++j) 
        {
            mark[j][i] = mark[i][j];
        }
    }

    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> n;
        memset(graph, false, sizeof(graph));
        
        for (int i = 0; i < n; ++i)
        {
            int x, y; cin >> x >> y;
            graph[x][y] = graph[y][x] = true;
        }
        
        memset(used, false, sizeof(used));
        ans = 0;
        dfs(1);
        
        cout << ans << endl;
    }
    return 0;
}
