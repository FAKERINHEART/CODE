#include <iostream>
#include <cstring>

using namespace std;

char board[10][15];
bool visited[10][15];
int num_remained;
int sub_x_max, sub_y_max;
int score;
char color;

int dfs(int x, int y)
{
	int area_max = 1;
	visited[x][y] = true;
	if(y > 0 && !visited[x][y - 1] && board[x][y] == board[x][y - 1]) area_max += dfs(x, y - 1);
	if(x > 0 && !visited[x - 1][y] && board[x][y] == board[x - 1][y]) area_max += dfs(x - 1, y);
	if(y < 14 && !visited[x][y + 1] && board[x][y] == board[x][y + 1]) area_max += dfs(x, y + 1);
	if(x < 9 && !visited[x + 1][y] && board[x][y] == board[x + 1][y]) area_max += dfs(x + 1, y);
	return area_max;
}

int Search_Max_Area_Sub()
{
	memset(visited, 0, sizeof(visited));
	int area_max = 0, area;
	for(int j = 0; j < 15; j++)	
		for(int i = 0; i < 10; i++)	
			if(!visited[i][j] && board[i][j] != ' ') 
			{
				area = dfs(i, j);
				if(area > area_max)
				{
					area_max = area;
					sub_x_max = i;
					sub_y_max = j;
				}
			}
	return area_max;
}

void Delete_Max_Area(int i, int j)
{
	visited[i][j] = true;
	if(j > 0 && !visited[i][j - 1] && board[i][j] == board[i][j - 1]) Delete_Max_Area(i, j - 1);
	if(i > 0 && !visited[i - 1][j] && board[i][j] == board[i - 1][j]) Delete_Max_Area(i - 1, j);
	if(j < 14 && !visited[i][j + 1] && board[i][j] == board[i][j + 1]) Delete_Max_Area(i, j + 1);
	if(i < 9 && !visited[i + 1][j] && board[i][j] == board[i + 1][j]) Delete_Max_Area(i + 1, j);
	board[i][j] = ' ';
	return;
}

void Shift_Area()
{
	bool empty_col[15];
	memset(empty_col, false, sizeof(empty_col));
	for(int j = 0; j < 15; j++)
	{
		int i = 0, p = 0;
		while(i < 10)
		{
			while(board[p][j] != ' ' && p < 10) p++;
			i = p + 1;
			while(board[i][j] == ' ' && i < 10) i++;
			if(p == 0 && i == 10) empty_col[j] = true;
			if(p < 10 && i < 10 && p < i) swap(board[p][j], board[i][j]);
		}
	}
	int j = 0, p = 0;
	while(j < 15)
	{
		while(!empty_col[p] && p < 15) p++;
		j = p + 1;
		while(empty_col[j] && j < 15) j++;
		if(p < 15 && j < 15 && p < j) for(int i = 0; i < 10; i++) swap(board[i][p], board[i][j]);
		swap(empty_col[p], empty_col[j]);
	}
	return;
}

int main()
{
	int num_case, area_max, count_step;
	cin >> num_case;
	for(int i = 0; i < num_case; i++)
	{
		for(int j = 9; j >= 0; j--) for(int k = 0; k < 15; k++) cin >> board[j][k];
		num_remained = 150;
		score = 0;
		cout << "Game " << i + 1 << ":" << endl;
		cout << endl;
		count_step = 0;
		while(1)
		{
			area_max = Search_Max_Area_Sub();
			if(area_max == 0 || area_max == 1) break;
			num_remained -= area_max;
			score += (area_max - 2) * (area_max - 2);
			color = board[sub_x_max][sub_y_max];
			memset(visited, 0, sizeof(visited));
			Delete_Max_Area(sub_x_max, sub_y_max);
			Shift_Area();
			cout << "Move " << ++count_step << " at (" << sub_x_max + 1 << "," << sub_y_max + 1 << "): removed " << area_max << " balls of color " << color << ", got " << (area_max - 2) * (area_max - 2) << " points." << endl;
		}
		if(num_remained == 0) score += 1000;
		cout << "Final score: " << score << ", with " << num_remained << " balls remaining." << endl;
		cout << endl;
	} 	
	return 0;	
} 
