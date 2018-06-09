#include <iostream>
#include <algorithm>

using namespace std;

int dp[201][201];

int solve(int s,int e)
{
	if (s >= e)
	{
		return 0;
	}
	
	if (dp[s][e])
	{
		return dp[s][e];
	}
	
	int tmp = 1 << 30;

	for (int i = s; i <= e; ++i)
	{
		tmp = min(tmp, i + max(solve(i + 1, e), solve(s, i - 1)));
	}
	
	dp[s][e] = tmp;
	
	return tmp;
}

int main()
{
	int N;
	cin >> N;
	
	cout << solve(1, N) << endl;
	
	return 0;
}
