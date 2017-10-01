#include <iostream>
#include <string>

using namespace std;

int n;
int mask[40];
bool visited[40];

int dfs(int now, int m)
{
	visited[now] = true;
	
	m = m | mask[now];
	
	int ret = 0;
	
	for(int i = 0; i < n; ++i)
	{
		if(visited[i] == true || (m & mask[i])) continue;
		
		ret = max(ret, dfs(i, m));
	}
	
	visited[now] = false;
	
	return ret + 1;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		
		for(int j = 0; j < str.length(); ++j)
		{
			mask[i] = mask[i] | (1 << (str[j] - 'a'));
		}
	}
	
	int ans = 0;
	
	for(int i = 0; i < n; ++i)
	{
		ans = max(ans, dfs(i, 0));
		visited[i] = true;
	}
	
	cout << ans << endl;
	
	return 0;	
} 
