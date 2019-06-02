#include <iostream>

long long a[3][100500], sum, goal, ans = 0;

int main()
{
    int N;
    std::cin >> N;
    
    for (int i = 1; i <= N; ++i)
    {
        std::cin >> a[1][i] >> a[2][i];

        sum += a[1][i];
        sum += a[2][i];
    }

    goal = sum / (2 * N);

    for (int j = 1; j <= N; ++j)
    {
        if (a[1][j] >= goal && a[2][j] >= goal)
        {
            ans += a[1][j] - goal;
            ans += a[2][j] - goal;
            a[1][j+1] += a[1][j] - goal;
            a[2][j+1] += a[2][j] - goal;
        }
        else if (a[1][j] >= goal && a[2][j] < goal)
        {
            long long need = goal - a[2][j];
            long long have = a[1][j] - goal;
            ans += have;

            if (have >= need)
            {
                a[1][j + 1] += have - need;
                a[2][j] += need;
            }
            else
            {
                a[2][j] += need;
                a[2][j + 1] -= need - have;
                ans += (need - have);
            }
        }
        else if (a[1][j] < goal && a[2][j] >= goal)
        {
            long long need = goal - a[1][j];
            long long have = a[2][j] - goal;
            ans += have;

            if (have>=need)
            {
                a[1][j] += need;
                a[2][j + 1] += have - need;
            }
            else
            {
                a[1][j] += need;
                a[1][j + 1] -= need - have;
                ans += need - have;
            }
        }
        else if (a[1][j] < goal && a[2][j] < goal)
        {
            ans += goal - a[1][j];
            ans += goal - a[2][j];
            
            a[1][j + 1] -= goal - a[1][j];
            a[2][j + 1] -= goal - a[2][j];
        }
    }
    
    std::cout << ans << std::endl;

    return 0;
}
