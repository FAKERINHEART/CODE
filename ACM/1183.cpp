#include <iostream>

using namespace std;

int main()
{
	long long a;
	cin >> a;
	int m;
	for(m = a; m >= 1; m--) if(!((a * a + 1) % m)) break;
	cout << 2 * a + m + (a * a + 1) / m << endl;
	return 0;
}
