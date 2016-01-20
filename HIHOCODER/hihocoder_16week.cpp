#include <iostream> 
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int dp[20][1000000];

int main()
{
	int N;
	memset(dp, 0, sizeof(dp));
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", &dp[0][i]);
	int rows = int(log(N * 1.0) / log(2.0));
	for(int i = 1; i <= rows; i++) for(int j = 0; j + (1 << i) - 1 < N; j++) dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
	
	int Q, one, two, len;
	scanf("%d", &Q);
	for(int i = 0; i < Q; i++)
	{
		scanf("%d%d", &one, &two);
		len = int(log((two - one + 1) * 1.0) / log(2.0));
		printf("%d\n", min(dp[len][one - 1], dp[len][two - (1 << len)]));
	}
	return 0;
}
