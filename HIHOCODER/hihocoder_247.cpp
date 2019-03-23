#include <iostream>
#include <cstring>

using namespace std;

double num[101];

int main()
{
    int p, q, n;
    cin >> p >> q >> n;

    for (int i = 0; i <= 100; ++i)
    {
        int count = 0;
        double percent = 1;

        while (true)
        {
            if (i + count * q >= 100 )
            {
                num[i] += (count + 1 ) * percent;
                break;
            }
            
            num[i] += percent * (i + count * q) / 100.0 * (count + 1);
            percent = percent * (1 - (i + count * q) / 100.0);
            ++count;
        }
    }

    double ans = 0;

    for (int i = 1 ; i <= n; ++i)
    {
        if (p == 0)
        {
            ans += ( n - i + 1 ) * num[0];
            break;
        }

        ans += num[p];
        p >>= 1;
    }

    printf("%.2lf\n", ans);
    return 0;
}
