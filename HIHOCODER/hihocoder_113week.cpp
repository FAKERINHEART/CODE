#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int fn[25];
	fn[0] = 1;
	fn[1] = 1;
	for(int i = 2; i <= 24; i++) fn[i] = fn[i - 1] + fn[i - 2];
	
	int n;
	cin >> n;
	int str[n];
	for(int i = 0; i < n; i++) cin >> str[i];
	long long dp[n][25];
	memset(dp, 0, sizeof(dp));
	if(str[0] == 1) dp[0][0] = 1;
	for(int i = 1; i < n; i++)
	{
		if(str[i] == 1) dp[i][0] = (dp[i - 1][0] + 1) % 1000000007;
		else dp[i][0] = dp[i - 1][0];
		for(int j = 1; j <= 24; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if(str[i] == fn[j])	dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % 1000000007;	
		} 
	}
	long long sum = 0;
	for(int i = 0; i <= 24; i++) sum = (sum + dp[n - 1][i]) % 1000000007; 
	cout << sum << endl;
	
	return 0;
}
