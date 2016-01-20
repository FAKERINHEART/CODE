#include <iostream>
#include <string>
#include <cstring>
#include <deque>

using namespace std;

int width;
int height;
int path[100][2];//x: 0, y: 1
int length_path;
bool wall[100][100][4];//左0, 上1, 右2, 下3 
bool visited[100][100];//在bfs时有没有已经被遍历过 
int count_path_searching[100][100];
int length_path_searching[100][100];

void bfs()
{
	int x = 0, y = 0, temp_x, temp_y;
	deque<int> _dq;
	visited[y][x] = true;
	count_path_searching[y][x] = 1;
	length_path_searching[y][x] = 0;
	_dq.push_back(y * width + x);
	while(!_dq.empty())
	{
		deque<int>::const_iterator iter = _dq.begin();
		x = (*iter) % width;
		y = (*iter) / width;
		if(x == path[length_path - 1][0] && y == path[length_path - 1][1]) break;
		for(int i = 0; i < 4; i++)
		{
			switch(i)
			{
				case 0: temp_x = x - 1; temp_y = y; break;
				case 1: temp_x = x; temp_y = y + 1; break;
				case 2: temp_x = x + 1; temp_y = y; break;
				case 3: temp_x = x; temp_y = y - 1; break;
			}
			if(temp_x >= 0 && temp_x < width && temp_y >= 0 && temp_y < height && !wall[y][x][i])
			{
				if(!visited[temp_y][temp_x])
				{
					visited[temp_y][temp_x] = true;
					count_path_searching[temp_y][temp_x] = count_path_searching[y][x];
					length_path_searching[temp_y][temp_x] = length_path_searching[y][x] + 1;
					_dq.push_back(temp_y * width + temp_x);
				}
				else if(length_path_searching[temp_y][temp_x] == length_path_searching[y][x] + 1) count_path_searching[temp_y][temp_x] += count_path_searching[y][x];
			}
		}
		_dq.pop_front();
	}
	_dq.clear();
	return; 
}

bool check()
{
	int temp_x, temp_y;
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			for(int k = 0; k < 4; k++)
			{
				if(wall[i][j][k])
				{
					wall[i][j][k] = false;
					switch(k)
					{
						case 0: wall[i][j - 1][2] = false; break;
						case 1: wall[i + 1][j][3] = false; break;
						case 2: wall[i][j + 1][0] = false; break;
						case 3: wall[i - 1][j][1] = false; break; 
					}
					memset(visited, 0, sizeof(visited));
					memset(count_path_searching, 0, sizeof(count_path_searching));
					memset(length_path_searching, 0, sizeof(length_path_searching));
					bfs();
					if(length_path_searching[path[length_path - 1][1]][path[length_path - 1][0]] == length_path && count_path_searching[path[length_path - 1][1]][path[length_path - 1][0]] == 1) return false;
					else 
					{
						wall[i][j][k] = true;
						switch(k)
						{
							case 0: wall[i][j - 1][2] = true; break;
							case 1: wall[i + 1][j][3] = true; break;
							case 2: wall[i][j + 1][0] = true; break;
							case 3: wall[i - 1][j][1] = true; break; 
						}
					}
				}				
			}
		}
	}
	return true;
}

 
int main()
{
	int num_case, num_pair_wall;
	string str_path;
	cin >> num_case;
	for(int i = 0; i < num_case; i++)
	{
		memset(wall, 0, sizeof(wall));
		cin >> width >> height >> str_path >> num_pair_wall;
		length_path = str_path.length();
		int temp_x = 0, temp_y = 0;
		for(int j = 0; j < length_path; j++)
		{
			switch(str_path[j])
			{
				case 'U': temp_y++; break;
				case 'D': temp_y--; break;
				case 'R': temp_x++; break;
				case 'L': temp_x--; break;
			}
			path[j][0] = temp_x;
			path[j][1] = temp_y;
		}
		int x1, y1, x2, y2;
		for(int j = 0; j < num_pair_wall; j++)
		{
			cin >> x1 >> y1 >> x2 >> y2;
			if(x1 == x2)
			{
				if(y1 > y2)
				{
					wall[y1][x1][3] = true;
					wall[y2][x2][1] = true;
				}
				else
				{
					wall[y1][x1][1] = true;
					wall[y2][x2][3] = true;
				}
			}
			else
			{
				if(x1 > x2)
				{
					wall[y1][x1][0] = true;
					wall[y2][x2][2] = true;
				}
				else
				{
					wall[y1][x1][2] = true;
					wall[y2][x2][0] = true;
				}
			}
		}
		memset(visited, 0, sizeof(visited));
		memset(count_path_searching, 0, sizeof(count_path_searching));
		memset(length_path_searching, 0, sizeof(length_path_searching));
		bfs();
		if(length_path_searching[path[length_path - 1][1]][path[length_path - 1][0]] != length_path || count_path_searching[path[length_path - 1][1]][path[length_path - 1][0]] > 1) cout << "INCORRECT" << endl;
		else
		{
			if(!check()) cout << "INCORRECT" << endl;
			else cout << "CORRECT" << endl;
		}
	}
	return 0;
}
