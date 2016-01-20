#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int king_substract[8][2] = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
	int knight_substract[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
	int king_board[64][64], knight_board[64][64];
	int position[64], sub_position = 0;
	int x, y;
	for(int i = 0; i < 64; i++)
	{
		for(int j = 0; j < 64; j++)
		{
			king_board[i][j] = 100000;
			knight_board[i][j] = 100000;
		}
		king_board[i][i] = 0;
		knight_board[i][i] = 0;
		
		x = i / 8;
		y = i % 8;
		for(int j = 0; j < 8; j++)
		{
			if(x + king_substract[j][0] >= 0 && x + king_substract[j][0] < 8 && y + king_substract[j][1] >= 0 && y + king_substract[j][1] < 8)
				king_board[i][(x + king_substract[j][0]) * 8 + (y + king_substract[j][1])] = 1;
			if(x + knight_substract[j][0] >= 0 && x + knight_substract[j][0] < 8 && y + knight_substract[j][1] >= 0 && y + knight_substract[j][1] < 8)
				knight_board[i][(x + knight_substract[j][0]) * 8 + (y + knight_substract[j][1])] = 1;
		}
	}
	
	for(int k = 0; k < 64; k++)
	{
		for(int i = 0; i < 64; i++)
		{
			for(int j = 0; j < 64; j++)
			{
				if(king_board[i][j] > king_board[i][k] + king_board[k][j]) king_board[i][j] = king_board[i][k] + king_board[k][j];
				if(knight_board[i][j] > knight_board[i][k] + knight_board[k][j]) knight_board[i][j] = knight_board[i][k] + knight_board[k][j];
			}
		}
	}
	
	string str;
	cin >> str;
	for(int i = 0; i < str.size(); i += 2) position[sub_position++] = (str[i + 1] - '1') * 8 + (str[i] - 'A');
	
	int sum, MIN = 100000;
	
	for(int i = 0; i < 64; i++)
	{
		for(int j = 0; j < 64; j++)
		{
			for(int k = 1; k < sub_position; k++)
			{
				sum = 0;
				for(int l = 1; l < sub_position; l++) sum += knight_board[position[l]][i];
				sum -= knight_board[position[k]][i];
				sum += king_board[position[0]][j];
				sum += knight_board[position[k]][j] + knight_board[j][i];
				MIN = min(MIN, sum);
			}
		}
	}
	cout << MIN << endl;
	
	return 0;
} 
