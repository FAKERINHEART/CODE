#include <iostream>
#include <cstring>

char g[100][100];
bool visited[100][100][4];
int xx[4] = {-1, 0, 1, 0};
int yy[4] = { 0,-1, 0, 1};
int N, M;

void dfs(int x, int y, int k)
{
	visited[x][y][k] = true;
	int tx = x + xx[k];
	int ty = y + yy[k];
	int tk = (k + 2) % 4;

	if(tx >= 0 && tx < N && ty >= 0 && ty < M && visited[tx][ty][tk] == false)
    {
        dfs(tx, ty, tk);
    }

	if(g[x][y] == '/')
    {
		if(k == 0 && visited[x][y][1] == false)
		{
		    dfs(x, y, 1);
        }
        
		if(k == 1 && visited[x][y][0] == false)
        {
            dfs(x, y, 0);
        }

        if(k == 2 && visited[x][y][3] == false)
        {
            dfs(x, y, 3);
        }
        
		if(k == 3 && visited[x][y][2] == false)
        {
            dfs(x, y, 2);
        }
	}
    else if(g[x][y] == '\\')
    {
		if(k == 0 && visited[x][y][3] == false)
        {
            dfs(x, y, 3);
        }
        
		if(k == 1 && visited[x][y][2] == false)
        {
            dfs(x, y, 2);
        }
		if(k == 2 && visited[x][y][1] == false)
        {
            dfs(x, y, 1);
        }
		if(k == 3 && visited[x][y][0] == false)
        {
            dfs(x, y, 0);
        }
	}
    else
    {
		for(int i = 0; i < 4; ++i)
        {
            if(visited[x][y][i] == false)
            {
			    dfs(x, y, i);
		    }
        }
	}
}

int main()
{
    std::cin >> N >> M;

    int count = 0;

    getchar();

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            g[i][j] = getchar();
        }
        getchar();
    }

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < N; ++i)
    {
		for (int j = 0; j < M; ++j)
        {
			for(int k = 0; k < 4; ++k)
            {
                if(visited[i][j][k] == false)
                {
				    ++count;
				    dfs(i, j, k);
			    }
            }
		}
	}

    std::cout << count << std::endl;

	return 0;
}


