#include <iostream>
#include <algorithm>

int A[100010], B[100010], C[100010];
int N, M, L;
int ans = 1e9;

void work(int *a, int *b, int *c, int n, int m, int l)
{
    for (int i = 1; i <= n; i++)
    {
        int x = std::lower_bound(b + 1, b + m + 1, a[i]) - b;

        if (x <= m)
        {
            int y = std::lower_bound(c + 1, c + l + 1, b[x]) - c;

            if (y <= l)
            {
                ans = std::min(ans, (c[y] - a[i]) * 2);
            }
        }
    }
    
    return;
}

int main()
{
    std::cin >> N >> M >> L;
    
    for (int i = 1; i <= N; ++i)
    {
        std::cin >> A[i];
    }

    for (int i = 1; i <= M; ++i)
    {
        std::cin >> B[i];
    }

    for (int i = 1; i <= L; ++i)
    {
        std::cin >> C[i];
    }

    std::sort(A + 1, A + N + 1);
    std::sort(B + 1, B + M + 1);
    std::sort(C + 1, C + L + 1);

    work(A, B, C, N, M, L);
    work(A, C, B, N, L, M);
    work(B, A, C, M, N, L);
    work(B, C, A, M, L, N);
    work(C, A, B, L, N, M);
    work(C, B, A, L, M, N);

    std::cout << ans << std::endl;

    return 0;
}
