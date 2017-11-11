#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int array[N];
	for(int i = 0; i < N; i++) cin >> array[i];
	int j;
	for(j = N - 2; j >= 0; j--) if(array[j] > array[j + 1]) break;
	if(j < 0) cout << array[0] << endl;
	else
	{
		for(int i = 0; i <= j; i++) cout << array[i] << " ";
		cout << endl;
	} 
	return 0;
}
