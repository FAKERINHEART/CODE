#include <iostream>
#include <list>
#include <algorithm>
#include <deque>
#include <cstring>

using namespace std;

int N, M;
list<int> node[20001];
int weight[20001];
bool visited[20001]; 
int level[20001];
int low[20001];
int dfsLevel;
deque<int> stack;
bool inStacked[20001];// «∑Ò‘⁄’ªƒ⁄
int group[20001];

void dfs(int now)
{
	visited[now] = true;
	stack.push_back(now);
	inStacked[now] = true;
	level[now] = low[now] = dfsLevel++;
	list<int>::iterator iter = node[now].begin();
	while(iter != node[now].end())
	{
		if(!visited[*iter])
		{
			dfs(*iter);
			low[now] = min(low[now], low[*iter]);
		}
		else if(inStacked[*iter]) low[now] = min(low[now], level[*iter]);
		iter++;
	}
	if(level[now] == low[now])
	{
		for(int i = stack.size() - 1; i >= 0; i--)
		{
			inStacked[stack[i]] = false;
			group[stack[i]] = now;
			stack.pop_back();
			if(stack[i] == now) break;
			weight[now] += weight[stack[i]];
			weight[stack[i]] = 0;
		}
	}
	return;
}

int main()
{
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
	{
		cin >> weight[i];
		visited[i] = inStacked[i] = false;
		level[i] = low[i] = -1; 	
	}
	int fi, se;
	while(M--)
	{
		cin >> fi >> se;
		node[fi].push_back(se);
	}
	
	dfsLevel = 1;
	dfs(1);
	
	for(int i = 1; i <= N; i++)
	{
		list<int>::iterator iter = node[i].begin();
		while(iter != node[i].end())
		{
			if(group[i] != i || group[*iter] != *iter)
			{		
				if(group[i] != group[*iter]) node[group[i]].push_front(group[*iter]);	
				iter = node[i].erase(iter);
			}
			else iter++;
		}
	}

	//Õÿ∆À≈≈–Ú 
	int tempWeight[N + 1];
	int tempIndegree[N + 1];
	memset(tempIndegree, 0, sizeof(tempIndegree));
	for(int i = 1; i <= N; i++) 
	{
		tempWeight[i] = weight[i];
		list<int>::iterator iter = node[i].begin();
		while(iter != node[i].end())
		{
			tempIndegree[*iter]++;
			iter++;
		}
	}
	
	int MAX = -1;
	deque<int> queue;
	queue.push_back(1);
	while(!queue.empty())
	{
		int front = queue.front();
		list<int>::iterator iter = node[front].begin();
		while(iter != node[front].end())
		{
			tempWeight[*iter] = max(tempWeight[*iter], weight[*iter] + tempWeight[front]);
			tempIndegree[*iter]--;
			if(!tempIndegree[*iter]) queue.push_back(*iter);
			iter++;
		}
		if(!node[front].size()) MAX = max(MAX, tempWeight[front]);
		queue.pop_front();
	}
	cout << MAX << endl;
	return 0;
}
