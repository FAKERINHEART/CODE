#include <iostream>
#include <utility>
#include <set>
#include <deque>

std::set<std::pair<int, int>> s;
int xx[] = {0, 0, 1,-1};
int yy[] = {1,-1, 0, 0};

char get(int x, int y)
{
    if(x == 0 && y == 0)
    {
        return 'A';
    }

    long long q = std::max(std::abs(x), std::abs(y)) - 1;
    long long area = (2 * q + 1) * (2 * q + 1);//看看上一圈一共占了多少个点
    long long start = (area - 1) % 26;
    ++q;

    /*
        字符BDF...Z都会在某个位置与A相邻
        ACEG...Y在任何位置都不会与A相邻
        所以对于位置(X, Y)最多4步一定能到达。
        分情况讨论一下能不能0、1、2、3步到达，不行就输出4
     */
    if (y == q && x != -q)
    {
        start += (x + q);
        return 'A' + (start % 26);
    }
    else
    {
        start += 2 * q;
    }

    if (x == q)
    {
        start += (-y) + q;
        return 'A' + (start % 26);
    }
    else
    {
        start += 2 * q;
    }

    if (y == -q)
    {
        start += (-x) + q;
        return 'A' + (start % 26);
    }
    else
    {
        start += 2 * q;
    }

    if (x == -q)
    {
        start += y + q;
    }

    return 'A' + (start % 26);
}

int BFS(int x, int y, char c)
{
    std::deque<std::pair<int, int>> q;
    q.clear();
    s.clear();

    q.push_back(std::make_pair(x, y));
    s.insert(std::make_pair(x, y));

    while (!q.empty())
    {
        std::pair<int, int> nvex = q.front();
        q.pop_front();

        int nx = nvex.first, ny = nvex.second;

        if (get(nx, ny) == c)
        {
            return abs(nx - x) + abs(ny - y);
        }

        for (int i = 0; i < 4; ++i)
        {
            int tx = xx[i] + nx;
            int ty = yy[i] + ny;

            if (s.count(std::make_pair(tx, ty)) == 0)
            {
                q.push_back(std::make_pair(tx, ty));
                s.insert(std::make_pair(tx, ty));
            }
        }
    }
    
    return 0;
}

int main()
{
    int N, X, Y;
    
    std::cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        std::cin >> X >> Y;
        s.clear();

        int ans = abs(X) + abs(Y);

        for(char c='A'; c<='Z'; c++)
        {
            int st = BFS(0, 0, c);
            int ed = BFS(X, Y, c);
            ans = std::min(ans, st + ed + 1);
        }

        int C = get(X, Y) - 'A';

        if (C % 2 == 0 && C != 0)
        {
            if (ans > 4)
            {
                ans = 4;
            }
        }
        else if (ans > 3)
        {
            ans = 3;
        }
        
        std::cout << ans << std::endl;
    }

    return 0;
}


