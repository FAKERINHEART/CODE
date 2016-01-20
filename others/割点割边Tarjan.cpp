#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>

//Tarjan�㷨 
using namespace std;

int N, M;
vector<int> node[20001];//�߹�ϵ 
bool visited[20001];//dfs�Ƿ���ʹ� 
int level[20001];//dfs������������ 
int parent[20001];//dfsĸ�׽ڵ� 
int low[20001];//dfs�ж��ڸýڵ�Ļرߵ���һ�˽ڵ����С������� 
int dfsLevel;//dfs���� 

set<int> tarjanNode;//��� 
vector<pair<int, int> > tarjanEdge;//���

void dfs(int now)
{
	int numChildren = 0; //�ýڵ����Ϊ0
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
