#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1111;

int dp[1001][1025];

int main()
{
    int T;

    cin >> T;
    
    while (T--)
    {
        int n, m;
        cin >> n >> m;

        memset(dp, 255, sizeof(dp));
        dp[0][0] = 0;

        for (int i = 1; i <= n; ++i)
        {
            int value, num;
            cin >> value >> num;

            int s = 0;

            for (int j = 0; j < num; ++j)
            {
                int temp;
                cin >> temp;

                s |= (1 << (temp - 1));
            }
            
            for (int j = 0; j < (1 << m); ++j)
            {
                if (dp[i - 1][j] != -1)
                {
                    dp[i][j ^ s] = max(dp[i][j ^ s], dp[i - 1][j] + value);
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                }

            }
        }

        cout << dp[n][(1 << m) - 1] << endl;
    }

    return 0;
}

