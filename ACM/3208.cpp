#include <iostream>
#include <cstring> 

using namespace std;
///////////////////////////0, 1, 2, 3, 4, 5, 6, 7, 8, 9
int statusChange[4][10] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, //状态表示当前数的末尾位数没有6, 再加6则跳到状态1，加其他还是原状态0 
						   0, 0, 0, 0, 0, 0, 2, 0, 0, 0, //状态表示当前数的末尾位数有一个6, 再加6则跳到状态2，加其他跳到状态0  
						   0, 0, 0, 0, 0, 0, 3, 0, 0, 0, //状态表示当前数的末尾位数有连续的2个6, 再加6则跳到状态3，加其他跳到状态0 
						   3, 3, 3, 3, 3, 3, 3, 3, 3, 3}; //状态表示当前数的末尾位数或数中位数已经有三个连续6, 加任何数字都还是原状态3
long long dp[15][4];
//设整个数字一共是k位，前面(k-i)位的状态是j，则dp[i][j]表示的是在前面(k-i)位的状态为j的情况下,剩下的i位能组成多少个满足666的数字
//dp[i][j]可以根据第i位不同数字l进行叠加，例如当第i为的数字为l=3时，则前面(k-i)的j状态转化成了(k-i+1)的statusChange[j][3]状态，
//因此，dp[i][j]的个数是包括dp[i-1][statusChange[j][3]]的。当l取不同值时，可得dp[i][j] += dp[i-1][statusChange[j][l]]

int main()
{
	memset(dp, 0, sizeof(dp));
	dp[0][3] = 1;
	for(int i = 1; i < 15; i++) for(int j = 0; j < 4; j++) for(int k = 0; k <= 9; k++) dp[i][j] += dp[i - 1][statusChange[j][k]];
	
	int T, n;
	int len, status;
	long long ans;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		cin >> n;
		len = 0;
		status = 0;
		ans = 0;
		while(dp[len][0] < n) len++;
		for(int j = len - 1; j >= 0; j--)
		{
			int l;
			for(l = 0; l <= 9; l++)
			{
				if(dp[j][statusChange[status][l]] < n) n-= dp[j][statusChange[status][l]]; // 当j+1是l时一共有几种取法 
				else break;
			}
			ans = ans * 10 + l;
			status = statusChange[status][l];
		}
		cout << ans << endl;
	}
	
	return 0;
}
