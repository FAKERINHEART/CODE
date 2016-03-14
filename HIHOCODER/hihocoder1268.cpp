#include <iostream>
#include <cstring>

using namespace std;

int array[4][4];
bool existed[10];
int num = 0;
int result[4][4];

bool check()
{
	for(int i = 1; i <= 3; i++)
	{
		if(array[i][1] + array[i][2] + array[i][3] != 15) return false;
		if(array[1][i] + array[2][i] + array[3][i] != 15) return false;
	}
	if(array[1][1] + array[2][2] + array[3][3] != 15) return false;
	if(array[1][3] + array[2][2] + array[3][1] != 15) return false;
	return true;
}

void dfs(int x, int y)
{
	if(y >= 4) 
	{
		++x;
		y = 1;
	}
	
	if(x > 3)
	{
		if(check()) 
		{
			num++;
			for(int i = 1; i <= 3; i++) for(int j = 1; j <= 3; j++) result[i][j] = array[i][j];
		}
		return;
	}
	else
	{
		if(array[x][y]) 
		{
			dfs(x, y + 1);
			return;
		}
		else
		{
			for(int i = 1; i <= 9; i++)
			{
				if(!existed[i])
				{
					array[x][y] = i;
					existed[i] = true;
					dfs(x, y + 1);
					array[x][y] = 0;
					existed[i] = false;	
				} 
			}
		}	
	}
	return;
}

int main()
{
	memset(existed, false, sizeof(existed));
	for(int i = 1; i <= 3; i++)
	{
		for(int j = 1; j <= 3; j++)
		{
			cin >> array[i][j];
			existed[array[i][j]] = true;
		}	
	}	
	dfs(1, 1);
	if(num > 1) cout << "Too Many" << endl;
	else
	{
		for(int i = 1; i <= 3; i++)
		{
			for(int j = 1; j <= 3; j++)	cout << result[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
} 
