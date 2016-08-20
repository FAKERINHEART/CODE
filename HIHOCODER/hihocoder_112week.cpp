#include <iostream>
#include <vector>
#include <string>

using namespace std;

class edge
{
public:
	long long next;
	long long value;
	edge(long long x, long long y):next(x), value(y){}
};

vector<edge> E[100001];
long long N, M;
long long level[100001];
long long node[100001];
long long path[100001]; 
long long total;
long long root = 1;

void dfs(long long now)
{
	node[now] = 1;
	long long temp_next, temp_value;
	for(long long i = 0; i < E[now].size(); ++i)
	{
		temp_next = E[now][i].next;
		temp_value = E[now][i].value;
		if(level[temp_next] == 0)
		{
			level[temp_next] = level[now] + 1;
			path[temp_next] = temp_value;
			dfs(temp_next);
			node[now] += node[temp_next];
			total += temp_value * node[temp_next] * (N - node[temp_next]);
		}
	}
	return;
}

void edit(long long x, long long y, long long key)
{
	if(level[x] < level[y])
	{
		long long temp = x;
		x = y;
		y = temp;
	}
	
	long long delta = key - path[x];
	total += delta * node[x] * (N - node[x]);
	path[x] = key;
	
	return;
}

int main()
{	
	long long u, v, k;
	cin >> N >> M;
	
	for(long long i = 1; i <= N - 1; ++i)
	{
		cin >> u >> v >> k;
		E[u].push_back(edge(v, k));
		E[v].push_back(edge(u, k));
	} 
	level[root] = 1;
	dfs(root);
	
	string describe;
	for(long long i = 1; i <= M; ++i)
	{
		cin >> describe;
		if(describe == "EDIT")
		{
			cin >> u >> v >> k;
			edit(u, v, k);
		}
		else if(describe == "QUERY")
		{
			cout << total << endl;
		}
	}
	
	return 0;
}
