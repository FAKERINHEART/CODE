#include <iostream>
#include <cstring>

using namespace std;

int mother[1000000];
int grid[1000][1000];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int findset(int x) 
{
    if (mother[x] < 0)
	{
		mother[x] = x;
    }
	else if(mother[x] != x)
	{
		mother[x] = findset(mother[x]);
	}
    
    return mother[x];
}

void unionset(int x, int y)
{
    int mx = findset(x), my = findset(y);
    if (mx != my)
	{
        mother[mx] = my;
    }
    
    return;
}

int main()
{
    int N, count = 0; 
	cin >> N;
	
	memset(mother, -1, sizeof(mother));
    memset(grid, 0, sizeof grid);
	
    for (int i = 0; i < N; ++i)
	{
        int x, y;
		cin >> x >> y;
        grid[x][y] = 1;
        ++count;
        
        for (int j = 0; j < 4; j++)
		{
            int nx = x + dx[j];
            int ny = y + dy[j];
            
            if (nx >= 0 && ny >= 0 && nx < 1000 && ny < 1000)
			{
                if (grid[nx][ny] != 0 && findset(nx * 1000 + ny) != findset(x * 1000 + y))
				{
                    --count;
                    unionset(nx * 1000 + ny, x * 1000 + y);
                }
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}
