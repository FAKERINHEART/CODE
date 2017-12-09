#include <iostream> 
#include <cstring>

using namespace std;

const long long MOD=1e9+7;
int k1, k2;

struct Mat 
{
    long long data[2][2];
};

Mat multi(const Mat &a, const Mat &b)
{
    Mat c;
    c.data[0][0] = c.data[0][1] = c.data[1][0] = c.data[1][1] = 0;
    
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                c.data[i][j] += a.data[i][k] * b.data[k][j];
                c.data[i][j] %= MOD;
            }
        }
    }
    
    return c;
}

Mat POW(long long n)
{
    Mat res, a;
    res.data[0][0] = res.data[1][1] = 1;//单元矩阵
	res.data[0][1] = res.data[1][0] = 0;
	a.data[0][0] = k1;
	a.data[0][1] = 1;
    a.data[1][0] = k2;
    a.data[1][1] = 0;

    while (n)
    {
        if (n & 1) 
		{
			res = multi(res,a);	
		}
        a = multi(a, a);    
		n >>= 1;
    }
    
    return res;
}

long long QPOW(long long x, long long n)
{
    long long res=1;
    
    while (n)
    {
        if(n & 1)
        {
        	res = (res * x) % MOD;
		}
		
        x = (x * x) % MOD;
        n >>= 1;
    }
    
    return (res % MOD + MOD) % MOD;
}

int main()
{
    long long x, y, Ax, Ay, z;
    
    cin >> k1 >> k2;
	cin >> x >> y >> Ax >> Ay >> z;
    
	Mat kx = POW(x - 3);//Ax跟原始矩阵的距离 
    Mat ky = POW(y - 3);//Ay跟原始矩阵的距离 
    
    //求原始矩阵的系数 
    long long A0 = ((Ax * ky.data[0][0] % MOD - Ay * kx.data[0][0] % MOD + MOD) % MOD) * QPOW((kx.data[1][0] * ky.data[0][0] % MOD - kx.data[0][0] * ky.data[1][0] % MOD + MOD) % MOD, MOD - 2) % MOD;
    long long A1 = ((Ax - kx.data[1][0] * A0 % MOD + MOD) % MOD) * QPOW((kx.data[0][0] + MOD) % MOD, MOD - 2) % MOD;

    Mat kz = POW(z - 3);
    
	cout << (A1 * kz.data[0][0] % MOD + A0 * kz.data[1][0] % MOD + MOD) % MOD << endl;
    
	return 0;
}

