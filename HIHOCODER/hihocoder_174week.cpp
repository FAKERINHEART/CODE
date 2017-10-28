#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main()
{
    int N, M;
    double dp[101][601];
    
	cin >> N >> M;
	
	memset(dp, 0, sizeof(dp));
	
    for (int i = 1; i <= 6; ++i)
    {
        dp[1][i] = 100.0 / 6;
    }

    for (int i = 2; i <= N; ++i)
    {
    	for (int j = i; j <= M; ++j)
		{
			if(j - i < 6)
			{
		    	for(int k = i - 1; k < j; ++k)
		    	{
		        	dp[i][j] += dp[i-1][k] / 6;
		    	}
			}
			else
			{
		    	for(int k = j - 6; k < j; ++k)
		    	{
		       		dp[i][j] += dp[i-1][k] / 6;
		    	}
			}
		}
    }
    
    cout << fixed << setprecision(2) << dp[N][M] << endl;
    
    return 0;
}  
