#include <iostream>

using namespace std;

int edge[13];
int p[1 << 13];
int count;

void dfs(int now, int unvisited)
{
	if(!unvisited) count += (edge[now] & 1);
	else
	{
		int rest = unvisited & edge[now];
		int temp;
		while(rest)
		{
			temp = rest & (-rest);
			dfs(p[temp], unvisited - temp);
			rest -= temp;
		}
	}
	return;
}

int main()
{
	int n, m, one, two;
	cin >> n >> m;
	for(int i = 0; i < n; i++) p[1 << i] = i + 1;
	for(int i = 0; i < m; i++)
	{
		cin >> one >> two;
		edge[one] |= (1 << (two - 1));
	}
	dfs(1, (1 << n) - 2);
	cout << count << endl;
	return 0;
}
