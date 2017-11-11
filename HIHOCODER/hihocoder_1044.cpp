#include <iostream>
#include <cstring> 
#include <algorithm>

using namespace std; 

int main()
{
	int N, M, Q;	
	cin >> N >> M >> Q;
	int dp[N][1 << (M - 1)];
	int num[1 << (M - 1)];
	int weight[N];
	for(int i = 0; i < N; i++) cin >> weight[i];	
	
	memset(num, 0, sizeof(num));
	for(int i = 0; i < (1 << (M - 1)); i++)
	{
		int temp = i;
		while(temp)
		{
			if(temp & 1) num[i]++;
			temp = temp >> 1;
		}
	}
	
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 0;
	dp[0][1 << (M - 2)] = weight[0];
	for(int i = 0; i < N - 1; i++)
	{
		for(int j = 0; j < (1 << (M - 1)); j++)
		{
			dp[i + 1][(j >> 1)] = max(dp[i + 1][(j >> 1)], dp[i][j]);
			if(num[j] < Q) dp[i + 1][(j >> 1) + (1 << (M - 2))] = max(dp[i + 1][(j >> 1) + (1 << (M - 2))], dp[i][j] + weight[i + 1]);
		}
	}
	int ans = -1;
	for(int i = 0; i < (1 << (M - 1)); i++) ans = max(ans, dp[N - 1][i]);
	cout << ans << endl; 
	return 0;	
} 
