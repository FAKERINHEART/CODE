#include <iostream>
#include <cstring>

using namespace std;

const int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool maze[1000][1000];
int parent[1000000];

int findp(int x)
{
    return (~parent[x])? (parent[x] = findp(parent[x])): x;
}

int unit(int u, int v)
{
    u = findp(u), v = findp(v);

    if(u == v)
    {
        return 0;
    }

    parent[v] = u;

    return 1;
}

int main()
{
    memset(parent, 255, sizeof(parent));

    int N;
    cin >> N;
    
    int island_num = 0, perimeter = 0;

    for(int i = 1; i <= N; ++i)
    {
        int x, y;
        cin >> x >> y;

        ++island_num;

        for(int j = 0; j < 4; ++j)
        {
            int dx = x + dir[j][0], dy = y + dir[j][1];

            if(dx >= 0 && dx < 1000 && dy >= 0 && dy < 1000 && maze[dx][dy] == true)
            {
                island_num -= unit(x * 1000 + y, dx * 1000 + dy);
                --perimeter;
            }
            else ++perimeter;
        }

        maze[x][y] = true;
        
        cout << island_num << " " << i << " " << perimeter << endl;
    }

    return 0;
}

