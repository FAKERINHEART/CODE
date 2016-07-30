#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct NODE
{
	int p;
	int q;
	int pt;
	int qt;
	vector<int> next; 	
};

int n;
NODE node[10001];

bool compare(int x, int y)
{
	return node[x].qt > node[y].qt;
}

void dfs(int parent, int now)
{
	int wallet = 200000000;
	int min_wallet = 200000000;
	
	vector<int> temp;
	for(int i = 0; i < node[now].next.size(); i++)
	{
		if(node[now].next[i] != parent)
		{
			dfs(now, node[now].next[i]);
			temp.push_back(node[now].next[i]);
		} 
	}
	
	sort(temp.begin(), temp.end(), compare);
	
	wallet -= node[now].p;
	if(min_wallet > wallet) min_wallet = wallet;
	wallet += node[now].q;
	
	for(int i = 0; i < temp.size(); i++)
	{
		wallet -= node[temp[i]].pt;
		if(min_wallet > wallet) min_wallet = wallet;
		wallet += node[temp[i]].qt;
	}
	
	node[now].pt = 200000000 - min_wallet;
	node[now].qt = wallet - min_wallet;
	
	return;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> node[i].p >> node[i].q;
		node[i].pt = node[i].qt = 0;
	}
	int a, b;
	for(int i = 1; i <= n - 1; i++)
	{
		cin >> a >> b;
		node[a].next.push_back(b);
		node[b].next.push_back(a);
	}
	dfs(0, 1);
	cout << node[1].pt << endl;
	return 0;
}
