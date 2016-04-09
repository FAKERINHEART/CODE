#include <iostream>
#include <cmath>

using namespace std;

long long divid[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
long long n;
long long u0;

long long multi_mod(long long d, long long m, long long p) // (d * m) % p 
{
	long long d1 = 0;
	while(m)
	{
		if(m & 1) d1 = (d1 + d) % p;
		m >>= 1;
		d = (d + d) % p; 
	}
	return d1;
}

long long exp_mod(long long d, long long m, long long p) // (d ^ m) % p
{
	long long d1 = 1;
	while(m)
	{
		if(m & 1) d1 = multi_mod(d1, d, p);
		m >>= 1;
		d = multi_mod(d, d, p);
	}
	return d1;
}

bool isprime()
{
	if(n == 2) return true;
	if(n == 1) return false;
	if(n & 1 == 0) return false;
	
	long long u;
	long long x, y;
	for(int i = 0; i < 12; i++)
	{
		if(divid[i] >= n) break;
		u = u0;
		x = exp_mod(divid[i], u, n);
			
		while(u < n)
		{
			y = multi_mod(x, x, n);
			if(y == 1 && x != 1 && x != n - 1) return false; 
			x = y;
			u <<= 1;
		} 
		
		if(x != 1) return false;
	}
	return true;
}

int main()
{
	
	int t;
	cin >> t;
	
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		u0 = n - 1;
		while(u0 & 1 == 0) u0 >>= 1;
		if(isprime()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
