#include <iostream>

using namespace std;

int marbles[6];
int value;

bool test(int temp_value)
{
	if(temp_value > value) return false;
	else if(temp_value == value) return true;
	else
	{
		for(int i = 5; i >= 0; i--)
		{
			if(marbles[i])
			{
				marbles[i]--;
				if(test(temp_value + i + 1)) return true;
				else marbles[i]++;
			}
		}
		return false;
	}
}

int main()
{
	int sum;
	int num = 0;
	while(true)
	{
		sum = 0;
		num++;
		for(int i = 0; i < 6; i++)
		{
			cin >> marbles[i];
			sum += (i + 1) * marbles[i];
		}
		if(!sum) break;
		value = sum / 2;
		//cout << value << " " << test(0) << endl;
		if(sum % 2 || value % 2 && marbles[0] == 0 && marbles[2] == 0 && marbles[4] == 0 || !test(0))
		{
			cout << "Collection #" << num << ":" << endl;
			cout << "Can't be divided." << endl;
			cout << endl;
		}
		else
		{
			cout << "Collection #" << num << ":" << endl;
			cout << "Can be divided." << endl;
			cout << endl;
		}
	}
	return 0;
}
