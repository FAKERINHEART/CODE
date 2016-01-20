#include <iostream>
#include <cstring>

using namespace std;

bool visited[8];
char board[8][8]; 
int n, k, count;

void dfs(int x, int c)
{
	if(c == k)
	{
		count++;
		return;
	}
	for(int i = x; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(visited[j] || board[i][j] == '.') continue;
			visited[j] = true;
			dfs(i + 1, c + 1);
			visited[j] = false;
		}
	}
	return;
}

int main()
{
	while(cin >> n >> k)
	{
		if(n == -1 && k == -1) break;
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> board[i][j];
		memset(visited, 0, sizeof(visited));
		count = 0;
		dfs(0, 0);
		cout << count << endl; 
	}
	return 0;	
} 
