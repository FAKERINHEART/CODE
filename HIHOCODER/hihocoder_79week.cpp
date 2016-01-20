#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
vector<int> node[20002];
bool visited[20002];
int level[20002];
int low[20002];
vector<int> stack;
bool inStacked[20002];
int dfsLevel;
int group[20002];

void dfs(int now)
{
	if(visited[now]) return;
	visited[now] = true;
	level[now] = low[now] = dfsLevel++;
	stack.push_back(now);
	inStacked[now] = true;
	for(int i = node[now].size() - 1; i >= 0; i--)
	{
		if(!visited[node[now][i]])
		{
			dfs(node[now][i]);
			low[now] = min(low[now], low[node[now][i]]);
		}
		else if(inStacked[node[now][i]]) low[now] = min(low[now], level[node[now][i]]);
	}
	if(level[now] == low[now])
	{
		for(int i = stack.size() - 1; i >= 0; i--)
		{
			inStacked[stack[i]] = false;
			group[stack[i]] = now;
			if(stack[i] == now) break;
			stack.pop_back();
		}
		stack.pop_back();
	}
	return;
}

int main()
{
	int numCase;
	cin >> numCase;
	while(numCase--)
	{
		cin >> N >> M;
		for(int i = 1; i <= 2 * N; i++) 
		{
			node[i].clear();
			level[i] = low[i] = -1;
		}
		memset(visited, false, sizeof(visited));
		memset(inStacked, false, sizeof(inStacked));
				
		int fi, se, val;
		while(M--)
		{
			cin >> fi >> se >> val;
			if(val)
			{
				node[fi + N].push_back(se);
				node[se + N].push_back(fi);
			}
			else
			{
				node[fi].push_back(se + N);
				node[se].push_back(fi + N);
			}
		}
		
		dfsLevel = 0;
		for(int i = 1; i <= N; i++) dfs(i);
		
		int i;
		for(i = 1; i <= N; i++)
		{
			if(group[i] == group[i + N])
			{
				cout << "No" << endl;
				break;
			}
		}
		if(i == N + 1) cout << "Yes" << endl;
	}
	return 0;
}
