#include <iostream>
#include <algorithm>
	
using namespace std;

struct point
{
	int x;
	int state;
};

bool cmp(point p1, point p2)
{
	return p1.x < p2.x;
}

int main()
{
	int n, m;

	point p[400010];
	cin >> n >> m;
	
	for(int i = 0; i < n + m; ++i)
	{
		cin >> p[2*i].x;
		cin >> p[2 * i + 1].x;
		
		if(i < n)
		{
			p[2 * i].state = 0;
			p[2 * i + 1].state = 1;
		}
		else
		{
			p[2 * i].state = 2;
			p[2 * i + 1].state = 3;
		}
	}
	
	sort(p, p + 2 * (n + m), cmp);
	
	int len = 0, A = 0, B = 0;
	int start;
	
	for(int i = 0; i < 2 * (n + m); ++i)
	{
		switch(p[i].state)
		{
		case 0:
			if(A == 0 && B == 0) start = p[i].x;
			++A;
			break;
		case 3:
			--B;
			if(A != 0 && B == 0) start = p[i].x;
			break;
		case 1:
			--A;
			if(B == 0 && A == 0) len += p[i].x - start;
			break;
		case 2:
			if(A != 0 && B == 0) len += p[i].x - start;
			++B;
			break;

		}
	}
	cout << len << endl;
	
	return 0;
}
