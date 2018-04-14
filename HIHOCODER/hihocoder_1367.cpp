#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> left_num;//���ÿ�����ֵ�λ�� 
char str[101];//�ұ�����(������ֳ���Ϊ100) 
int left_count[2][50][500];//left_count[0][x][y], x������(ȡ0~9),���ǵĺ�Ϊyʱ���ܹ������Ŀ;left_count[1][x][y], x������(ȡ1~9),���ǵĺ�Ϊyʱ���ܹ������Ŀ
long long dp[101][50];

void prepare(int n)
{
    left_count[0][0][0] = left_count[1][0][0] = 1;

    for (int i = 1; i <= n; ++i)
    {
    	for (int j = 0; j <= 9 * i; ++j)
        {
            for (int k = 0; k <= min(9, j); ++k)
            {
                left_count[0][i][j] += left_count[0][i - 1][j - k];
				left_count[0][i][j] %= 1000000007;
            }
        }
        for (int j = i; j <= 9 * i; ++j)
        {
            for (int k = 1; k <= min(9, j - (i-1)); ++k)
            {
                left_count[1][i][j] += left_count[1][i - 1][j - k];
				left_count[1][i][j] %= 1000000007;
            }
        }
    }
    
    return;
}

int main()
{
    int max_length = 0;
	int length;
	
    while (true)
    {
        scanf("%*[?]%n%[=+]", &length, str);
        left_num.push_back(length);
        max_length = max(length, max_length);
        
		if (str[0] == '=')
        {
            break;
        }
    }

    scanf("%s%n", str + 1, &length);

    if(length < max_length)
    {
        printf("0");
        
        return 0;
    }

    prepare(left_num.size());
    
	reverse(str + 1, str + length + 1);
    dp[0][0] = 1;
    
    for (int i = 1; i <= length; ++i)
    {
        int count1 = 0, count2 = 0;
        
        for (int j = 0; j < left_num.size(); ++j)
        {
            count1 += (left_num[j] == i);//λ�����õ���i, �����ֻ��ȡ1~9 
            count2 += (left_num[j] > i);//λ������i, �����ֻ��ȡ0~9 
        }

        for (int j = 0; j < left_num.size(); ++j)
        {
            for (int k = 0; k < left_num.size(); ++k)
            {
                int total = 10 * j + str[i] - '0' - k;//��λ��ֵ��βΪi, ��λΪj�ҳ�ȥ��һλ(i-1)�Ľ�λk, ������������Ϊ: 10 * j + i - k
                long long sum = 0;
                
                for(int l = count1; l <= total; ++l)
                {
                    sum += (long long)left_count[1][count1][l] * left_count[0][count2][total - l];
                    sum %= 1000000007;
                }
                
                dp[i][j] += dp[i-1][k] * sum;
                dp[i][j] %= 1000000007;
            }
        }
    }

	printf("%ld\n", dp[length][0]);
	
    return 0;
}
