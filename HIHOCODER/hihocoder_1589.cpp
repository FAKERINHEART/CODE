#include <iostream>
#include <string>
#include <cstring>

int dp[1600002];

long long manacher(const std::string &str)
{
    memset(dp, 0, sizeof(dp));

    long long ans    = 0;
    size_t max_pos   = 0;
    size_t max_right = 0;

    for (size_t i = 1; i < str.length(); ++i)
    {
        if (max_right > i)
        {
            dp[i] = std::min((size_t)dp[max_pos * 2 - i], max_right - i);
        }
        else
        {
            dp[i] = 1;
        }

        while (str[i - dp[i]] == str[i + dp[i]])
        {
            ++dp[i];
        }

        if (max_right < i + dp[i])
        {
            max_right = i + dp[i];
            max_pos   = i;
        }

        ans += dp[i] / 2;
    }

    return ans;
}

int main()
{
    std::string str;
    std::cin >> str;

    std::string target_str;
    target_str = "^#";

    for (size_t i = 0; i < str.length(); ++i)
    {
        target_str += str[i];
        target_str += "#";
    }

    target_str += "$";

    long long ret = manacher(target_str);

    std::cout << ret << std::endl;

    return 0;
}
