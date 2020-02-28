#include <iostream>
#include <map>
#include <utility>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    std::map<char, int> m;
    m['u'] = 0;
    m['r'] = 1;
    m['d'] = 2;
    m['l'] = 3;

    int N, M;
    char ans[400][400];

    std::cin >> N >> M;

    for (int i = 0; i <= 2 * N; ++i)
    {
        for (int j = 0; j <= 2 * M; ++j)
        {
            ans[i][j] = ' ';
        }
    }

    int pos_x = 1, pos_y = 1, dir = 2;

    for (int i = 0; i < 2 * N * M - 1; ++i)
    {
        int a, b, c;
        char d;

        std::cin >> a >> b >> c >> d;

        if (a == 1)
        {
            ans[pos_x + dx[(dir + 3) % 4]][pos_y + dy[(dir + 3) % 4]] = '-';
        }

        if (b == 1) 
        {
            ans[pos_x + dx[dir]][pos_y + dy[dir]] = '-';
        }

        if (c == 1)
        {
            ans[pos_x + dx[(dir + 1) % 4]][pos_y + dy[(dir + 1) % 4]] = '-';
        }

        dir = m[d];
        pos_x += dx[dir] * 2;
        pos_y += dy[dir] * 2;
    }

    for (int i = 0; i <= N; ++i)
    {
        for (int j = 0; j <= M; ++j)
        {
            ans[2 * i][2 * j] = '+';
        }
    }

    for (int i = 1; i <= 2 * N; i += 2)
    {
        for (int j = 0; j <= 2 * M; ++j)
        {
            if (ans[i][j] == '-')
            {
                ans[i][j] = '|';
            }
        }
    }

    for (int i = 0; i <= 2 * N; ++i)
    {
        for (int j = 0; j <= 2 * M; ++j)
        {
            std::cout << ans[i][j];
        }

        std::cout << std::endl;
    }

    return 0;
}

