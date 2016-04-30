#include <iostream>

using namespace std;

long long xx, yy, r;

void gcd(long long a, long long b)
{
	if(a % b == 0) 
	{
		xx = 0;
		yy = 1;
		r = b;	
		return;
	}
	
	gcd(b, a % b);
	long long temp_xx, temp_yy;
	temp_xx = xx;
	temp_yy = yy;
	xx = temp_yy;
	yy = temp_xx - a / b * temp_yy;
	return;
}

int main()
{
	long long x, y, m, n, L;
	cin >> x >> y >> m >> n >> L;
	
	gcd(L, n - m);
	
	if((x - y) % r) cout << "Impossible" << endl;
	else
	{
		long long ret = yy * (x - y) / r;
		
		while(ret < 0)
		{
			ret += abs(L / r);
		}
		cout << ret % abs(L / r) << endl;
	} 	
	return 0;
}
