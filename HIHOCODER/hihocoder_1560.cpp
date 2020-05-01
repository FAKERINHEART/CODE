#include <iostream>
#include <cstring>

int MOD = 1e9 + 7;

struct Matrix
{
    long long a[10][10];
    Matrix()
    {
        memset(a, 0, sizeof(a));
    }

    Matrix operator*(const Matrix &b) const
    {
        Matrix c;

        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                for (int k = 0; k < 10; ++k)
                {
                    c.a[i][j] += a[i][k] * b.a[k][j];
                    c.a[i][j] %= MOD;
                }
            }
        }

        return c;
    }
};

Matrix mod_pow(Matrix a, long long b)
{
    Matrix ans;

    for (int i = 0; i < 10; ++i)
    {
        ans.a[i][i] = 1;
    }

    while (b > 0)
    {
        if (b & 1)
        {
            ans = ans * a;
        }

        a = a * a;
        b >>= 1;
    }

    return ans;
}

int main(void)
{
    long long N, K;
    std::cin >> N >> K;

    Matrix A;

    for (int i = 0; i <= 9 && i <= K; ++i)
    {
        for (int j = 0; j <= 9 && j <= K; ++j)
        {
            if (i * j <= K)
            {
                A.a[i][j] = 1;
            }
        }
    }

    Matrix B = mod_pow(A, N - 1);

    long long ans = 0;

    for (int i = 0; i <= 9 && i <= K; ++i)
    {
        for (int j = 1; j <= 9 && j <= K; ++j)
        {
            ans = (ans + B.a[i][j]) % MOD;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
