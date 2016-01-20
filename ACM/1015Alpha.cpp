#include <iostream>
#include <algorithm>

using namespace std;

int p[200];
int d[200];
int pd[200];
int sum[21][801];
int path[21][801];

bool selected(int x, int y, int k)
{
	int i;
	for(i = x; i > 0; i--)
	{
		if(path[i][y] != k)	y = y - pd[path[i][y]];
		else break;
	}
	if(i > 0) return true;
	else return false;
}

int main()
{
	for(int i = 1; i <= 800; i++)
	{
		sum[0][i] = -1;
		path[0][i] = -1;
	} 
	sum[0][0] = 0;
	path[0][0] = -1;
		
	int n, m;
	int num = 0;
	while(cin >> n >> m)
	{
		if(!n && !m) break;
		num++;
		for(int i = 0; i < n; i++)
		{
			cin >> p[i] >> d[i];
			pd[i] = p[i] - d[i] + 20;
		}
	
		for(int i = 1; i <= m; i++)
		{
			for(int j = 0; j <= m * 40; j++)
			{
				sum[i][j] = -1;
				path[i][j] = -1;
				for(int k = 0; k < n; k++)
				{
					if(pd[k] <= j && sum[i - 1][j - pd[k]] != -1 && sum[i - 1][j - pd[k]] + p[k] + d[k] > sum[i][j] && !selected(i - 1, j - pd[k], k))
					{
						sum[i][j] = sum[i - 1][j - pd[k]] + p[k] + d[k];
						path[i][j] = k;
					}
				}
			}
		}	
		
		int left, right, result = -1;
		for(int i = m * 20; i <= m * 40; i++)
		{
			left = sum[m][m * 40 - i];
			right = sum[m][i];
			if(left != -1) result = m * 40 - i;
			if(right != -1 && right > left) result = i;
			if(result != -1) break;
		}		
		
		int* mmm = new int[m];
		int P = 0, D = 0;
		for(int i = m; i > 0; i--)
		{
			P += p[path[i][result]];
			D += d[path[i][result]];
			mmm[i - 1] = path[i][result];
			result = result - pd[path[i][result]];
		}
		
		cout << "Jury #" << num << endl;
		cout << "Best jury has value " << P << " for prosecution and value " << D << " for defence:" << endl;
		sort(mmm, mmm + m);
		for(int i = 0; i < m; i++) cout << " " << mmm[i] + 1;
		cout << endl;
		
		delete[] mmm;
	}	
	return 0;
}
