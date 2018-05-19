#include <iostream>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

struct point
{
    int x;
    int y;

    point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    bool operator<(const point &p)const
    {
        if (p.x < x)
        {
            return true;
        }
        else if (p.x == x)
        {
            return p.y < y;
        }
        else
        {
            return false;
        }
    }

    bool operator==(const point &p)const
    {
        return (x == p.x && y == p.y);
    }
};

int h, w;
char image[501][501];
bool visible[501][501] = {0};

double dist(point& p1, point& p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

point bfs(point head, int& min_x, int& min_y, int& max_x, int& max_y)
{
    int move[8][2] = { {1, 0}, {1, 1}, {1, -1}, {-1, 0}, {-1, 1}, {-1, -1}, {0, 1}, {0, -1} };

    queue<point> q;
    set<point> s;
    q.push(head);
    s.insert(head);
    visible[head.x][head.y] = true;

    point tmp(0, 0);

    while (q.empty() == false)
    {
        tmp = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i)
        {
            int x = tmp.x + move[i][0];
            int y = tmp.y + move[i][1];
            point node(x, y);
            if (x >= 0 && x < h && y >= 0 && y < w && image[x][y] == '#' && s.count(node) == 0)
            {
                q.push(node);
                s.insert(node);
                visible[x][y] = true;

                min_x = min(x, min_x);
                max_x = max(x, max_x);
                min_y = min(y, min_y);
                max_y = max(y, max_y);
            }
        }
    }

    return tmp;
}

int main()
{
    cin >> h >> w;

    int m = 0;
    int s = 0;

    for (int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            cin >> image[i][j];
        }
    }

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (image[i][j] == '.' || visible[i][j] == true)
            {
                continue;
            }

            int min_x = i, min_y = j, max_x = i, max_y = j;

            point node(i, j);
            point p1 = bfs(node, min_x, min_y, max_x, max_y);
            point p2 = bfs(p1, min_x, min_y, max_x, max_y);

            point middle((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
            point center((min_x + max_x) / 2, (min_y + max_y) / 2);

            double dist1 = dist(p1, p2);
            double dist2 = dist(middle, center);

            if (dist2 / dist1 < 0.4)
            {
                ++s;
            }
            else
            {
                ++m;
            }
        }
    }

    cout << m << ' ' << s;

    return 0;
}
