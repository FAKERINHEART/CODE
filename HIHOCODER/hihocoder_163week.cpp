#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, x, y;
	
	cin >> n >> x >> y;
	
	long long seq = 0, N;
	
	for(int i = n; i > 0; --i)
	{
		N = 1ll << (i - 1);
		
		if(x <= N)
		{
			if(y <= N)//1
			{
				swap(x, y);
			}
			else//2
			{
				seq += N * N;
				y -= N;
			}
		}
		else
		{
			if(y <= N)//4
			{
				seq += 3 * N*N;
				int tempx = x;
				int tempy = y;
				x = N + 1 - tempy;
				y = 2 * N + 1 - tempx;
			}
			else//3
			{
				seq += 2 * N * N;
				x -= N;
				y -= N;
			}
		}
	}
	
	cout << ++seq << endl;
	
	return 0;
}
