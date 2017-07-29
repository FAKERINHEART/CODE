#include <iostream>
#include <cstring>

using namespace std;

int N, M;
bool Map[501][501];
bool visited[501];

void dfs(int now)
{
	visited[now] = true;
	
	for(int i = 1; i <= N; ++i)
	{
		if(Map[now][i] == true && visited[i] == false)
		{
			dfs(i);
		}
	}
	
	return;
}

int main()
{
	int T;
	
	cin >> T;
	
	while(T--)
	{
		cin >> N >> M;
		memset(Map, false, sizeof(Map));
		memset(visited, false, sizeof(visited));
		
		int num_M = 0;
		
		for(int i = 0; i < M; ++i)
		{
			int x, y;
			
			cin >> x >> y;
			
			if(Map[x][y] == false) ++num_M;
			
			Map[x][y] = Map[y][x] = true;
		}
		
		if(N != num_M + 1)
		{
			cout << "NO" << endl;
			
			continue;
		}
		
		dfs(1);
		
		bool flag = true;
		
		for(int i = 1; i <= N; ++i)
		{
			if(visited[i] == false)
			{
				flag = false;
				
				break;
			}
		}
		
		if(flag == true)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	
	return 0;
}
