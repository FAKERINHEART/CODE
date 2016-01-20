#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[32][32];//表示i长度的数字有j个0,不包括前导0 

int analysis(int num)
{
	int bit[32];
	int len = 0;
	int ret = 0, cnt = 0;
	int down;
	while(num)
	{
		bit[++len] = num % 2;
		num /= 2;
	}
	
	for(int i = len; i >= 1; i--)
	{
		if(!bit[i]) cnt++;
		else
		{
			if(i == len) ret += analysis((1 << (i - 1)) - 1);
			else
			{
				if(len % 2 && (i - 1 + cnt + 1) <= len / 2 || !(len % 2) && (i - 1 + cnt + 1) < len / 2) break;
				if(len % 2) down = len / 2 + 1 - cnt - 1;
				else down = len / 2 - cnt - 1;
				for(int j = down; j <= i - 1; j++) ret += dp[i - 1][j];
			}
		}
	}
	if(len % 2 && cnt > len / 2 || !(len % 2) && cnt >= len / 2) ret++;
	return ret;
}

int main()
{
	memset(dp, 0, sizeof(dp));
	
	dp[0][0] = 1;
	for(int i = 1; i <= 31; i++)
	{
		dp[i][0] = 1;
		for(int j = 1; j <= i; j++) dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
	}
	int Start, Finish;
	cin >> Start >> Finish;
	if(Start > Finish) swap(Start, Finish);
	cout << analysis(Finish) - analysis(Start - 1) << endl;
	return 0;
}
