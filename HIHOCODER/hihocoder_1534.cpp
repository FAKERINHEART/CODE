#include <iostream>
#include <map>

long long A[100001];
long long S[100001];
std::map<long long, long long> M;

int main()
{
    int N, ans = 0;
    std::cin >> N;
    
    for (int i = 1; i <= N; ++i)
    {
        std::cin >> A[i];
        S[i] = S[i - 1] + A[i];
        ++M[S[i]];
    }
    
    --M[S[N]];
    
    for (int i = 1; i < N - 1; ++i)
    {
        --M[S[i]];
        
        for (int j = S[i] - 1; j <= S[i] + 1; ++j)
        {
            long long x = S[i];
            long long y = j;
            long long z = S[N] - x - y;
            
            if (std::abs(x - y) <= 1 && std::abs(y -z) <= 1 && std::abs(z - x) <= 1)
            {
                ans += M[x + y];
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
