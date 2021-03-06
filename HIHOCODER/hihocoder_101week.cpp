#include <iostream>

using namespace std;

struct node
{
	int up;
	int down;
	int left;
	int right;
};

node head[101][101];
int n, m;
int array[101][101];

bool construct()
{
	head[0][0].up = head[0][0].down = head[0][0].left = head[0][0].right = 0;
	for(int i = 1; i <= m; i++)
	{
		head[0][i].up = 0;
		head[0][i].down = 0;
		head[0][i].left = i - 1;
		head[0][i].right = 0;
		head[0][i - 1].right = i;
		head[0][0].left = i;
		
		int pre = 0;
		for(int j = 1; j <= n; j++)
		{
			if(array[j][i] == 1)
			{
				head[j][i].up = pre;
				head[j][i].down = 0;
				head[j][i].left = i;
				head[j][i].right = i;
				head[pre][i].down = j;
				head[0][i].up = j;
				
				pre = j;
				
				for(int k = i - 1; k >= 1; k--)
				{
					if(array[j][k] != 0)
					{
						head[j][i].left = k;
						head[j][i].right = head[j][k].right;
						head[j][head[j][k].right].left = i;
						head[j][k].right = i;
						break;
					}
				}
			}
			else
			{
				head[j][i].up = j;
				head[j][i].down = j;
				head[j][i].left = i;
				head[j][i].right = i;
			}
		}
		if(pre == 0) return false;
	}
	return true;
}

void de(int y)//删除列y 
{
	head[0][head[0][y].left].right = head[0][y].right;
	head[0][head[0][y].right].left = head[0][y].left;
	
	int d_x = head[0][y].down;
	while(d_x)
	{
		int r_y = head[d_x][y].right;
		while(r_y != y)
		{
			head[head[d_x][r_y].up][r_y].down = head[d_x][r_y].down;
			head[head[d_x][r_y].down][r_y].up = head[d_x][r_y].up;
			r_y = head[d_x][r_y].right;
		}	
		d_x = head[d_x][y].down;
	}
	return;
}

void re(int y)
{
	head[0][head[0][y].left].right = y;
	head[0][head[0][y].right].left = y;
	int d_x = head[0][y].down;
	while(d_x)
	{
		int r_y = head[d_x][y].right;
		while(r_y != y)
		{
			head[head[d_x][r_y].up][r_y].down = d_x;
			head[head[d_x][r_y].down][r_y].up = d_x;
			r_y = head[d_x][r_y].right;
		}
		d_x = head[d_x][y].down;
	}
	return;
}

bool dfs()
{
	int r_0 = head[0][0].right;//r_0代表0行head[0][0]的右边 
	if(r_0 == 0) return true;
	else if(head[0][r_0].down == 0) return false;
	
	int d_r_0 = head[0][r_0].down;//d_r_0代表r_0列head[0][r_0]的下边
	
	de(r_0);
	while(d_r_0)
	{
		int r_r_0 = head[d_r_0][r_0].right;
		while(r_r_0 != r_0)
		{
			de(r_r_0);
			r_r_0 = head[d_r_0][r_r_0].right;
		}
		
		if(dfs()) return true;
		
		int l_r_0 = head[d_r_0][r_0].left;
		while(l_r_0 != r_0)
		{
			re(l_r_0);
			l_r_0 = head[d_r_0][l_r_0].left;
		}
		
		d_r_0 = head[d_r_0][r_0].down;
	}
	re(r_0);
	
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
