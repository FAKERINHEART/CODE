#include <iostream>
#include <cmath>

int main()
{
    int T, N;

    std::cin >> T;
    
    while (T--)
    {
        std::cin >> N;
        int SQRT = sqrt(1.0 * 2 * N);
        
        int ans = 0;

        for (int i = 1; i <= SQRT; ++i)
        {
            if ((N - i * (i - 1) / 2) % i == 0)
            {
                ans = std::max(ans, i);
            }
        }
        
        std::cout << ans << std::endl;
    }

    return 0;
}
