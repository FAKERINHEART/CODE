#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 20000;
int deep;
int stack[maxn];
bool mark[maxn];
vector<int> G[maxn];
vector<int> ans;

bool dfs(int u) 
{
	if(mark[u ^ 1]) 
	{
		return 0;
	}
	if(mark[u]) 
	{
		return 1;
	}
	
	mark[u] = 1;
	stack[deep++] = u;
	
	for(int i = 0; i < G[u].size(); i++)
	{
		if(!dfs(G[u][i])) 
		{
			return 0;
		}
	}
		
	return 1;
}

int main() 
{
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) 
	{
		int u, v;
		cin >> u >> v;
		
		--u;
		--v;
		
		G[u].push_back(v ^ 1);
		G[v].push_back(u ^ 1);
	}
	
	bool NIE = false;
	for(int i = 0; i < n * 2; i += 2)
	{
		if(!mark[i] && !mark[i + 1]) 
		{
			deep = 0;
			if(!dfs(i)) 
			{
				while(deep > 0) 
				{
					mark[stack[--deep]] = 0;
				}
				if(!dfs(i + 1)) 
				{ 
					NIE = true; 
					break; 
				}
			}
		}	
	}
		
	if(NIE)
	{
		cout << "NIE" << endl;
	}
	else 
	{
		for(int i = 0; i < n * 2; i += 2)
		{
			if(mark[i]) 
			{
				ans.push_back(i);
			} 
			else 
			{
				ans.push_back(i^1);
			}
		}
			
		sort(ans.begin(), ans.end());
		for(int i = 0; i < n; i++) 
		{
			cout << ans[i] + 1 << endl;
		}
	}
	
	return 0;
}
