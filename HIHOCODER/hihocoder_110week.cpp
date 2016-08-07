#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int N, M;
long long dist[101];
long long newdist[101];
long long edge[40][101][101];

bool check()
{
	for(int i = 1; i <= N; i++) if(newdist[i] <= M) return true;
	return false;
}

int main()
{
	cin >> N >> M;
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) cin >> edge[0][i][j];
	for(int i = 1; i <= int(log(M) / log(2)) + 1; i++)
	{
		for(int j = 1; j <= N; j++) for(int k = 1; k <= N; k++) edge[i][j][k] = (1LL << 62);
		for(int j = 1; j <= N; j++)
		{
			for(int k = 1; k <= N; k++)
			{
				for(int l = 1; l <= N; l++)
				{
					if(i == 1 && j != l && k != l || i != 1)
					{
						if(edge[i][j][k] > edge[i - 1][j][l] + edge[i - 1][l][k]) 
						{
							edge[i][j][k] = edge[i - 1][j][l] + edge[i - 1][l][k];	
						}	
					}	
				}
			} 
		}
	}
	
	long long ans = 0;
	for(int i = int(log(M) / log(2)) + 1; i >= 0; i--)
	{
		for(int j = 1; j <= N; j++) newdist[j] = (1LL << 62);
		for(int j = 1; j <= N; j++)
		{
			for(int k = 1; k <= N; k++)
			{
				if(!i && j != k || i)
				if(newdist[j] > dist[k] + edge[i][k][j])
				{
					newdist[j] = dist[k] + edge[i][k][j];
				}
			}
		}
		if(check())
		{
			for(int j = 1; j <= N; j++) dist[j] = newdist[j];
			ans = ans + pow(2, i);
		}
	}
	cout << ans << endl;
	
	return 0;
}
