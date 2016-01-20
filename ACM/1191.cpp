#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int dp[15][9][9][9][9];
int SUM[9][9];

int GET_SUM(int x1, int y1, int x2, int y2)
{
	return (SUM[x2][y2] - SUM[x2][y1 - 1] - SUM[x1 - 1][y2] + SUM[x1 - 1][y1 - 1]);
} 

int DP(int n, int x1, int y1, int x2, int y2)
{
	int temp;
	if(dp[n][x1][y1][x2][y2] >= 0) return dp[n][x1][y1][x2][y2];
	if(n == 1) 
	{
		temp = GET_SUM(x1, y1, x2, y2);
		return (dp[n][x1][y1][x2][y2] = temp * temp);
	}
	
	int MIN = 1 << 30;
	for(int i = x1; i < x2; i++)
	{
		temp = GET_SUM(x1, y1, i, y2);
		MIN = min(MIN, DP(n - 1, i + 1, y1, x2, y2) + temp * temp);
		temp = GET_SUM(i + 1, y1, x2, y2);
		MIN = min(MIN, DP(n - 1, x1, y1, i, y2) + temp * temp);
	}
	for(int i = y1; i < y2; i++)
	{
		temp = GET_SUM(x1, y1, x2, i);
		MIN = min(MIN, DP(n - 1, x1, i + 1, x2, y2) + temp * temp);
		temp = GET_SUM(x1, i + 1, x2, y2);
		MIN = min(MIN, DP(n - 1, x1, y1, x2, i) + temp * temp);
	}
	return (dp[n][x1][y1][x2][y2] = MIN);
}

int main()
{
	int n, num, total;
	while(cin >> n)
	{
		memset(SUM, 0, sizeof(SUM));
		for(int i = 0; i < 15; i++) for(int j = 0; j < 9; j++) for(int k = 0; k < 9; k++) for(int l = 0; l < 9; l++) for(int m = 0; m < 9; m++)
			dp[i][j][k][l][m] = -1;
		total = 0;
		
		for(int i = 1; i < 9; i++)
		{
			for(int j = 1; j < 9; j++)
			{
				cin >> num;
				total += num;
				SUM[i][j] = num + SUM[i][j - 1] + SUM[i - 1][j] - SUM[i - 1][j - 1]; 
			}
		}
		
		int ANS = DP(n, 1, 1, 8, 8);
		cout << fixed << setprecision(3) << sqrt(1.0 * ANS / n - 1.0 * total / n * total / n) << endl;
	}
	
	return 0;
} 
