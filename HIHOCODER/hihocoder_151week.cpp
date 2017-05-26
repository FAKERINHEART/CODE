#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
 
int cube[105][105][105];
int data[100005][3];

const int dx[] = {0, 0, 1,-1, 0, 0};
const int dy[] = {0, 0, 0, 0, 1,-1};
const int dz[] = {1,-1, 0, 0, 0, 0};

struct State
{
    int x, y, z;
    State(): x(0), y(0), z(0){}
    State(int a, int b, int c): x(a), y(b), z(c){}
};

bool adjacent(int x, int y, int z)
{
    int a, b, c;
    if(z == 1) 
    {
        return true;
    }
    for(int i = 0; i < 6; i++)
    {
        a = x + dx[i];
        b = y + dy[i];
        c = z + dz[i];
        if( a > 0 && b > 0 && c > 0 && cube[a][b][c])
        {
            return true;
        }
    }
    return false;
}

bool bfs(int x, int y, int z, int limit, int tag)
{
    queue<State> que;
    
    que.push(State(x, y, z));
    cube[x][y][z] = tag;
    
    bool ret = false;
    int a, b, c;
    
    while(!que.empty())
    {
        State now = que.front(); que.pop();
        
        for(int i = 0; i < 6; i++)
        {
            a = now.x + dx[i];
            b = now.y + dy[i];
            c = now.z + dz[i];
            if( a < 0 || b < 0 || c < 1 || a > limit || b > limit || c > limit)
            {
                continue;
            }

            if(cube[a][b][c] > tag)
            {
                ret = true;
            }
                
            if(cube[a][b][c])
            {
                continue;
            }
            else
            {
                cube[a][b][c] = tag;
                que.push(State(a, b, c));                
            }
        }
    }
    return ret;
}

int main()
{
    int T, x, y, z, limit, count;
    bool flag;
    
    cin >> T;
    
    while(T--)
    {
        limit  = 0;
        flag = true;
        
        cin >> count;
        memset(cube, 0, sizeof(cube));
        
        for(int i = 0; i < count; ++i)
        {
            cin >> x >> y >> z;
            
            if(!adjacent(x,y,z)) flag = false;
                
            cube[x][y][z] = i + 1;
            data[i][0] = x;
            data[i][1] = y;
            data[i][2] = z;
            limit = max(max(limit, x), max(y, z));
        }
        
        ++limit;
        
        if(flag)
        {
            bfs(limit, limit, limit, limit, count + 10);
            
            while(count-- && flag)
            {
                flag = bfs(data[count][0], data[count][1], data[count][2], limit, count + 10);
            }  
        }
        
        if(flag)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
