#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double gold = (sqrt(5) + 1) / 2;
	int one, two, temp;
	while(cin >> one >> two)
	{
		temp = abs((double)(one - two));
		if(((int)(gold * temp)) == ((one < two)? one: two)) cout << "0" << endl;
		else cout << "1" << endl;
	}
	return 0;	
} 
