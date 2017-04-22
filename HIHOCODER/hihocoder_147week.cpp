#include <iostream> 
#include <bitset>
#include <algorithm>

using namespace std;

int a[30000], b[30000], c[30000], d[30000], e[30000];//每一个科目一个排名位置上的人的序号 
bitset<30000> A[30000], B[30000], C[30000], D[30000], E[30000], F;

int main()
{
	int N, temp_a, temp_b, temp_c, temp_d, temp_e;
	
	cin >> N;
	 
	for(int i = 0; i < N; ++i)
	{
		cin >> temp_a >> temp_b >> temp_c >> temp_d >> temp_e;
		
		a[temp_a - 1] = b[temp_b - 1] = c[temp_c - 1] = d[temp_d - 1] = e[temp_e - 1] = i;
	}
	
	for(int i = 1; i < N; ++i)
	{
		A[a[i]] = A[a[i - 1]];
		A[a[i]][a[i - 1]] = 1;
		B[b[i]] = B[b[i - 1]];
		B[b[i]][b[i - 1]] = 1;
		C[c[i]] = C[c[i - 1]];
		C[c[i]][c[i - 1]] = 1;
		D[d[i]] = D[d[i - 1]];
		D[d[i]][d[i - 1]] = 1;
		E[e[i]] = E[e[i - 1]];
		E[e[i]][e[i - 1]] = 1;
	}
	
	for(int i = 0; i < N; ++i)
	{
		F = A[i] & B[i] & C[i] & D[i] & E[i];
		cout << F.count() << endl;
	}
	
	return 0;	
}
