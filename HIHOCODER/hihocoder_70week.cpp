#include <iostream>

using namespace std;

long long N, M;
long long cnt = 0;

void dfs(long long now, long long sum, long long multi)
{
	if(sum == N)
	{
		if(multi % M == 0) cnt++;
	}
	else for(long long i = now + 1; i <= N - sum; i++) dfs(i, sum + i, multi * i);
	return;
}

int main()
{
	cin >> N >> M;
	dfs(0, 0, 1);
	cout << cnt << endl;
	return 0;
}
