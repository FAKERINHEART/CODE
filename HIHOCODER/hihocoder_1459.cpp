#include <iostream>
#include <string>
#include <cstring>

int dp[100001][26];

bool find(int target, int d, int str_len, int K)
{
    int ed = str_len - d;
    for(int i = 0; i <= ed; i++)
    {
        if(dp[i + d][target] - dp[i][target] + K >= d)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int K, ans = 0;
    std::string s;

    std::cin >> K >> s;

    for (int i = 1; i <= s.length(); ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            dp[i][j] = dp[i - 1][j];
        }
        
        ++dp[i][s[i - 1] - 'a'];
    }

    if (s.length() > 0)
    {
        ans = 1;
    }

    for (int i = 0; i < 26; ++i)
    {
        int l = 0, r = dp[s.length()][i];

        while(l <= r)
        {
            int mid = (l + r) >> 1;

            if(mid <= ans)
            {
                l = mid + 1;
            }
            else
            {
                if(find(i, mid, s.length(), K) == true)
                {
                    ans = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
