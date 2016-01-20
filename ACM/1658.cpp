#include <iostream>

using namespace std;

int main()
{
	int one, two, three, four;
	int num;
	cin >> num;
	for(int i = 0; i < num; i++)
	{
		cin >> one >> two >> three >> four;
		if(two - one == three - two && three - two == four - three) cout << one << " " << two << " " << three << " " << four << " " << 2 * four - three << endl;
		else cout << one << " " << two << " " << three << " " << four << " " << four * four / three << endl; 
	}
	return 0;
}
