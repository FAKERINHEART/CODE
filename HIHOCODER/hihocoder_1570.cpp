#include <iostream>
#include <algorithm>
#include <math.h>

int main()
{

    int T;
    std::cin >> T;

    while (T--)
    {
        int N, U;
        std::cin >> N >> U;

        int X[N + 1], Y[N + 1];
        int MAX = -(1 << 30), X_MAX = 0, Y_MAX = 0;
        int MIN = (1 << 30), X_MIN = 1 << 30, Y_MIN = 1 << 30;

        for (int i = 1; i <= N; ++i)
        {
            std::cin >> X[i] >> Y[i];
        }

        for (int i = 1; i <= N; ++i)
        {
            for (int j = i + 1; j <= N; ++j)
            {
                for (int k = j + 1; k <= N; ++k)
                {
                    int area = abs((X[j] - X[i]) * (Y[k] - Y[i]) - (X[k] - X[i]) * (Y[j] - Y[i]));

                    if (area == 0)
                    {
                        continue;
                    }

                    int GX = (X[i] + X[j] + X[k]), GY = (Y[i] + Y[j] + Y[k]);

                    if (area < MIN || (area == MIN && GX < X_MIN) || (area == MIN && GX == X_MIN && GY < Y_MIN))
                    {
                        MIN = area;
                        X_MIN = GX;
                        Y_MIN = GY;
                    }

                    if (area > MAX || (area == MAX && GX > X_MAX) || (area == MAX && GX == X_MAX && GY > Y_MAX))
                    {
                        MAX = area;
                        X_MAX = GX;
                        Y_MAX = GY;
                    }
                }
            }
        }

        double dx = (X_MAX - X_MIN) / 3.0, dy = (Y_MAX - Y_MIN) / 3.0;
        printf("%.2lf\n", sqrt(dx * dx + dy * dy) / U / 2.0);
    }

    return 0;
}
