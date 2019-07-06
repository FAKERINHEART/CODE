#include <iostream>
#include <cstring>

struct mat
{
    int r, c;
    int a[64][64];

    mat(int r = 0, int c = 0) : r(r), c(c)
    {
        memset(a, 0, sizeof(a));
    }
};

mat ma;

int myhash(int x, int y)
{
    return x * 8 + y;
}

void inc(int &a, int b)
{
    a += b;

    if(a >= 1000000007) a -= 1000000007;
    
    return;
}

mat mul(const mat &a, const mat &b)
{
    mat c(a.r, b.c);

    for(int i = 0; i < a.r; ++i)
    {
        for(int j = 0; j < b.c; ++j)
        {
            for(int k = 0; k < a.c; ++k)
            {
                inc(c.a[i][j], (long long)a.a[i][k] * b.a[k][j] % 1000000007);
            }
        }
    }

    return c;
}

mat pow_mod(mat a, int n)
{
    mat ret(a.r, a.c);

    for(int i = 0; i < ret.r; ++i)
    {
        ret.a[i][i] = 1;
    }

    while(n)
    {
        if (n & 1)
        {
            ret = mul(ret, a);
        }

        a = mul(a, a);
        n >>= 1;
    }

    return ret;
}

int main()
{
    int N, R, C;
    std::cin >> N >> R >> C;

    ma = mat(64, 64);

    for (int i = 0; i < 8; ++i)
    {
       for (int j = 0; j < 8; ++j)
       {
           for (int dx = -2; dx <= 2; ++dx)
           {
               if (dx == 0)
               {
                   continue;
               }

               int dy = 3 - abs(dx);
               int nx = i + dx, ny = j - dy;

               if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
               {
                   ma.a[myhash(i, j)][myhash(nx, ny)] = 1;
               }

               nx = i + dx, ny = j + dy;
               
               if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
               {
                   ma.a[myhash(i, j)][myhash(nx, ny)] = 1;
               }
           }
       }
    }

    --R, --C;
    ma = pow_mod(ma, N);

    int p = myhash(R, C);
    int ans = 0;

    for (int i = 0; i < 64; ++i)
    {
        inc(ans, ma.a[p][i]);
    }
    
    std::cout << ans << std::endl;

    return 0;
}

