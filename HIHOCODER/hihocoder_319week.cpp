#include <iostream>
#include <cmath>

int main()
{
    int K;
    std::cin >> K;

    double num[K], val[K];
    double a;
    std::cin >> a;

    double sum = 0;

    for (int i = 0; i < K; ++i)
    {
        std::cin >> num[i];
        sum += num[i];
    }

    double ans = 0;

    for (int i = 0; i < K; ++i)
    {
        val[i] = num[i] / sum * a;
        ans += num[i] * log(val[i]);
    }

    printf("%.5lf\n", ans);

    for (int i = 0; i < K; ++i)
    {
        printf("%.5lf ", val[i]);
    }

    std::cout << std::endl;

    return 0;
}
