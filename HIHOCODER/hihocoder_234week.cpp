#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

struct Point
{
    int x_;
    int y_;
    Point(int x, int y): x_(x), y_(y){};
    bool operator<(Point &rhs)const
    {
        return y_ < rhs.y_;
    }
};

int main()
{
    int N, M, K;
    
    std::cin >> N >> M >> K;
    
    std::vector<Point> v_point;
    
    for (int i = 0; i < K; ++i)
    {
        int R, C;
        cin >> R >> C;
        
        v_point.push_back(Point(R, C));
    }
    
    std::sort(v_point.begin(), v_point.end());
    
    long long dp[N + 1][M + 1];
    memset(dp, 0, sizeof(dp));
    
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            int now = 0;
            int last_x = 0;
            int last_y = j;
            
            for (int k = v_point.size() - 1; k >= -1; --k)
            {
                Point p = Point(i, 0);
                
                if (k != -1)
                {
                    p = v_point[k]; 
                }
                
                if (p.y_ > j || p.x_ > i || p.x_ < last_x)
                {
                    continue;
                }
                
                
                
                now += (i - last_x) * (last_y - p.y_);
                
                last_x = p.x_;
                last_y = p.y_;
            }
            
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + now;
        }
    }
    
    std::cout << dp[N][M] << std::endl;
    
    return 0;
}
