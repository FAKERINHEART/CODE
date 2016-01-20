#include <iostream>

using namespace std;

int main()
{
	float sum = 0;
	float sa;
	for(int i = 1; i <= 12 ; i++)
	{
		cin >> sa;
		sum += sa;
	}
	cout << "$" << sum / 12.0 << endl; 
}
