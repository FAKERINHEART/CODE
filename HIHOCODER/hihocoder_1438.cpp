#include <iostream>
#include <algorithm>
#include <iomanip>

int N, M, k;
double distance[100000];

int main()
{
    std::cin >> N >> M >> k;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> distance[i];
    }

    double left = 0, right = M;

    while (right - left > 1e-3)
    {
        double mid = (left + right) / 2;
        int temp = k;

        for (int i = 1; i < N; ++i)
        {
            int t = std::ceil((distance[i] - distance[i - 1]) / mid) - 1;
            temp -= t;
            
            if (temp < 0)
            {
                break;
            }
        }

        if (temp >= 0)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1) << left << std::endl;

    return 0;
}
