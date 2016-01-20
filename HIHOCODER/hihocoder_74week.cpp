#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double y, x;
	cin >> y;
	if(y >= 0 && y <= 45) x = y / 0.03 + 3500;
	else if(y >= 45 && y <= 345) x = (y - 45) / 0.1 + 5000;
	else if(y >= 345 && y <= 1245) x= (y - 345) / 0.2 + 8000;
	else if(y >= 1245 && y <= 7745) x = (y - 1245) / 0.25 + 12500;
	else if(y >= 7745 && y <= 13745) x = (y - 7745) / 0.3 + 38500;
	else if(y >= 13745 && y <= 22495) x = (y - 13745) / 0.35 + 58500;
	else x = (y - 22495) / 0.45 + 83500;
	cout << int(floor(x)) << endl;
	return 0;
}
