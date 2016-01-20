#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int A[N + 1][147], B[N + 1][147], level[N + 1];
	for(int i = 1; i <= N; i++) 
	{
		int damage, coin;
		cin >> damage >> coin;
		A[i][0] = 0;
		B[i][0] = 0;
		level[i] = 0;
		while(B[i][level[i]] <= M)
		{
			++level[i];
			A[i][level[i]] = damage * level[i];
			B[i][level[i]] = coin + B[i][level[i] - 1];
			coin = coin * 1.07;
		}
		level[i]--;
	}
	
	int dp[N + 1][M + 1];
	memset(dp, 0, sizeof(dp));
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 0; j <= M; j++)
		{
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			for(int k = 1; k <= level[i]; k++)
			{
				if(j >= B[i][k]) dp[i][j] = max(dp[i][j], dp[i - 1][j - B[i][k]] + A[i][k]);
				else break;
			}
			
		}
	}
	cout << dp[N][M] << endl;
	
	return 0;
}
