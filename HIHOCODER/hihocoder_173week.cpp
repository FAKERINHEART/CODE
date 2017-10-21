#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	long long  A[N + 1], sum[N + 1];
	long long dp[N + 1][N + 1];
	
	sum[0] = 0;
	
	for(int i = 1; i <= N; ++i)
	{
		cin >> A[i];
		sum[i] = sum[i - 1] + A[i];
	}
	
	memset(dp, 0, sizeof(dp));
	
	for(int k = 1; k <= N; ++k)
	{
		for(int j = k; j >= 1; --j)
		{
			dp[j][k] = max(sum[k] - sum[j - 1] - dp[j + 1][k], sum[k] - sum[j - 1] - dp[j][k - 1]);
		}
	}
	
	cout << dp[1][N] << endl;
 
    return 0;
}
