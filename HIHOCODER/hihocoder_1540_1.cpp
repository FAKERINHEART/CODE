#include <iostream>
#include <vector>
#include <cstring>

int n, A[100001][5], dp[100001][121];
int kangtuo_facts[] = {1, 1, 2, 6, 24, 120, 720};
std::vector<int> kangtuo_list[121];
std::vector<int> kangtuo_trans[121];

std::vector<int> reverse_kangtuo(int n, int k) //逆康托展开
{
    --k;
    
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));
    std::vector<int> kt;

    for (int i = 1; i <= n; ++i)
    {
        int temp_num = k / kangtuo_facts[n - i];

        for (int j = 1; j <= n; ++j)
        {
            if (visited[j] == false)
            {
                if (temp_num-- == 0)
                {
                    kt.push_back(j);
                    visited[j] = true;
                    break;
                }
            }
        }

        k %= kangtuo_facts[n - i];
    }

    return kt;
}

int kangtuo(int n, std::vector<int> a)//康托展开
{
    int sum = 1;

    for (int i = 0; i < n; ++i)
    {
        int t = 0;

        for(int j = i + 1; j < n; ++j)
        {
            if (a[i] > a[j])
            {
                ++t;
            }
        }

        sum += t * kangtuo_facts[n - i - 1];
    }

    return sum;
}


void prepare()
{
    for (int i = 1; i <= 120; ++i)
    {
        kangtuo_list[i] = reverse_kangtuo(5, i);

        std::vector<int> v(kangtuo_list[i].begin() + 1, kangtuo_list[i].end());

        for (int j = 0; j < 4; ++j)
        {
            if (v[j] > kangtuo_list[i][0])
            {
                --v[j];
            }
        }

        for(int j = 1; j <= 5; ++j)
        {
            std::vector<int> temp_v(v);
            temp_v.push_back(j);

            for(int k = 0; k < 4; ++k)
            {
                if(temp_v[k] >= j)
                {
                    ++temp_v[k];
                }
            }
                
            kangtuo_trans[kangtuo(5, temp_v)].push_back(i);
            //(1234)y->x(1234)
        }
    }
    
    return;
}

int main()
{
    /*
    std::vector<int> v = reverse_kangtuo(5, 107);
    
    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << std::endl;
    }

    std::cout << kangtuo(5, v) << std::endl;
    */
    
    prepare();
    
    int T;
    std::cin >> T;

    while(T--)
    {
        int n;
        std::cin >> n;

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> A[i][0] >> A[i][1] >> A[i][2] >> A[i][3] >> A[i][4];
        }

        int ans = 1 << 30;

        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= 120; ++j)
            {
                dp[i][j] = 1 << 30;
            }
        }

        for (int  i = 1; i <= 120; ++i)
        {
            if (kangtuo_list[i][3] > 3 && kangtuo_list[i][4] > 3)
            {
                dp[0][i] = 0;
            }
        }

        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= 120; ++j)
            {
                for(int k = 0; k < 5; ++k)
                {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][kangtuo_trans[j][k]] + A[i][5 - kangtuo_list[j][2]]);

                    if (i == n && kangtuo_list[j][3] < 3 && kangtuo_list[j][4] < 3)
                    {
                        ans=std::min(ans, dp[i][j]);
                    }   
                }
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}

