#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>

//Tarjan算法 
using namespace std;

int N, M;
vector<int> node[20001];//边关系 
bool visited[20001];//dfs是否访问过 
int level[20001];//dfs遍历各点的序号 
int parent[20001];//dfs母亲节点 
int low[20001];//dfs中对于该节点的回边的另一端节点的最小遍历序号 
int dfsLevel;//dfs次序 

set<int> tarjanNode;//割点 
vector<pair<int, int> > tarjanEdge;//割边

void dfs(int now)
{
	int numChildren = 0; //该节点个数为0
	visited[now] = true;
	level[now] = low[now] = dfsLevel++;
	for(int i = 0; i < node[now].size(); i++)
	{
		if(!visited[node[now][i]])
		{
			numChildren++;
			parent[node[now][i]] = now;
			dfs(node[now][i]);
			low[now] = min(low[now], low[node[now][i]]);

			if(parent[now] == -1 && numChildren > 1) tarjanNode.insert(now); 
			else if(parent[now] != -1 && level[now] <= low[node[now][i]]) tarjanNode.insert(now);
			
			if(level[now] < low[node[now][i]]) 
			{
				if(now < node[now][i]) tarjanEdge.push_back(make_pair(now, node[now][i]));
				else tarjanEdge.push_back(make_pair(node[now][i], now));
			}
		}
		else if(parent[now] != node[now][i]) low[now] = min(low[now], level[node[now][i]]);
	}
	return;
}

bool cmp(pair<int, int> x, pair<int, int> y)
{
	if(x.first == y.first) return x.second < y.second;
	return x.first < y.first;
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
		level[i] = -1;
		parent[i] = -1;
		low[i] = -1;
	}
	dfsLevel = 1;
	dfs(1);
	
	if(!tarjanNode.size()) cout << "Null" << endl;
	else
	{
		set<int>::const_iterator iter = tarjanNode.begin();
		while(iter != tarjanNode.end())
		{
			cout << *iter << " ";
			iter++;
		}
		cout << endl;
	}
	
	sort(tarjanEdge.begin(), tarjanEdge.end(), cmp);
	for(int i = 0; i < tarjanEdge.size(); i++) cout << tarjanEdge[i].first << " " << tarjanEdge[i].second << endl;
	
	tarjanNode.clear();
	tarjanEdge.clear();
	return 0;
}
