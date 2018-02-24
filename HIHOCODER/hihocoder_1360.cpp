#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	
	int A[N], B[N];
	double dp[N][N][M + 1], area[N][N][N];
	memset(dp, 0, sizeof(dp));
	memset(area, 0, sizeof(area));
	
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i] >> B[i];
	}
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				area[i][j][k] = 0.5 * abs(A[i] * B[j] + A[j] * B[k] + A[k] * B[i] - A[i] * B[k] - A[k] * B[j] - A[j] * B[i]);
			}
		}
	}
	
	for (int k = 3; k <= M; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = (i + 1); j != i; j = (j + 1) % N)
			{
				for (int u = (i + 1); u != j; u = (u + 1) % N)
				{
					dp[i][j][k] = max(dp[i][j][k], dp[i][u][k - 1] + area[i][u][j]);
				}
			}
		}
	}
	
	double ans = 0;
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			ans = max(ans, dp[i][j][M]);
		}
	}
		
	cout << fixed << setprecision(2) << ans << endl;
	return 0;
}
