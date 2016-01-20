#include <iostream>

using namespace std;

long long xx, yy, r;

void gcd(long long a, long long b)
{
	if(b == 0) 
	{
		xx = 1;
		yy = 0;
		r = a;	
		return;
	}
	
	gcd(b, a % b);
	long long temp_xx, temp_yy;
	temp_xx = xx;
	temp_yy = yy;
	yy = temp_xx - a / b * temp_yy;
	xx = temp_yy;
	return;
}

int main()
{
	long long x, y, m, n, L;
	cin >> x >> y >> m >> n >> L;
	gcd(L, n- m);
	if((x- y) % r) cout << "Impossible" << endl;
	else cout << ((yy * (x - y) / r) % (L / r) + (L / r)) % (L / r) << endl;	
	return 0;
}
