#include <iostream>
#include <algorithm>

const int MOD = 1000000007; 
int num[100000];
 
long long fast_mode(long long a, long long b)
{
    long long ans = 1;
    
    while (b > 0)
    {
        if ((b & 1) != 0)
        {
            ans = (ans * a) % 1000000007;
        }

        a = (a * a) % 1000000007;
        b /= 2;
    }

    return ans;
}

int main()
{
    int N, K;
    long long ans = 0;

    std::cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> num[i];
    }

    std::sort(num, num + N);

    for (int i = 0, j = N -1; i < N && 2 * num[i] <= K; ++i)
    {
        while (j >= i && num[j] + num[i] > K)
        {
            --j;
        }

        if (j >= i)
        {
            ans = (ans + fast_mode(2, j-i)) % 1000000007;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
