#include <iostream>

using namespace std;

int a = 1, b = 2;


int main()
{
	int n;
	cin >> n; 
	if(n <= 1) cout << 1 << endl;
	else if(n == 2) cout << 2 << endl;
	else
	{
		int temp;
		for(int i = 1; i <= (n - 1) / 2; i++)
		{
			a = (a + b) % 19999997;
			b = (a + b) % 19999997; 
		}
		if(n % 2 == 1) cout << a << endl;
		else cout << b << endl;
	}
	return 0;
}
