#include <iostream>

int main()
{

    int T, h, m, s, t;

    std::cin >> T;

    while (T--)
    {
        std::cin >> h >> m >> s >> t;

        t = t % 86400;
        s = s + t;

        if (s >= 60)
        {
            m += s / 60;
            s %= 60;

            if (m >= 60)
            {
                h += m / 60;
                m %= 60;

                if (h >= 24)
                {
                    h %= 24;
                }
            }
        }

        if (h > 12)
        {
            h -= 12;
        }

        double s1 = (s / 60.0) * 0.5 + 1.0 * m * 0.5 + h * 60 * 0.5;
        double s2 = (s / 60.0) * 6.0 + m * 6.0;
        double temp = (s1 - s2) > 0?(s1 - s2): (s2 - s1);
        printf("%.4f\n", std::min(360 - temp, temp));
    }

    return 0;
}
