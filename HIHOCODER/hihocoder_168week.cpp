#include <iostream>

using namespace std;

int cal(int n)
{
	if(n == 0 || n == 1) return 1;
	else if(n % 2)
	{
		return cal((n - 1) / 2);
	}
	else
	{
		return cal(n / 2) + cal((n - 2) / 2);
	}
}

int main()
{
	int n;
	cin >> n;
	
	cout << cal(n) << endl;
	
	return 0;
} 
