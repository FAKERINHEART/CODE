#include <iostream>
#include <unordered_set>

using namespace std;

struct Point
{
    long long x_;
    long long y_;
    
    Point(long long x, long long y): x_(x), y_(y)
    {
        return;
    }
    
    bool operator==(const Point &one)const
    {
        return (one.x_ == this->x_ && one.y_ == this->y_);
    }
};

struct PointHash
{
    int operator()(const Point &point)const
    {
        return point.x_ * 31 + point.y_;
    }
};

std::unordered_set<Point, PointHash> points;
long long x[1000], y[1000];

int main()
{
    points.clear();

    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        cin >> x[i] >> y[i];
        points.insert(Point{x[i], y[i]});
    }
    
    long long ans = -1;
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            long long x1 = x[i], y1 = y[i];
            long long x2 = x[j], y2 = y[j];
            
            if (x1 != x2 && y1 != y2)
            {
                if (points.find(Point(x1, y2)) != points.end() && points.find(Point(x2, y1)) != points.end())
                {
                    long long area = std::abs(x2 - x1) * std::abs(y2 - y1);
                    
                    if (ans < 0 || area < ans)
                    {
                        ans = area;
                    }
                }
            }
        }
    }
    
    std::cout << ans << std::endl;
    
    return 0;
}