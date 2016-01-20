#include <iostream>

using namespace std;

int main()
{
	const double M_PI = 3.1415926535897932384626433832795;
	float x, y;
	int num, year;
	cin >> num;
	for(int i = 1; i <= num; i++)
	{
		cin >> x >> y;
		year = (int)(M_PI * (x * x + y * y) / 100) + 1;
		cout << "Property " << i << ": This property will begin eroding in year " << year << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}
