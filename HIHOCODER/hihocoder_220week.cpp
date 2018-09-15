#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool visited[8];
char str[20];

void dfs(int nums, int len, int n)
{
    if (nums == n)
    {
        str[len] = '\0';
        std::cout << str + 1 << std::endl;
        return;
    }

    //先尝试后面接'-'
    if (str[len - 1] != '-')
    {
        str[len] = '-';
        dfs(nums, len + 1, n);
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i]) continue;
        if (str[len - 1] == '-' || str[len - 1] < (i + '0'))
        {
            str[len] = (i + '0');
            visited[i] = true;
            dfs(nums + 1, len + 1, n);
            visited[i] = false;
        }
    }
}

int main()
{
    int n;
    std::cin >> n;

    str[0] = '-';
    dfs(0, 1, n);

    return 0;
}

