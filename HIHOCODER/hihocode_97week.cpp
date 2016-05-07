#include <iostream>

using namespace std;

long long xx, yy, g;

void gcd(long long a, long long b)
{
	if(a % b == 0) 
	{
		xx = 0;
		yy = 1;
		g = b;	
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
	int N;
	cin >> N;
	long long m[N], r[N];
	
	for(int i = 0; i < N; i++) cin >> m[i] >> r[i];
	
	long long M = m[0], R = r[0];
	
	for(int i = 1; i < N; i++)
	{
		gcd(M, -m[i]);
		
		if((r[i] - R) % g != 0) 
		{
			cout << -1 << endl;
			return 0;
		}
		else
		{
			R = (xx * (r[i] - R) / g) % abs(m[i] / g) * M + R;
			M = M * m[i] / g;
			R = R % M;
		}
	}
	if(R < 0) R += abs(M);
	cout << R % abs(M) << endl;
	return 0;
}
