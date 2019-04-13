#include <string.h>
#include <iostream>

using namespace std;

char str[1005];
int dp1[1005][1005];//dp[i][j], 以i为结尾的字符串, 前缀和要达到j, 需要插入多少个字符
int dp2[1005][1005];//dp[i][j], 以i为结尾的字符串, 前缀和要达到j, 一共有多少种方案

void Update(int a1,int b1,int a2,int b2,int diff)
{
    if (dp1[a1][b1] == dp1[a2][b2] + diff)
    {
        dp2[a1][b1] = (dp2[a1][b1] + dp2[a2][b2]) % 1000000007;
    }
    else if (dp1[a1][b1] > dp1[a2][b2] + diff)
    {
        dp1[a1][b1] = dp1[a2][b2] + diff;
        dp2[a1][b1] = dp2[a2][b2];
    }
}

int main()
{
    std::cin >> str + 1;
    int str_len = strlen(str + 1);

    str[str_len + 1] = '(';
    memset(dp1, 63, sizeof(dp1));

    dp1[0][0] = 0, dp2[0][0] = 1;

    //我们只在每次循环的末尾字符前插入字符
    //(前只插入), )前只插入(
    for (int i = 1; i <= str_len + 1; ++i)
    {
        if (str[i] == '(')
        {
            for (int j = str_len; j >= 1; --j)
            {
                Update(i, j, i - 1, j, 1);//'(', i结尾和i-1结尾, 要达到同一个前缀和, 必须是i结尾的多插入一个字符')'

                if (j < str_len)
                {
                    Update(i, j, i, j + 1, 1);//'(', 同样i结尾的, 多一个前缀和, 说明多前缀和的少插入一个字符')'
                }
                
            }
            
            for(int j = 1; j <= str_len; ++j)
            {
                Update(i, j, i - 1, j - 1,0);//'(', i结尾和i-1结尾, 正好差一个前缀和
            }
        }
        else
        {
            for (int j = 0; j <= str_len; ++j)
            {
                Update(i, j, i - 1, j, 1);//')', i结尾和i-1结尾, 要达到同一个前缀和, 必须是i结尾的多插入一个字符'('

                if (j > 0)
                {
                    Update(i, j, i, j - 1, 1);//')', 同样i结尾的, 多一个前缀和, 说明多前缀和的少插入一个字符'('
                }
            }

            for (int j = 0; j <= str_len; ++j)
            {
                Update(i, j, i - 1, j + 1, 0);//')', i结尾和i-1结尾, 正好差一个前缀和
            }
        }
    }

    std::cout << dp1[str_len + 1][1] << " " << dp2[str_len + 1][1] << std::endl;

    return 0;
}
