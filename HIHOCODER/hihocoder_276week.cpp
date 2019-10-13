#include <iostream>

int a[100005];

int main()
{
    int N;
    
    std::cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        std::cin >> a[i];
    }

    int sum = 0, r = N;

    for (int i = N; i >= 1; --i)
    {
        if (a[i] != r)
        {
            ++sum;
        }
        else
        {
            --r;
        }
    }
    
    std::cout << sum << std::endl;

    return 0;
}
