#include<iostream>

int main()
{
	long long dp[101][2], ans;
    int n;
    
    while(std::cin >> n)
    {
        dp[0][0] = dp[0][1] = 1;
        
        for(int i = 1;i < n; ++i)
        {
            dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % 1000000007;
            dp[i][1] = dp[i-1][0];
        }

        ans = 1;
        
        for(int i = 1; i <= n; ++i)
        {
            ans = (ans << 1) % 1000000007;
        }
        
        std::cout<< (ans - ((dp[n-1][0] + dp[n-1][1]) % 1000000007) + 1000000007) % 1000000007 << std::endl;
    }
 }   
