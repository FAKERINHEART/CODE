#include <iostream>

using namespace std;

int N;
double A[50];
int B[50];
int yuwang;

void check(double sum_temp, int yuwang_temp)
{
	if(int(sum_temp) == sum_temp && int(sum_temp) % 5 == 0 && yuwang_temp > yuwang)
	{
		yuwang = yuwang_temp;
	}
	return;
}

int main()
{
	int Q, N;
	cin >> Q;
	while(Q--)
	{
		cin >> N;
		for(int i = 0; i < N; i++) cin >> A[i] >> B[i];
		yuwang = 0;
		
		double sum_temp;
		int yuwang_temp;
		for(int i = 0; i < N; i++)
		{
			sum_temp = A[i];
			yuwang_temp = B[i];
			check(sum_temp, yuwang_temp);
			for(int j = i + 1; j < N; j++)
			{
				sum_temp = A[i] + A[j];
				yuwang_temp = B[i] + B[j];
				check(sum_temp, yuwang_temp);
				for(int k = j + 1; k < N; k++)
				{
					sum_temp = A[i] + A[j] + A[k];
					yuwang_temp = B[i] + B[j] + B[k];
					check(sum_temp, yuwang_temp);
				}
			}
		}
		cout << yuwang << endl;
	} 
	return 0;
} 
