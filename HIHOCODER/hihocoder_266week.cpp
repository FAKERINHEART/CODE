#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-9;
const double pi = acos(-1.0);

struct point
{
    double x;
    double y;

    double friend dis(const point &a, const point &b)
    {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
};

struct alpha
{
    double v;
    bool flag;

    bool friend operator<(const alpha &a, const alpha &b)
    {
        return a.v < b.v;
    }
};

point p[2010];
alpha alp[4000005];

int main()
{
    int N, R;
    std::cin >> N >> R;
    
    for (int i = 0; i < N; ++i)
    {
        std::cin >> p[i].x >> p[i].y;
    }

    int MAX = 0;

    for (int i = 0; i < N; ++i)
    {
        int t = 0;

        for (int j = 0; j < N; ++j)
        {
            if (i == j)
            {
                continue;
            }

            double D = dis(p[i], p[j]);

            if (D > 2.0 * R)
            {
                continue;
            }

            double theta = atan2(p[j].y - p[i].y, p[j].x - p[i].x);

            if (theta < 0)
            {
                theta += 2 * pi;
            }
            
            double phi = acos(D / (2.0 * R));

            alp[t].v = theta - phi + 2 * pi;
            alp[t].flag = true;
            alp[t + 1].v = theta + phi + 2 * pi;
            alp[t + 1].flag = false;

            t += 2;
        }

        sort(alp, alp + t);

        int sum = 0;

        for (int j = 0; j < t; ++j)
        {
            if (alp[j].flag == true)
            {
                ++sum;
            }
            else
            {
                --sum;
            }

            if (sum > MAX)
            {
                MAX = sum;
            }
        }
    }

    std::cout << MAX + 1 << std::endl;
    
    return 0;
}
