#include <iostream>

using namespace std;
//u(0) = 1, v(1) = 1, u(2) = 3, u(n) = 2 * v(n - 1) + u(n - 2), v(n) = v(n - 2) + u(n - 1)
int main()
{
	int n;
	cin >> n;
	if(n % 2) 
	{
		cout << 0 << endl;
		return 0;	
	}
	int u = 1;
	int v = 1;
	for(int i = 1; i <= n / 2; i++)
	{
		u = (2 * v + u) % 12357;
		v = (u + v) % 12357;
	}
	cout << u << endl;
	return 0;	
} 
