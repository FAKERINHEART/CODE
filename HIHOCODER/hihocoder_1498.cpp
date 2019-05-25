#include <iostream>

using namespace std;

int main()
{
    long long N, Q;
    
    std::cin >> N >> Q;
    
    if (N <= 2 * Q)
    {
        std::cout << N << std::endl;
    }
    else
    {
        long long ans = 1LL << 30, k = 0;
        
        while (true)
        {
            long long hours = 1LL << k;
            
            if (hours > N)
            {
                break;
            }
            
            if (N % hours == 0)
            {
                ans = std::min(ans, N / hours + Q * k);
            }
            else
            {
                ans = std::min(ans, N / hours + 1 + Q * k);
            }

            ++k;
        }
        
        std::cout << ans << std::endl;
    }

    return 0;
}
