#include <iostream>

long long extend_gcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;

        return a;
    }

    long long d = extend_gcd(b, a % b, y, x);

    y -= a / b * x;

    return d;
}

int main()
{
    int a, b, p;
    
    std::cin >> a >> b >> p;

    long long x, y;
    extend_gcd(b, p, x, y);
    
    std::cout << a * ((x % p + p) % p) % p << std::endl;

    return 0;
}

