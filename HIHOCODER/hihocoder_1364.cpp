#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int N, M;
	int u[11][11];
	int dp[100005];
	int w, p;
	
	cin >> N >> M;
    memset(u, 0, sizeof(u));
    memset(dp, 0, sizeof(dp));
    
    for (int i = 0; i < N; ++i)
	{
        cin >> w >> p;
        ++u[w][p];
    }

    for (int i = 0; i <= 10; ++i)
    {
        for (int j = 0; j <= 10; ++j)
		{
            int temp = 1;
            
            while (u[i][j] > 0)
			{		
                if (u[i][j] >= temp)
				{
					u[i][j] -= temp;
				}
                else 
				{
					temp = u[i][j];
					u[i][j] = 0;
				}
				
                for(int k = M; k >= i * temp; --k)
                {
                	dp[k] = max(dp[k], dp[k - i * temp] + j * temp);
				}
				
				temp <<= 1;
            }
        }
    }
    
    cout << dp[M] << endl;
    
    return 0;
}  
