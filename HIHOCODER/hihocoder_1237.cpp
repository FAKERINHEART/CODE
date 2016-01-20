#include <iostream>
#include <cmath>

using namespace std;

double x, y, r;
int bx, by;
double best;

void get(int ix, int iy)
{
	if(abs((ix - x) * (ix - x) + (iy - y) * (iy - y) - r * r) < best)
	{
		bx = ix;
		by = iy;
		best = abs((ix - x) * (ix - x) + (iy - y) * (iy - y) - r * r);
	}
	else if(abs((ix - x) * (ix - x) + (iy - y) * (iy - y) - r * r) == best)
	{
		if(ix > bx || ix == bx && iy > by) 
		{
			bx = ix;
			by = iy;
			best = abs((ix - x) * (ix - x) + (iy - y) * (iy - y) - r * r);
		}
	}
	return;
}

int main()
{
	cin >> x >> y >> r;
	int ileftx, irightx, y1, y2;
	ileftx = floor(x - r);
	irightx = ceil(x + r);
	
	bx = 0, by = 0;
	best = abs(x * x + y * y - r * r);
	
	for(int i = ileftx; i <= irightx; i++)
	{
		y1 = floor(y + sqrt(r * r - (i - x) * (i - x)));
		get(i, y1);
		y2 = ceil(y - sqrt(r * r - (i - x) * (i - x)));
		get(i, y2);
	}
	cout << bx << " " << by << endl;
	return 0;
}
