#include <iostream>

using namespace std;

int main()
{
	int num, result = 0, temp;
	cin >> num;
	for(int i = 0; i < num; i++) 
	{
		cin >> temp;
		if(temp)
		{
			switch(temp % 4)
			{
				case 0: temp -= 1;break;
				case 3: temp += 1;break;
			}
		}
		result ^= temp;
	}
	if(result) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	return 0;
}
