#include <iostream>

using namespace std;

int main()
{
	int n, r = 0;
	char c;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> c;
		if(c == 'H') r ^= i; 
	}
	if(r) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	return 0;	
}
