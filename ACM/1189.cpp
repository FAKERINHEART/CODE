#include <iostream>
#include <cstring>

using namespace std;

long long gcd(long long a, long long b)
{
	return (!b)? a: gcd(b, a % b);
}

int main()
{
	long long dp[55][55];
	char board;
	int n, m;
	memset(dp, 0, sizeof(dp));
	cin >> n >> m;
	dp[0][0] = 1ll << n;//1 long long
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			cin >> board;
			if(board == '*')
			{
				dp[i + 1][j] += (dp[i][j] >> 1);
				dp[i + 1][j + 1] += (dp[i][j] >> 1);
			}
			else dp[i + 2][j + 1] += dp[i][j];
		}
	}
	long long mod = gcd(dp[0][0], dp[n][m]);
	cout << dp[n][m] / mod << "/" << dp[0][0] / mod << endl;
	return 0;
} 
