#include <iostream>

using namespace std;

int main()
{
	int p, e, i, d, n = 0;
	while(cin >> p >> e >> i >> d && p != -1 && e != -1 && i != -1 && d != -1)
	{
		n++;
		p %= 23;
		e %= 28;
		i %= 33;
		int j = 1;
		while(j % 23 != p || j % 28 != e || j % 33 != i) j++;
		if(j <= d) j = j + 21252;
		cout << "Case " << n << ": the next triple peak occurs in " << j - d << " days." << endl;
	}
	return 0;
} 
