#include <iostream>
#include <cstring>

using namespace std;

class Cube
{
public:
	int id;
	int coordinate[4];
	int neighbours[4][2];
	bool marked;
};

Cube _cube[100];
int max_positive[4];
int max_negitive[4];
int num_cube;

int SearchSub(int id)
{
	for(int i = 0; i < num_cube; i++) if(_cube[i].id == id) return i;
}

bool symmetric()
{
	for(int i = 0; i < num_cube; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			for(int k = 0; k < 2; k++)
			{
				if(_cube[i].neighbours[j][k])
				{
					int next = SearchSub(_cube[i].neighbours[j][k]);
					if(k == 0 && _cube[next].neighbours[j][1] != _cube[i].id || k == 1 && _cube[next].neighbours[j][0] != _cube[i].id) return false;
				} 
			}
		}
	}
	return true;
}

bool solid()
{
	for(int i = 0; i < num_cube; i++) if(!_cube[i].marked) return false;
	return true;
}

void dfs(int now)
{
	if(_cube[now].marked) return;
	_cube[now].marked = true;
	
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			if(_cube[now].neighbours[i][j])
			{
				int next = SearchSub(_cube[now].neighbours[i][j]);
				if(_cube[next].marked) continue;
				for(int k = 0; k < 4; k++) _cube[next].coordinate[k] = _cube[now].coordinate[k];
				if(!j)
				{
					_cube[next].coordinate[i]++;
					max_positive[i] = (_cube[next].coordinate[i] > max_positive[i])? _cube[next].coordinate[i]: max_positive[i];
				}
				else
				{
					_cube[next].coordinate[i]--;
					max_negitive[i] = (_cube[next].coordinate[i] < max_negitive[i])? _cube[next].coordinate[i]: max_negitive[i];
				}	
				dfs(next);
			}
		}
	}
	return;
}


int main()
{
	int num_case;
	cin >> num_case;
	for(int i = 0; i < num_case; i++)
	{
		cin >> num_cube;
		for(int j = 0; j < num_cube; j++)
		{
			cin >> _cube[j].id;
			for(int k = 0; k < 4; k++) 
			{
				cin >> _cube[j].neighbours[k][0] >> _cube[j].neighbours[k][1];
				_cube[j].coordinate[k] = 0;
			}
			_cube[j].marked = false;
		}
		
		memset(max_positive, 0, sizeof(int) * 4);
		memset(max_negitive, 0, sizeof(int) * 4);
		
		dfs(0);
		if(!solid() || !symmetric()) cout << "Inconsistent" << endl;
		else cout << (max_positive[0] - max_negitive[0] + 1) * (max_positive[1] - max_negitive[1] + 1) * (max_positive[2] - max_negitive[2] + 1) * (max_positive[3] - max_negitive[3] + 1) << endl;
	}
	return 0;
}
