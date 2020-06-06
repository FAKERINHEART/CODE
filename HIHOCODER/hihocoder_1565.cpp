#include <iostream>

int A[100001];
int ans[100001];

int main()
{
    int N, Q;

    std::cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        std::cin >> A[i];
    }

    std::cin >> Q;

    for (int i = 1; i <= 6; ++i)
    {
        ans[i] = -1;
    }

    int op, Y, u, v;

    while (Q--)
    {
        std::cin >> op;

        if (op == 1)
        {
            std::cin >> Y;

            if (ans[Y] == -1)
            {
                for (int i = N; i >= 1; i--)
                {
                    if (A[i] + i > N)
                    {
                        ans[i] = 1;
                    }
                    else
                    {
                        ans[i] = ans[A[i] + i] + 1;
                    }
                }
            }

            std::cout << ans[Y] << std::endl;
        }
        else
        {
            std::cin >> u >> v;

            A[u] = v;

            for (int i = 1; i <= 6; i++)
            {
                ans[u] = -1;
            }
        }
    }
    return 0;
}

