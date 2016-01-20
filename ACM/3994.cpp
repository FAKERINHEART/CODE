#include <iostream>
 
using namespace std; 

int main()
{
	int n, num = 0;
	while(cin >> n)
	{
		if(!n) break;
		cout << ++num << ". ";
		if(n % 2) cout << "odd ";
		else cout << "even ";
		cout << n / 2 << endl;
	}
	return 0;
}
