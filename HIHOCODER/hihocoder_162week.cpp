#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int dp[100][100];
	string S;
	
	memset(dp, 0, sizeof(dp));
	
	cin >> S;
	
	int len = S.length();
	
	for(int i = 0; i < len; ++i)
	{
		for(int j = i - 1; j >= 0; --j)
		{
			if(S[j] == S[i])
			{
				dp[j][i] = dp[j + 1][i - 1];
			}
			else
			{
				dp[j][i] = min(min(dp[j + 1][i], dp[j][i - 1]), dp[j + 1][i - 1]) + 1;
			}
		}
	}
	
	cout << dp[0][len - 1] << endl;
	
	return 0;
}
