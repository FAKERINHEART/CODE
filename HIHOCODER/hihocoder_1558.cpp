#include <iostream>

int base = 1;
int N, K;

void dfs(int num_base, int num)
{
    for (int i = 0; i <= K; ++i)
    {
        if (num_base >= base)
        {
            std::cout << num_base << std::endl;
            return;
        }
        
        if (num * i <= K)
        {
            dfs(num_base * 10 + i, i);
        }
    }

    return;
}

int main()
{
    std::cin >> N >> K;
    
    for (int i = 2; i <= N; ++i)
    {
        base *= 10;
    }

    for (int i = 1; i <= K; ++i)
    {
        dfs(i, i);
    }
    
    return 0;
}
