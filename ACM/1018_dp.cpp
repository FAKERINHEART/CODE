#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	int num_case, num_device, num_choose;
	int B[101][100], P[101][100];
	int dp[101][1000];
	
	cin >> num_case;
	for(int i = 0; i < num_case; i++)
	{
		memset(dp, 0, sizeof(dp));
		cin >> num_device;
		for(int j = 1; j <= num_device; j++)
		{
			cin >> num_choose;
			for(int k = 0; k < num_choose; k++) cin >> B[j][k] >> P[j][k];
			for(int k = 0; k < 1000; k++)
			{
				dp[j][k] = 1 << 30;
				for(int l = 0; l < num_choose; l++)	if(B[j][l] >= k) dp[j][k] = min(dp[j][k], dp[j - 1][k] + P[j][l]);
			}
		}
		double B_P = -1;
		for(int j = 1; j < 1000; j++) B_P = max(B_P, j * 1.0 / dp[num_device][j]);
		cout << fixed << setprecision(3) << B_P << endl;
		
	}
	return 0;
} 
