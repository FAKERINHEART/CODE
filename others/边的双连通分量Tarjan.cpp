#include <iostream>
#include <vector>
#include <algorithm>

//Tarjan算法 
using namespace std;

int N, M;
vector<int> node[20001]; 
bool visited[20001];
int parent[20001];
int level[20001];
int low[20001];
int dfsLevel;
vector<int> stack;//dfs栈 
int numTarjanEdge;//割边数量 
int group[20001];//连通分量编号 

void dfs(int now)
{
	visited[now] = true;
	stack.push_back(now); 
	level[now] = low[now] = dfsLevel++;
	for(int i = 0; i < node[now].size(); i++)
	{
		if(!visited[node[now][i]])
		{
			parent[node[now][i]] = now;
			dfs(node[now][i]);
			low[now] = min(low[now], low[node[now][i]]);
		}
		else if(parent[now] != node[now][i]) low[now] = min(low[now], level[node[now][i]]);
	}
	if(level[now] == low[now])
	{
		numTarjanEdge++;
		int valueMin = 20001;
		for(int i = stack.size() - 1; i >= 0; i--) 
		{
			valueMin = min(valueMin, stack[i]);
			if(stack[i] == now) break;
		}
		for(int i = stack.size() - 1; i >= 0; i--)
		{
			group[stack[i]] = valueMin;
			if(stack[i] == now) break;
			stack.pop_back();
		}
		stack.pop_back();
	}
	return;
}

int main()
{
	cin >> N >> M;
	int fi, se;
	while(M--)
	{
		cin >> fi >> se;
		node[fi].push_back(se);
		node[se].push_back(fi);
	}
	for(int i = 1; i <= N; i++)
	{
		visited[i] = false;
		parent[i] = -1;
		level[i] = -1;
		low[i] = -1;
	}
	
	dfsLevel = 0;
	numTarjanEdge = 0;
	dfs(1);
	cout << numTarjanEdge << endl;
	for(int i = 1; i <= N; i++) cout << group[i] << " ";
	cout << endl;
	return 0;
}
