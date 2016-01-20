#include <iostream>

using namespace std;

int mem[14] = {0};
int num, _mod, temp_num, temp, _even;

void test(int num)
{
	if(mem[num]) return;
	_mod = num + 1;
	while(1)
	{
		temp = 1;
		temp_num = num * 2;
		for(int i = 1; i <= num; i++)
		{
			temp = (_mod + temp - 1) % temp_num;
			if(temp == 0) temp = temp_num; 	
			if(temp <= num) break;
			temp_num--;
		}
		
		if(temp_num == num) break;
		_mod++;
		if(_mod % (2 * num) == 1) _mod += num;
	}	
	mem[num] = _mod;
	return;
}

int main()
{
	while(cin >> num)
	{
		if(!num) break;
		test(num);
		cout << mem[num] << endl;		
	}
	return 0;
}
