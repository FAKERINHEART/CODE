#include <iostream>
#include <map>

std::map<long long, long long> v, h, d1, d2;

int main()
{
    int N, R, C, ans;

    ans = 0;
    std::cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        std::cin >> R >> C;
        
        ans += h[R];
        ++h[R];
        ans += v[C];
        ++v[C];
        ans += d1[R + C];
        ++d1[R + C];
        ans += d2[R - C];
        ++d2[R - C];
    }
    
    std::cout << ans << std::endl;
    
    return 0;
}
