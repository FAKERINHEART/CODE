#include <iostream>
#include <cstring>

using namespace std;

double dp[1001][1001];

int main()
{
    int N, M;
    
    std::cin >> N >> M;
    
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 0; i < N; ++i)
    {
        double p;
        
        std::cin >> p;
        
        for (int j = 0; j <= i; ++j)
        {
            dp[i + 1][j] += dp[i][j] * (1.0 - p);
            dp[i + 1][j + 1] += dp[i][j] * p;
        }
    }
    
    std::cout << dp[N][M] << std::endl;
    
    return 0;
}
