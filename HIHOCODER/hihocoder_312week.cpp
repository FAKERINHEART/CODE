#include <iostream>
#include <vector>

std::vector<int> ve[100001];
int ans;

int dfs(int x, int p)
{
    int num = 1;

    for (int i = 0; i < (int)ve[x].size(); ++i)
    {
        int y = ve[x][i];

        if (y == p)
        {
            continue;
        }

        int temp_num = dfs(y, x);

        if ((temp_num & 1) == 0)
        {
            ++ans;
        }
        
        num += temp_num;
    }

    return num;
}

int main()
{
    int N;
    std::cin >> N;

    int x, y;

    for (int i = 1; i < N; ++i)
    {
        std::cin >> x >> y;
        ve[x].push_back(y);
        ve[y].push_back(x);
    }

    dfs(1, 0);
    std::cout << ans << std::endl;

    return 0;
}

