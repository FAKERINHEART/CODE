#include <iostream> 
#include <algorithm>
using namespace std;

int main()
{
	int t, W, H, n, x, y;
	int imgA[100][100], imgB[100][100];
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> W >> H >> n;
		for(int j = 0; j < H; j++)
		{
			for(int k = 0; k < W; k++)
			{
				imgA[j][k] = 0;
				imgB[j][k] = 0;
			}
		}
		
		for(int j = 0; j < n; j++)
		{
			cin >> x >> y;
			imgA[y][x]++;
		}
		for(int j = 0; j < n; j++)
		{
			cin >> x >> y;
			imgB[y][x]++;
		}
		/*
		for(int j = 0; j < H; j++)
		{
			for(int k = 0; k < W; k++) cout << imgA[j][k] << " ";
			cout << endl;
		}
		cout << endl;
		for(int j = 0; j < H; j++)
		{
			for(int k = 0; k < W; k++) cout << imgB[j][k] << " ";
			cout << endl;
		}
		*/
		int* sortA = new int[n];
		int* sortB = new int[n];
		x = 0, y = 0;
		for(int j = 0; j < H; j++)
		{
			for(int k = 0; k < W; k++)
			{
				if(imgA[j][k])
				{
					for(int l = j - 1; l >= 0; l--)
					{
						if(imgA[l][k]) imgA[j][k]++;
						else break;
					}
					for(int l = j + 1; l <= H - 1; l++)
					{
						if(imgA[l][k]) imgA[j][k]++;
						else break;
					}
					for(int l = k - 1; l >= 0; l--)
					{
						if(imgA[j][l]) imgA[j][k]++;
						else break;
					}
					for(int l = k + 1; l <= W - 1; l++)
					{
						if(imgA[j][l]) imgA[j][k]++;
						else break;
					}
					sortA[x] = imgA[j][k];
					x++;
				}
				
				if(imgB[j][k])
				{
					for(int l = j - 1; l >= 0; l--)
					{
						if(imgB[l][k]) imgB[j][k]++;
						else break;
					}
					for(int l = j + 1; l <= H - 1; l++)
					{
						if(imgB[l][k]) imgB[j][k]++;
						else break;
					}
					for(int l = k - 1; l >= 0; l--)
					{
						if(imgB[j][l]) imgB[j][k]++;
						else break;
					}
					for(int l = k + 1; l <= W - 1; l++)
					{
						if(imgB[j][l]) imgB[j][k]++;
						else break;
					}
					sortB[y] = imgB[j][k];
					y++;
				}
			}
		}
		/*
		for(int j = 0; j < n; j++) cout << sortA[j] << " ";
		cout << endl;
		for(int j = 0; j < n; j++) cout << sortB[j] << " ";
		*/
		sort(sortA, sortA + n);
		sort(sortB, sortB + n);
		
		for(int j = 0; j < n; j++) cout << sortA[j] << " ";
		cout << endl;
		for(int j = 0; j < n; j++) cout << sortB[j] << " ";
		cout << endl;
		
		
		int j;
		for(j = 0; j < n; j++) if(sortA[j] - sortB[j]) break;
		if(j == n) cout << "YES" << endl;
		else cout << "NO" << endl;
		
		delete[] sortB;
		delete[] sortA;
	}
	return 0;
}
