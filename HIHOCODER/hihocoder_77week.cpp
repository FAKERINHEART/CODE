#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int T;
	cin >> T;
	long long i, n;
	while(T--)
	{
		cin >> i >> n;
		while(1)
		{
			if(i % 4 == 2 || i % 4 == 3 || n == 0)
			{
				cout << n << endl;
				break;
			}
			else
			{
				i = ceil(i * 1.0 / 4);
				n--;
			}
		}
	}
	return 0;
}
