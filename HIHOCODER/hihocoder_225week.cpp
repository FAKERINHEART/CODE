#include <iostream>

struct Point
{
    long long x;
    long long y;
};

Point point[4];

long long calculate_vector(Point vec1, Point vec2)
{
    return vec1.x * vec2.y - vec2.x * vec1.y;
}

int main()
{
    int T;
    std::cin >> T;
    
    while (T-- > 0)
    {
        for (int i = 0; i < 4; ++i)
        {
            std::cin >> point[i].x >> point[i].y;
        }
        
        Point vec1, vec2, vec3;

        vec1.x = point[1].x - point[0].x;
        vec1.y = point[1].y - point[0].y;
        vec2.x = point[2].x - point[0].x;
        vec2.y = point[2].y - point[0].y;
        vec3.x = point[3].x - point[0].x;
        vec3.y = point[3].y - point[0].y;

        long long r1, r2, r3;

        r1 = calculate_vector(vec1, vec2);
        r2 = calculate_vector(vec2, vec3);
        r3 = calculate_vector(vec3, vec1);
        
        if((r1 >= 0 && r2 >= 0 && r3 >= 0) || (r1 <= 0 && r2 <= 0 && r3 <= 0))
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
