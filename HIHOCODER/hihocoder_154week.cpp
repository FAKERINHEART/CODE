#include <iostream>
#include <cstring>

using namespace std;

int graph[1024][1024];
int x[1024], y[1024], r[1024];

bool dfs(int i, bool* visited)
{
	visited[i] = true;
	if (y[i] - r[i] <= 0) return true;
	
	for (int k = 0; graph[i][k] != -1; ++k) 
	{
		int j = graph[i][k];
		if (visited[j] == false)
		{
			if (dfs(j, visited))
			{
				return true;
			}
		}
	}
	return false;
}

int main() 
{
	int T, W, H, N;
	cin >> T;
	
	while(T--)
	{
		cin >> W >> H >> N;
		
		for(int i = 0; i < N; ++i)
		{
			cin >> x[i] >> y[i] >> r[i];
		}
		
		int neighbour[1024];
		memset(neighbour, 0, sizeof(neighbour));
		
		for(int i = 0; i < N; ++i) 
		{
			for(int j = i + 1; j < N; ++j) 
			{
				long long dx = x[i] - x[j], dy = y[i] - y[j], sr = r[i] + r[j];
				
				if(dx * dx + dy * dy <= sr * sr) 
				{
					graph[i][neighbour[i]] = j;
					graph[j][neighbour[j]] = i;
					++neighbour[i];
					++neighbour[j];
				}
			}
		}
		
		for(int i = 0; i < N; ++i)	graph[i][neighbour[i]] = -1;
		
		bool visited[1024];
		memset(visited, false, sizeof(visited));
		
		bool find = false;
		for(int i = 0; i < N; ++i) 
		{
			if(y[i] + r[i] >= H) 
			{
				if(dfs(i, visited)) 
				{
					find = true;
					break;
				}
			}
		}
		
		if(find == 0) 
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

