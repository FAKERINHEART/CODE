#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<int> v[6001];
int dp[6001][2];

void dfs(int now)
{
	for(int i = 0; i < v[now].size(); i++)
	{
		dfs(v[now][i]);
		dp[now][1] += dp[v[now][i]][0];
		dp[now][0] += max(dp[v[now][i]][0], dp[v[now][i]][1]);
	}
}

int main()
{
	memset(dp, 0, sizeof(dp));
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> dp[i][1];
	int n1, n2, root = 1;
	while(cin >> n1 >> n2)
	{
		if(!n1 && !n2) break;
		v[n2].push_back(n1);
		if(n1 == root) root = n2;
	}
	dfs(root);
	cout << max(dp[root][0], dp[root][1]) << endl;
	return 0;
}
