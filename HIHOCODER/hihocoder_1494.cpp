#include <iostream>
#include <map>
#include <algorithm>

std::map<int, int> m;

int main()
{
    int N;
    std::cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        int Ci;
        std::cin >> Ci;
        
        int width_sum = 0;
        
        for (int j = 0; j < Ci; ++j)
        {
            int width;
            std::cin >> width;
            
            if (j < Ci - 1)
            {
                width_sum += width;
                ++m[width_sum];
            }
        }
    }
    
    int ans = 0;
    
    for (std::map<int, int>::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        ans = std::max(ans, iter->second);
    }

    std::cout << N - ans << std::endl;
    
    return 0;
}
