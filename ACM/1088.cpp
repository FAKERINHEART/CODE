#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int height[100][100], length[100][100];
int R, C;

int dfs(int r, int l)
{
	if(length[r][l] > 0) return length[r][l];
	if(l > 0 && height[r][l - 1] < height[r][l]) length[r][l] = max(length[r][l], dfs(r, l - 1));
	if(r > 0 && height[r - 1][l] < height[r][l]) length[r][l] = max(length[r][l], dfs(r - 1, l));
	if(l < C - 1 && height[r][l + 1] < height[r][l]) length[r][l] = max(length[r][l], dfs(r, l + 1));
	if(r < R - 1 && height[r + 1][l] < height[r][l]) length[r][l] = max(length[r][l], dfs(r + 1, l));
	length[r][l]++; 
	return length[r][l];
}

int main()
{
	cin >> R >> C;
	for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) cin >> height[i][j];
	memset(length, 0, sizeof(length));
	for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) dfs(i, j);
	int MAX = -1;
	for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) MAX = max(MAX, length[i][j]);
	cout << MAX << endl;
	return 0;
}
