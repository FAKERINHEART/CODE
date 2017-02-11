#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k, t;
int a[101], b[101];
long long dp[10005];

int main() 
{
    int T;
    cin >> T;
    while(T --) 
    {
        long long ans = 0;
        bool flag = true;
        cin >> n >> m >> k >> t;
        
        for(int i = 0; i < m; ++i)
        {
        	cin >> a[i];
		}
		
        for(int i = 0; i < m; ++i)
        {
        	cin >> b[i]; 
		}
		
        while(n --) 
        {
            for(int i = 0; i < 10005; i++)
        	{
            	dp[i] = (1 << 30);
			}
            dp[0] = 0;
            
            long long now = (1 << 30);
            for(int i = 0; i < m; ++i)
            {
                for(int j = 0; j <= k; ++j)
                {
                    if(k < j + b[i])
                    {
                    	now = min(now, dp[j] + a[i]);
					}
                    else
                    {
                    	dp[j + b[i]] = min(dp[j + b[i]], dp[j] + a[i]);
					}  
                }
            }
            now = min(now, dp[k]);
            if(now == (1 << 30)) 
            {
                flag = false;
                break;
            }
            ans += now;
            for(int i = 0; i < m; ++i) 
            {
            	b[i] /= t;
			}  
        }
        if(flag)
        {
        	cout << ans << endl;
		}
        else
        {
        	cout << "No Answer" << endl;
		}
    }
}

