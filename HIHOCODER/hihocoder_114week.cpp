#include <iostream>

using namespace std;

int mat[2][101][101];
int N;

void dfs(int tag, int n, int x0, int y0)
{
	int MIN[n][n];
	int tp[n][n];
	if(n % 2)
	{
		int rotate_tp[n][n];
		for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) MIN[i][j] = tp[i][j] = mat[tag][x0 + i][y0 + j];
		for(int k = 0; k < 3; ++k)
		{
			for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) rotate_tp[i][j] = tp[n - 1 - j][i];
			for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) tp[i][j] = rotate_tp[i][j];
			int flag = 0;
			for(int j = 0; j < n; ++j)
			{
				for(int i = 0; i < n; ++i)
				{
					if(tp[i][j] < MIN[i][j]) 
					{
						flag = 1;
						break;		
					}
					else if(tp[i][j] > MIN[i][j])
					{
						flag = -1;
						break;
					}
				}
				if(flag) break;
			}
			if(flag == 1) for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) MIN[i][j] = tp[i][j];
		}
	}
	else
	{
		dfs(tag, n / 2, x0, y0);
		dfs(tag, n / 2, x0, y0 + n / 2);
		dfs(tag, n / 2, x0 + n / 2, y0);
		dfs(tag, n / 2, x0 + n / 2, y0 + n / 2);
		int swap_tp[n / 2][n / 2];
		for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) MIN[i][j] = tp[i][j] = mat[tag][x0 + i][y0 + j];
		for(int k = 0; k < 3; ++k)
		{
			for(int i = 0; i < n / 2; ++i) for(int j = 0; j < n / 2; ++j) swap_tp[i][j] = tp[i][j];
			for(int i = 0; i < n / 2; ++i) for(int j = 0; j < n / 2; ++j) tp[i][j] = tp[i][n / 2 + j];
			for(int i = 0; i < n / 2; ++i) for(int j = 0; j < n / 2; ++j) tp[i][n / 2 + j] = tp[n / 2 + i][n / 2 + j];
			for(int i = 0; i < n / 2; ++i) for(int j = 0; j < n / 2; ++j) tp[n / 2 + i][n / 2 + j] = tp[n / 2 + i][j];
			for(int i = 0; i < n / 2; ++i) for(int j = 0; j < n / 2; ++j) tp[n / 2 + i][j] = swap_tp[i][j];
			
			int flag = 0;
			for(int j = 0; j < n; ++j)
			{
				for(int i = 0; i < n; ++i)
				{
					if(tp[i][j] < MIN[i][j]) 
					{
						flag = 1;
						break;		
					}
					else if(tp[i][j] > MIN[i][j])
					{
						flag = -1;
						break;
					}
				}
				if(flag) break;
			}
			if(flag == 1) for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) MIN[i][j] = tp[i][j];
		}
	}
	for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) mat[tag][x0 + i][y0 + j] = MIN[i][j];
	
	return;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> N;
		for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) cin >> mat[0][i][j];
		for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) cin >> mat[1][i][j];
		dfs(0, N, 0, 0);
		dfs(1, N, 0, 0);
		
		bool flag = true;
		for(int i = 0; i < N; ++i) 
		{
			for(int j = 0; j < N; ++j) 
			{
				if(mat[0][i][j] != mat[1][i][j])
				{
					flag = false;
					break;
				}
			}
			if(flag == false) break;
		}
		if(flag) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
