#include<iostream>
#include <string>
#include <cstring>

std::string W[10000];
std::string S;
int dp[100001][26];
int dp_assist[26];

int main()
{
    int N;

    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> W[i];
    }

    std::cin >> S;
    memset(dp, 255, sizeof(dp));
    memset(dp_assist, 255, sizeof(dp_assist));

    for (int i = S.length() - 1; i >= 0; --i)
    {
        dp_assist[S[i] - 'a'] = i;

        for (int j = 0; j < 26; ++j)
        {
            dp[i][j] = dp_assist[j];
        }
    }

    /*
    for (int i = 0; i < S.length(); ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << dp[i][j] << " ";
        }

        std::cout << std::endl;
    }
    */

    int ans = 0;

    for (int i = 0; i < N; ++i)
    {
        int j = 0;
        int Sk = 0;

        for (j = 0; j < W[i].length(); ++j)
        {
            if (dp[Sk][W[i][j] - 'a'] < 0)
            {
                break;
            }
            else
            {
                Sk = dp[Sk][W[i][j] - 'a'] + 1;
            }
        }

        if (j == W[i].length())
        {
            ans = std::max(ans, j);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
