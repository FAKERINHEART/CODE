#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long dp[11][10]; //表示长度为i(第一维)的数字上共有几个j(第二维),包括前导的0 
long long bit[11]; //10的i次方 

long long count(long long up, int num)
{
	int len = 0;
	int _up[11];
	long long ret = 0, cnt = 0;
	while(up)
	{
		_up[++len] = up % 10;
		up /= 10;
	}
	
	for(int i = len; i >= 1; i--)
	{
		if(!num && i == len)
		{
			ret += dp[i - 1][num] * (_up[i] - 1);
			ret += count(bit[i - 1] - 1, num);	
		}	
		else ret += dp[i - 1][num] * _up[i];
		
		ret += cnt * _up[i] * bit[i - 1];
		
		if(num || i != len)
		{
			if(_up[i] > num) ret += bit[i - 1];
			else if(_up[i] == num) cnt++;
		}
	}
	
	return (ret + cnt);
}

int main()
{
	bit[0] = 1; 
	for(int i = 1; i <= 10; i++) bit[i] = bit[i - 1] * 10;
	
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= 10; i++) for(int j = 0; j <= 9; j++) dp[i][j] = 10 * dp[i - 1][j] + bit[i - 1];
	
	long long a, b;
	while(cin >> a >> b)
	{
		if(a == -1 && b == -1) break;
		if(a > b) swap(a, b);
		if(a >= 1) cout << count(b, 0) - count(a - 1, 0) << endl;
		else cout << count(b, 0) + 1 << endl;
	} 
	return 0;
}
