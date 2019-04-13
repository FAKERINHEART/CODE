#include <string.h>
#include <iostream>

using namespace std;

char str[1005];
int dp1[1005][1005];//dp[i][j], ��iΪ��β���ַ���, ǰ׺��Ҫ�ﵽj, ��Ҫ������ٸ��ַ�
int dp2[1005][1005];//dp[i][j], ��iΪ��β���ַ���, ǰ׺��Ҫ�ﵽj, һ���ж����ַ���

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

    //����ֻ��ÿ��ѭ����ĩβ�ַ�ǰ�����ַ�
    //(ǰֻ����), )ǰֻ����(
    for (int i = 1; i <= str_len + 1; ++i)
    {
        if (str[i] == '(')
        {
            for (int j = str_len; j >= 1; --j)
            {
                Update(i, j, i - 1, j, 1);//'(', i��β��i-1��β, Ҫ�ﵽͬһ��ǰ׺��, ������i��β�Ķ����һ���ַ�')'

                if (j < str_len)
                {
                    Update(i, j, i, j + 1, 1);//'(', ͬ��i��β��, ��һ��ǰ׺��, ˵����ǰ׺�͵��ٲ���һ���ַ�')'
                }
                
            }
            
            for(int j = 1; j <= str_len; ++j)
            {
                Update(i, j, i - 1, j - 1,0);//'(', i��β��i-1��β, ���ò�һ��ǰ׺��
            }
        }
        else
        {
            for (int j = 0; j <= str_len; ++j)
            {
                Update(i, j, i - 1, j, 1);//')', i��β��i-1��β, Ҫ�ﵽͬһ��ǰ׺��, ������i��β�Ķ����һ���ַ�'('

                if (j > 0)
                {
                    Update(i, j, i, j - 1, 1);//')', ͬ��i��β��, ��һ��ǰ׺��, ˵����ǰ׺�͵��ٲ���һ���ַ�'('
                }
            }

            for (int j = 0; j <= str_len; ++j)
            {
                Update(i, j, i - 1, j + 1, 0);//')', i��β��i-1��β, ���ò�һ��ǰ׺��
            }
        }
    }

    std::cout << dp1[str_len + 1][1] << " " << dp2[str_len + 1][1] << std::endl;

    return 0;
}
