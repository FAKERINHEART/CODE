#include <iostream>
#include <vector>

using namespace std;

struct node
{
	int up;
	int down;
	int left;
	int right;
};

class p
{
public:
	p(int one, int two){x = one; y = two;}
	int x;
	int y;	
};

node head[101][101];
int n, m;
int array[101][101];

bool construct()
{
	head[0][0].up = head[0][0].down = head[0][0].left = head[0][0].right = -1;
	for(int i = 1; i <= m; i++)
	{
		head[0][i].up = head[0][i].down = head[0][i].right = -1;
		head[0][i].left = i - 1;
		head[0][i - 1].right = i;
		
		int pre = 0;
		for(int j = 1; j <= n; j++)
		{
			if(array[j][i] == 1)
			{
				head[j][i].up = pre;
				head[pre][i].down = j;
				head[j][i].down = head[j][i].left = head[j][i].right = -1;
				pre = j;
				
				for(int k = i - 1; k >= 1; k--)
				{
					if(array[j][k] != 0)
					{
						head[j][k].right = i;
						head[j][i].left = k;
						break;
					}
				}
			}
			else
			{
				head[j][i].up = head[j][i].down = head[j][i].left = head[j][i].right = -1;
			}
		}
		if(pre == 0) return false;
	}
	return true;
}

vector<p> de(int x, int y)
{
	vector<p> v;
	int r_y = y;
	while(head[x][r_y].left != -1) r_y = head[x][r_y].left;
	while(r_y != -1)
	{ 
		if(head[0][r_y].down != -1) head[head[0][r_y].down][r_y].up = head[0][r_y].up;
		if(head[0][r_y].left != -1) head[0][head[0][r_y].left].right = head[0][r_y].right;
		if(head[0][r_y].right != -1) head[0][head[0][r_y].right].left = head[0][r_y].left;
		v.push_back(p(0, r_y));
		
		int d_x = head[0][r_y].down;
		while(d_x != -1)
		{
			int r_r_y = r_y;
			while(head[d_x][r_r_y].left != -1) r_r_y = head[d_x][r_r_y].left;
			
			while(r_r_y != -1)
			{
				if(head[d_x][r_r_y].up != -1) head[head[d_x][r_r_y].up][r_r_y].down = head[d_x][r_r_y].down;
				if(head[d_x][r_r_y].down != -1) head[head[d_x][r_r_y].down][r_r_y].up = head[d_x][r_r_y].up;
				if(head[d_x][r_r_y].left != -1) head[d_x][head[d_x][r_r_y].left].right = head[d_x][r_r_y].right;
				if(head[d_x][r_r_y].right != -1) head[d_x][head[d_x][r_r_y].right].left = head[d_x][r_r_y].left;
				v.push_back(p(d_x, r_r_y));
				r_r_y = head[d_x][r_r_y].right;
			}
			d_x = head[d_x][r_y].down; 
		}		
		r_y = head[x][r_y].right;
	}
	return v;
}

void re(vector<p> v)
{
	for(int i = v.size() - 1; i >= 0; i--)
	{
		if(head[v[i].x][v[i].y].up != -1) head[head[v[i].x][v[i].y].up][v[i].y].down= v[i].x;
		if(head[v[i].x][v[i].y].down != -1) head[head[v[i].x][v[i].y].down][v[i].y].up= v[i].x;
		if(head[v[i].x][v[i].y].left != -1) head[v[i].x][head[v[i].x][v[i].y].left].right = v[i].y;
		if(head[v[i].x][v[i].y].right != -1) head[v[i].x][head[v[i].x][v[i].y].right].left = v[i].y;
	}
	return;
}

bool dfs()
{
	int r_0 = head[0][0].right;//r_0代表0行head[0][0]的右边 
	if(r_0 == -1) return true;
	else if(head[0][r_0].down == -1) return false;
	int d_r_0 = head[0][r_0].down;//d_r_0代表r_0列head[0][r_0]的下边
	while(d_r_0 != -1)
	{
		vector<p> v = de(d_r_0, r_0);
		
		bool ret = dfs();
		re(v);
		v.clear();
		
		if(ret) return true;		
		d_r_0 = head[d_r_0][r_0].down;
	}
	return false;
}

int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		cin >> n >> m;
		for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> array[i][j];
		if(construct() && dfs()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
