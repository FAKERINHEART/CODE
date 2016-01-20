#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N, M;
class Node
{
public:
	vector<int> Edge;
	vector<int> orderEdge;//边的输入下标顺序 
	bool visited;
	int level;
	int low;
	int parent;
};
Node node[20001];
int dfsLevel;
int numTarjanNode;

int group[100001];
vector<int> stack;

void dfs(int now)
{
	int numChildren = 0;
	node[now].visited = true;
	node[now].level = node[now].low = dfsLevel++;
	for(int i = 0; i < node[now].Edge.size(); i++)
	{
		if(group[node[now].orderEdge[i]] != -1) continue;
		stack.push_back(node[now].orderEdge[i]);
		group[node[now].orderEdge[i]] = node[now].orderEdge[i];
		
		if(!node[node[now].Edge[i]].visited)
		{
			numChildren++;
			node[node[now].Edge[i]].parent = now;
			dfs(node[now].Edge[i]);
			node[now].low = min(node[now].low, node[node[now].Edge[i]].low);
			
			if(node[now].parent == -1 && numChildren > 1 || node[now].parent != -1 && node[now].level <= node[node[now].Edge[i]].low)
			{
				numTarjanNode++;
				int valueMin = 100002;
				for(int j = stack.size() - 1; j >= 0; j--)
				{
					valueMin = min(valueMin, stack[j]);
					if(node[now].orderEdge[i] == stack[j]) break;
				}
				for(int j = stack.size() - 1; j >= 0; j--)
				{
					group[stack[j]] = valueMin;
					if(node[now].orderEdge[i] == stack[j]) break;
					stack.pop_back();
				}
				stack.pop_back();
			} 
		}
		else if(node[now].parent != node[now].Edge[i]) node[now].low = min(node[now].low, node[node[now].Edge[i]].level);
	}
	return;
}

int main()
{
	cin >> N >> M;
	int fi, se;
	for(int i = 1; i <= M; i++)
	{
		cin >> fi >> se;
		node[fi].Edge.push_back(se);
		node[se].Edge.push_back(fi);
		node[fi].orderEdge.push_back(i);
		node[se].orderEdge.push_back(i);
		
		group[i] = -1;
	}
	for(int i = 1; i <= N; i++)
	{
		node[i].visited = false;
		node[i].level = node[i].low = node[i].parent = -1;
	}
	
	dfsLevel = 0;
	numTarjanNode = 0;
	dfs(1);
	
	int valueMin = 100002;
	for(int j = stack.size() - 1; j >= 0; j--) valueMin = min(valueMin, stack[j]);
	for(int j = stack.size() - 1; j >= 0; j--)
	{
		group[stack[j]] = valueMin;
		stack.pop_back();
	}
	
	
	cout << numTarjanNode + 1 << endl;
	for(int i = 1; i <= M; i++) cout << group[i] << " ";
	cout << endl;
	return 0;
}
