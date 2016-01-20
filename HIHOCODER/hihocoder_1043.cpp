#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int dp[M], need[N + 1], value[N + 1];
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= N; i++) cin >> need[i] >> value[i];
	for(int i = 1; i <= N; i++) for(int j = need[i]; j < M; j++) dp[j] = max(dp[j], dp[j - need[i]] + value[i]);
	cout << dp[M - 1] << endl;
	return 0;
} 
