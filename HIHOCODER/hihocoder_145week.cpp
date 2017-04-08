#include <iostream>
#include <cstring>

using namespace std;

int dp[1001][1001];
int n, m, s, t, a[1001], q;

int main()
{
	cin >> q;
	
    while(q--)
    {
        memset(dp, 127, sizeof(dp));
        
        cin >> n >> m >> s >> t;
        
        for(int i = 0; i <= m; ++i)
        {
            dp[0][i] = 0;
        }
        
        for(int i = 1; i <= n; ++i)
        {
        	cin >> a[i];
        	
        	int num = a[i] / s;
            if(a[i] % s)
			{
				++num;
			}
			
            for(int j = 0; j <= num; ++j)
            {
                int x;
                if(a[i] - j * s > 0)
                {
                	x = (a[i] - j * s) / t;
                    if((a[i] - j * s) % t)
					{
						++x;
					}
                }
                else 
				{
					x = 0;
				}
				
                for(int k = 0; k <= m; ++k)
                {
                    if(k + j + x <= m)
                    {
                    	dp[i][k + j + x] = min(dp[i][k + j + x], dp[i - 1][k] + j);
                    }
                }
            }
        }
        
        int ans = 1 << 30;
        
        for(int j = 0; j <= m; ++j)
        {
            ans = min(ans, dp[n][j]);
        }
        
        if(ans > m)
		{
			cout << "No" << endl;
		}
        else 
		{
			cout << ans << endl;
		}
    }

    return 0;
}

