#include <iostream>

using namespace std;

int main()
{
	int num, Nim, result = 0;
	cin >> num;
	for(int i = 0; i < num; i++)
	{
		cin >> Nim;
		result = result ^ Nim;
	}
	
	if(result) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	return 0;
}
