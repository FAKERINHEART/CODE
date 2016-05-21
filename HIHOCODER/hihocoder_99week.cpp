#include <iostream>
#include <cstring>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

class node
{
public:
	int x;
	int y;
	node(int one, int two){x = one; y = two;}
};

int num[3][8][8];
int substract[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};

void bfs(int index, int x0, int y0)
{
	num[index][x0][y0] = 0;
	deque<node> q;
	int x1, y1, x2, y2;
	q.push_back(node(x0, y0));
	while(!q.empty())
	{
		x1 = q.front().x;
		y1 = q.front().y;
		q.pop_front();
		for(int i = 0; i < 8; i++)
		{
			x2 = x1 + substract[i][0];
			y2 = y1 + substract[i][1];
			if(x2 >= 0 && x2 < 8 && y2 >= 0 && y2 < 8 && num[index][x2][y2] == -1)
			{
				num[index][x2][y2] = num[index][x1][y1] + 1;
				q.push_back(node(x2, y2));
			}
		}
	}
}

int main()
{
	int num_case, x0, y0;
	string s;
	
	cin >> num_case;
	while(num_case--)
	{
		for(int i = 0; i < 3; i++)
		{
			cin >> s;
			x0 = s[0] - 'A';
			y0 = s[1] - '1';
			for(int j = 0; j < 8; j++) for(int k = 0; k < 8; k++) num[i][j][k] = -1;
			bfs(i, x0, y0);
		}
		int ans = 1 << 30;
		for(int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				ans = min(ans, num[0][i][j] + num[1][i][j] + num[2][i][j]);	
			}	
		}		
		cout << ans << endl;
	}
	return 0;
}
