#include <iostream>
using namespace std;

int main()
{
	float b;
	float c;
	int n;
	while(cin >> b && b != 0.00)
	{
		c = 0;
		n = 1;
		while(c < b)
		{
			n++;
			c += 1.0 / n;
		}
		cout << n - 1 << " " << "card(s)" << endl;
	}	
	return 0;
}
