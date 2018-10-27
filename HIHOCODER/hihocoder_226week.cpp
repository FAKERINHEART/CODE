#include <iostream>

int a[5] = {36, 48, 64, 81, 108};
int b[12] = {0, 1, 2, 3, 4, 5, 6, 9, 12, 16, 20, 27};

int main()
{
    long long N;
    std::cin >> N;
    
    if (N < 12)
    {
        std::cout << b[N] << std::endl;
    }
    else
    {
        long long result = a[(N - 12) % 5];
        
        for (int i = 0; i < (N - 12) / 5; ++i)
        {
            result = (result * 4) % 1000000007;
        }

        std::cout << result << std::endl;
    }

    return 0;
}
