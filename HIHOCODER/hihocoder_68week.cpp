#include <iostream>
#include <string>

using namespace std;

int N, M;
char arr[220][220], hi[3][3];
char hi90[3][3], hi180[3][3], hi270[3][3];
int X, Y;

void rotate()
{
	for(int i = 0; i <=2; i++) for(int j = 0; j <= 2; j++) hi90[i][j] = hi[2 - j][i];
	for(int i = 0; i <=2; i++) for(int j = 0; j <= 2; j++) hi180[i][j] = hi90[2 - j][i];
	for(int i = 0; i <=2; i++) for(int j = 0; j <= 2; j++) hi270[i][j] = hi180[2 - j][i];
	return;
}

bool check(int row, int column, char p[3][3])
{
	for(int i = 0; i <= 2; i++)	for(int j = 0; j <= 2; j++)	if(arr[row + i][column + j] != p[i][j]) return false;
	X = row + 1;
	Y = column + 1;
	return true;
}

int main()
{
	cin >> N >> M;
	bool flag;
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cin >> arr[i][j];
	for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) cin >> hi[i][j];
	rotate();
	
	for(int i = 0; i <= N - 3; i++)
	{
		for(int j = 0; j <= M - 3; j++)
		{
			flag = false;
			flag |= check(i, j, hi);
			flag |= check(i, j, hi90);
			flag |= check(i, j, hi180);
			flag |= check(i, j, hi270);
			if(flag) cout << X + 1 << " " << Y + 1 << endl;
		}
	}
	return 0;	
} 
