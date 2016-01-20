#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int cr = 0, cb = 0, cy = 0;
	int d1, d2, d3;
	cin >> d1 >> d2 >> d3;
	string str;
	cin >> str;
	int length = str.length();
	int MAX = 0;
	for(int i = 0; i < length; i++)
	{
		if(str[i] == 'R') cr++;
		else if(str[i] == 'Y') cy++;
		else cb++;
		MAX = max(MAX, cr + cy + cb);
		
		if(abs(cr - cy) == d1 && abs(cy - cb) == d2 && abs(cb - cr) == d3
		|| abs(cr - cy) == d1 && abs(cy - cb) == d3 && abs(cb - cr) == d2
		|| abs(cr - cy) == d2 && abs(cy - cb) == d3 && abs(cb - cr) == d1
		|| abs(cr - cy) == d2 && abs(cy - cb) == d1 && abs(cb - cr) == d3
		|| abs(cr - cy) == d3 && abs(cy - cb) == d1 && abs(cb - cr) == d2
		|| abs(cr - cy) == d3 && abs(cy - cb) == d2 && abs(cb - cr) == d1)
			cr = cb = cy = 0;	
	}
	
	cout << MAX << endl;
	return 0;	
} 
