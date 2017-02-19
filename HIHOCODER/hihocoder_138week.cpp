#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,T,S;
int a[4][4];

struct node{
	int b;
	int c;
}p[1005];

bool cmp(node x,node y)
{
	if(x.b!=y.b) return x.b>y.b;
	else return x.c>y.c;
}

vector<int> b;
vector<int> c;
vector<int> vec1;
vector<int> vec2;

int sta[4];
int ans;
int ansf;


void dfs(int x)
{
	if(x == n)
	{
		vec1.clear();
		vec2.clear();
		int flag=1;
		
		for(int i = 0; i < n; ++i)
		{
			int flag2 = 0;
			for(int j = 0; j < m; ++j)
			{
				if((1 << j) & sta[i])
				{
					vec1.push_back(a[i][j]);
				}
				else
				{
					flag2 = 1;
					vec2.push_back(a[i][j]);
				}
			}
			if(flag2 == 0)
			{
				flag = 0;
			}
		} 
		
		if(n == 0) flag = 0;
		if(vec1.size() > b.size() || vec2.size() > c.size()) return;
		sort(vec1.begin(), vec1.end());
		reverse(vec1.begin(), vec1.end());
		
		int temps=0;
		for(int i = 0; i < vec1.size(); ++i)
		{
			temps += vec1[i] * b[i];
		}

		if(temps < S)
		{
			return;
		}
		else
		{
			sort(vec2.begin(), vec2.end());
			reverse(vec2.begin(), vec2.end());
			
			int ret = 0;
			for(int i=0; i < vec2.size(); ++i)
			{
				ret += vec2[i] * c[i];
			}
			if(ret > ans)
			{
				ans = ret;
				if(flag == 1) ansf=1;
				else ansf=0;
			}
			else if(ret == ans && flag == 1)
			{
				ansf = 1;
			}
		}
		return;
	}	
	
	for(int i = 0; i < (1 << m); ++i)
	{
		sta[x] = i;
		dfs(x + 1);	
	}
}

int main()
{
	int Q;
	cin >> Q;
	while(Q--)
	{
		b.clear();
		c.clear();
		
		cin >> n >> m >> T >> S;
		
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				cin >> a[i][j];
			}
		}

		for(int i = 0; i < T; ++i)
		{
			cin >> p[i].b;
		}
		for(int i = 0; i < T; ++i)
		{
			cin >> p[i].c;
		}
		sort(p, p + T, cmp);
		for(int i = 0; i < T; ++i)
		{
			if(p[i].b==0)
			{
				c.push_back(p[i].c);
			}
			else if(p[i].c==0)
			{
				b.push_back(p[i].b);
			}
		}
		
		ans = -1;
		ansf = 0;
		dfs(0);
		
		if(ans == -1)
		{
			cout << "Not Exist" << endl;
		}
		else
		{
			cout << ans << endl;
			if(ansf == 1)
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
	}
	
	return 0; 
}
