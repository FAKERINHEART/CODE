#include <iostream>
#include <string>

using namespace std;
int a[30][30], b[30], ans[30];

void Solve()
{
	for(int i = 0; i < 30; i++)
	{
		for(int j = i; j < 30; j++) 
		{
			if(a[j][i])
			{    
				for(int k = i; k < 30; k++) swap(a[j][k], a[i][k]);
				swap(b[i], b[j]);
				break;
			}
		}

		for(int j = i + 1; j < 30; j++)
		{
			if(!a[j][i]) continue;
			for(int k = i; k < 30; k++) a[j][k] ^= a[i][k];
			b[j] ^= b[i];
		}
	}

	for(int i = 29; i >= 0; i--)
	{
		for(int j = i + 1; j < 30; j++)
		{
			b[i] ^= a[i][j] * ans[j];
			a[i][j] = 0;
		}
		ans[i] = b[i];
	}
	return;
}

int main()
{
	string str;
	for(int i = 0; i < 5; i++) 
	{
		cin >> str;
		for(int j = 0; j < 6; j++) 
		{
			b[i * 6 + j] = str[j] - '0';
			b[i * 6 + j] ^= 1;
		}
	}
	int x, y;
	for(int i = 0; i < 30; i++)
	{
		a[i][i] = 1;
		x = i / 6;
		y = i % 6;
		if(y - 1 >= 0) a[x * 6 + (y - 1)][i] = 1;
		if(y + 1 <= 5) a[x * 6 + (y + 1)][i] = 1;
		if(x - 1 >= 0) a[(x - 1) * 6 + y][i] = 1;
		if(x + 1 <= 4) a[(x + 1) * 6 + y][i] = 1;
	}
	
	Solve();
	int count = 0;
	for(int i = 0; i < 30; i++) if(ans[i]) count++;
	cout << count << endl;
	for(int i = 0; i < 30; i++) if(ans[i]) cout << i / 6 + 1 << " " << i % 6 + 1 << endl;
	return 0;
} 
