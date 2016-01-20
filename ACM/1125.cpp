#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, a, b, c;
	int dp[101][101];
	while(cin >> n)
	{
		if(!n) break;
		for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dp[i][j] = 20;
		for(int i = 1; i <= n; i++)
		{
			cin >> a;
			for(int j = 0; j < a; j++)
			{
				cin >> b >> c;
				dp[i][b] = c;
			}
		}
		for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) 
			if(i - j && dp[i][j] > dp[i][k] + dp[k][j]) dp[i][j] = dp[i][k] + dp[k][j];
		
		int max_time;
		int min_time = 20, sub_min_time = -1;
		for(int i = 1; i <= n; i++)
		{
			max_time = -1;
			for(int j = 1; j <= n; j++)	if(i - j) max_time = max(max_time, dp[i][j]);
			if(max_time < min_time)
			{
				min_time = max_time;
				sub_min_time = i;
			}
		}
		if(min_time < 20) cout << sub_min_time << " " << min_time << endl;
		else cout << "disjoint" << endl;
		
	}
	return 0;
} 
