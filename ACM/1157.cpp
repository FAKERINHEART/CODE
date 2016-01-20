#include <iostream>
#include <algorithm>

using namespace std;

int value[100][100];
int dp[100][100];

int main()
{
	int F, V;
	cin >> F >> V;
	for(int i = 0; i < F; i++) for(int j = 0; j < V; j++) cin >> value[i][j];
	for(int i = 0; i < V; i++) dp[0][i] = value[0][i];
	for(int i = 1; i < F; i++)
	{
		for(int j = i; j < V; j++)
		{
			dp[i][j] = -5000;
			for(int k = i - 1; k < j; k++) dp[i][j] = max(dp[i][j], dp[i - 1][k] + value[i][j]);
		}
	}
	
	int MAX = -5000;
	for(int i = F - 1; i < V; i++) MAX = max(MAX, dp[F-1][i]);
	cout << MAX << endl; 
	return 0;	
} 
