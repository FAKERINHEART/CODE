#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;





int main()
{
	int N, num;
	cin >> N;
	int num25[N][N][2];
	int dp[N][N][2];
	memset(num25, 0, sizeof(num25));
	memset(dp, 0, sizeof(dp));
	
	for(int i = 0; i < N; i++) 
	{
		for(int j = 0; j < N; j++) 
		{
			cin >> num;
			if(!num) num25[i][j][0] = num25[i][j][1] = 1 << 20;
			else
			{
				while(num % 2 == 0)
				{
					num25[i][j][0]++;
					num /= 2;
				}
				while(num % 5 == 0)
				{
					num25[i][j][1]++;
					num /= 5;
				}
			}
		}
	}
	
	int tmp0, tmp1;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(!i && !j) 
			{
				dp[i][j][0] = num25[i][j][0];
				dp[i][j][1] = num25[i][j][1];
			}
			else
			{
				tmp0 = tmp1 = 1 << 20;
				if(i)
				{
					tmp0 = min(tmp0, dp[i - 1][j][0]);
					tmp1 = min(tmp1, dp[i - 1][j][1]);
				} 
				if(j)
				{
					tmp0 = min(tmp0, dp[i][j - 1][0]);
					tmp1 = min(tmp1, dp[i][j - 1][1]);	
				}
				dp[i][j][0] = tmp0 + num25[i][j][0];
				dp[i][j][1] = tmp1 + num25[i][j][1];
			}
		}
	}
	cout << min(dp[N - 1][N - 1][0], dp[N - 1][N - 1][1]) << endl;
	return 0;
}
