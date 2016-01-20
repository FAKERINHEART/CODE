#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int p[200];
int d[200];
int pd[200];
int sum[21][801];
vector<int> path[21][801];

int main()
{		
	int n, m;
	int num = 0;
	while(cin >> n >> m)
	{
		if(!n && !m) break;
		num++;
		for(int i = 0; i <= m; i++)
		{
			for(int j = 0; j <= m * 40; j++) 
			{
				sum[i][j] = -1;
				path[i][j].clear();
			}
			
		} 
		sum[0][0] = 0;
		
		for(int i = 0; i < n; i++)
		{
			cin >> p[i] >> d[i];
			pd[i] = p[i] - d[i] + 20;
		}
	
		for(int k = 0; k < n; k++)
		{
			for(int i = m; i >= 1; i--)
			{
				for(int j = 0; j <= m * 40; j++)
				{
					if(j >= pd[k] && sum[i - 1][j - pd[k]] >= 0 && sum[i - 1][j - pd[k]] + p[k] + d[k] >= sum[i][j])
					{
						sum[i][j] = sum[i - 1][j - pd[k]] + p[k] + d[k];
						path[i][j] = path[i - 1][j - pd[k]];
						path[i][j].push_back(k);
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
		
		int P = 0, D = 0;
		for(vector<int>::size_type ix = 0; ix != path[m][result].size(); ix++)
		{
			P += p[path[m][result][ix]];
			D += d[path[m][result][ix]];
		}
		
		cout << "Jury #" << num << endl;
		cout << "Best jury has value " << P << " for prosecution and value " << D << " for defence:" << endl;
		for(vector<int>::size_type ix = 0; ix != path[m][result].size(); ix++) cout << " " << path[m][result][ix] + 1;
		cout << endl;
		
	}	
	return 0;
}
