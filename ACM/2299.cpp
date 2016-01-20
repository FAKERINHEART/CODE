#include <iostream>
#include <cstring> 

using namespace std;

int array[500001][2];
long long sum;
int n;

int Merge(int b, int m, int be, int mi)
{
	int k = 0, i = b, j = m;
	while(i && j)
	{
		if(array[i][0] <= array[j][0])
		{
			array[k][1] = i;
			k = i;
			i = array[i][1];
			be++;
		}
		else
		{
			array[k][1] = j;
			k = j;
			j = array[j][1];
			sum += (mi - be);
		}
	}
	if(!i) array[k][1] = j;
	else array[k][1] = i;
	return array[0][1];
}  

int MergeSort(int b, int e)
{
	if(b >= e) return b;
	int m = (b + e) / 2;
	return Merge(MergeSort(b, m), MergeSort(m + 1, e), b, m + 1);
}

int main()
{
	while(cin >> n)
	{
		if(n == 0) break;
		memset(array, 0, sizeof(array));
		for(int i = 1; i <= n; i++) cin >> array[i][0];
		sum = 0;
		MergeSort(1, n);
		/*
		int k = array[0][1];
		while(k)
		{
			cout << array[k][0] << " ";
			k = array[k][1];
		}
		cout << endl;
		*/
		cout << sum << endl;
	}
	return 0;
} 
