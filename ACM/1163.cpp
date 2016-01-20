#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
	int N, arr[101], temp[101];
	memset(arr, 0, sizeof(arr));
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= i; j++) cin >> temp[j];
		for(int j = i; j >= 1; j--)	arr[j] = max(arr[j], arr[j - 1]) + temp[j];
	}
	int MAX = -1;
	for(int i = 1; i <= N; i++) MAX = max(MAX, arr[i]);
	cout << MAX << endl;
	return 0;
}
