#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int LETTERS[20][20];
int visited[20][20];
int letter[26];
int R, S;
int MAX_LENGTH;

void dfs(int x, int y, int l)
{
	visited[x][y] = true;
	letter[LETTERS[x][y]] = true;
	MAX_LENGTH = max(MAX_LENGTH, l);
	int i, j;
	for(int k = 0; k < 4 ; k++)
	{
		switch(k)
		{
		case 0: i = x; j = y - 1; break;
		case 1: i = x - 1; j = y; break;
		case 2: i = x; j = y + 1; break;
		case 3: i = x + 1; j = y; break;
		}
		
		if(i >= 0 && i < R && j >= 0 && j < S && !visited[i][j] && !letter[LETTERS[i][j]]) 
		{
			dfs(i, j, l + 1);
			visited[i][j] = false;
			letter[LETTERS[i][j]] = false;
		}	
	}	
	return;
}

int main()
{
	char temp;
	cin >> R >> S;
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < S; j++) 
		{
			cin >> temp;
			LETTERS[i][j] = temp - 'A';
		}
	}
	memset(visited, 0, sizeof(visited));
	memset(letter, 0, sizeof(letter));
	MAX_LENGTH = 0;
	dfs(0, 0, 1);
	cout << MAX_LENGTH << endl;
	return 0;	
} 
