#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <set>

using namespace std;

int n, m;
string graph[50];
bool visited[50][50];
int direction[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void dfs(int x, int y, int& area, string& shape)
{
    for(int i = 0; i < 4; ++i)
    {
        int next_x = x + direction[i][0];
        int next_y = y + direction[i][1];
        
        if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= m || visited[next_x][next_y] || graph[next_x][next_y] == '.')
        {
            continue;
        }
        else
        {
            shape += (char)(i + '0');
            visited[next_x][next_y] = true;
            
            dfs(next_x, next_y, ++area, shape);
            
            shape += (char)(4 - i + '0');
        }
    }

    return;
}

int main()
{
    cin >> n >> m;
    
    for(int i = 0; i < n; ++i)
    {
        cin >> graph[i];
    }

    memset(visited, false, sizeof(visited));
    
    int count = 0, area_count = 0, shape_count = 0;
    map<int, set<string> > Map;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(visited[i][j] == false && graph[i][j] == '#')
            {
                visited[i][j] = true;
                int area = 1;
                string shape{};

                dfs(i, j, area, shape);

                if(Map.find(area) == Map.end())
                {
                    ++area_count;
                    ++shape_count;
                    Map[area].insert(shape);
                }
                else
                {
                    if(Map[area].find(shape) == Map[area].end())
                    {
                        ++shape_count;
                        Map[area].insert(shape);
                    }
                }
                
                ++count;
            }
        }
    }

    cout << count << " " << area_count << " " << shape_count << endl;

    return 0;
}
