#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	const double M_PI = 3.141592654;
	int N;
	double k, h, x[101], y[101], angle1, angle2, MIN = 0, MAX = 0, sum = 0;
	cin >> k >> h >> N;
	for(int i = 0; i < N; i++) cin >> x[i] >> y[i];
	y[N] = y[0];
	x[N] = x[0];
	for(int i = 0; i < N; i++)
	{
		angle1 = atan2(y[i], x[i]);
		angle2 = atan2(y[i + 1], x[i + 1]);
		if(angle1 - angle2 > M_PI) angle2 += 2 * M_PI;
		if(angle2 - angle1 > M_PI) angle1 += 2 * M_PI;
		sum += (angle1 - angle2);
		MIN = min(MIN, sum);
		MAX = max(MAX, sum);
		if(MAX - MIN > 2 * M_PI)
		{
			MAX = MIN + 2 * M_PI;
			break; 
		} 
	}
	cout << fixed << setprecision(2) << (MAX - MIN) * k * h << endl;
	return 0;
} 
