#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int coordination[10][2]={{0, 0}, {-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {0, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

int main()
{
	string str;
	int t, l;
	int x1, y1, x2, y2;
	long long area;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> str;
		l = str.length() - 1;
		area = 0;
		x2 = coordination[str[0] - '0'][0];
		y2 = coordination[str[0] - '0'][1];
		for(int j = 1; j < l; j++)
		{
			x1 = x2;
			y1 = y2;
			x2 += coordination[str[j] - '0'][0];
			y2 += coordination[str[j] - '0'][1];
			area += abs(x1 * y2 - x2 * y1);
		}
		cout << 1.0 * area / 2 << endl;
	}
	return 0;
} 
