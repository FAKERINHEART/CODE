#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int N, SUM = 0, last;
	cin >> N;
	last = (int)(sqrt(1 + 8 + 8 * N) - 1) / 2;
	SUM = (2 + last) * (last - 1) / 2;
	for(int j = 2; j <= last; j++)
	{
		if(j >= last + 1 - (N - SUM) % (last + 1))
		{
			if(j != last) cout << j + 1 << " ";
			else
			{
				if(last == (N - SUM)) cout << j + 2 << " ";
				else cout << j + 1 << " ";
			}
		}
		else cout << j << " ";
	}
	cout << endl;
	
	return 0;
} 
