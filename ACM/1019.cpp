#include <iostream>
#include <math.h>

using namespace std;

long long Sum[31269];
long long Bit[31269];

int main()
{
	Bit[0] = 0;
	Sum[0] = Bit[0];
	for(int i = 1; i <= 31268; i++)
	{
		Bit[i] = Bit[i - 1] + ((int)log10(i) + 1);
		Sum[i] = Sum[i - 1] + Bit[i];
	}
	//cout << Sum[12] << " " << Bit[12] << endl;
	
	long long num_case, num;
	cin >> num_case;
	for(int i = 0; i < num_case; i++)
	{
		cin >> num;
		int j;
		for(j = 1; j <= 31268; j++) if(Sum[j] >= num) break;
		//cout << j - 1 << " " << Sum[j - 1] << endl;
		int k;
		for(k = 1; k <= 31268; k++)	if(Sum[j - 1] + Bit[k] >= num) break;
		//cout << k << " " << Bit[k] << endl;
		int Sub = Sum[j - 1] + Bit[k] - num;
		cout << k % ((int)pow(10, Sub + 1)) / ((int)pow(10, Sub)) << endl;
 	}
	return 0;
}
