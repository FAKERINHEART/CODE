#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int a[500][500], b[500][500];
int leftt, rightt, upt, downt;
int N, M;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    leftt = min(leftt, y);
    rightt = max(rightt, y);
    upt = min(upt, x);
    downt = max(downt, x);

    a[x][y] = 0;
    b[x][y] = 1;

    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < N && ny < M && a[nx][ny] != 0)
        {
            dfs(nx, ny);
        }
    }
    
    return;
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;

        for(int j = 0; j < M; ++j)
        {
            if(str[j] == '0')
            {
               a[i][j] = 0;
            }
            else
            {
                a[i][j] = 1;
            }
        }
    }

    for (int j = 0; j < M; ++j)
    {
        for (int i = 0; i < N; ++i)
        {
            if (a[i][j] != 0)
            {
                leftt = upt = 500;
                rightt = downt = 0;

                dfs(i, j);
                
                int xx = downt - upt + 1;
                int yy = rightt - leftt + 1;

                cout << xx << " " << yy << endl;
                
                for (int k = upt; k <= downt; ++k)
                {
                    for(int l = leftt; l <= rightt; ++l)
                    {
                        cout << b[k][l];
                        b[k][l] = 0;
                    }
                    
                    cout << endl;
                }
            }
        }
    }

    return 0;
}
