#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dpM[101][1001], dpF[101][1001];
long long recM[101][1001][2], recF[101][1001][2];

int main()
{
	int n, nMale, nFemale, B;
	cin >> n >> nMale >> nFemale >> B;
	
	for(int i = 0; i <= n; i++) for(int j = 0; j <= B; j++)	dpM[i][j] = dpF[i][j] = -1;
	memset(recM, 0, sizeof(recM));
	memset(recF, 0, sizeof(recF));
	int cntM = 0, cntF = 0, sum = 0;
	dpM[0][0] = dpF[0][0] = 0;
	
	char gendle;
	int value, salary;
	for(int i = 1; i <= n; i++)
	{
		cin >> gendle >> value >> salary;
		sum += salary;
		sum = min(sum, B);
		
		if(gendle == 'M')
		{
			cntM++;
			cntM = min(cntM, nMale);
			for(int j = cntM; j >= 1; j--)
			{
				for(int k = sum; k >= salary; k--)
				{
					if(dpM[j - 1][k - salary] >= 0 && dpM[j - 1][k - salary] + value > dpM[j][k])
					{
						dpM[j][k] = dpM[j - 1][k - salary] + value;
						recM[j][k][0] = recM[j - 1][k - salary][0];
						recM[j][k][1] = recM[j - 1][k - salary][1];
						if(i - 1 < 50) recM[j][k][0] |= 1ll << (i - 1);
						else recM[j][k][1] |= 1ll << (i - 1 - 50);
					} 
				}
			}
		}
		else
		{
			cntF++;
			cntF = min(cntF, nFemale);
			for(int j = cntF; j >= 1; j--)
			{
				for(int k = sum; k >= salary; k--)
				{
					if(dpF[j - 1][k - salary] >= 0 && dpF[j - 1][k - salary] + value > dpF[j][k])
					{
						dpF[j][k] = dpF[j - 1][k - salary] + value;
						recF[j][k][0] = recF[j - 1][k - salary][0];
						recF[j][k][1] = recF[j - 1][k - salary][1];
						if(i - 1 < 50) recF[j][k][0] |= 1ll << (i - 1);
						else recF[j][k][1] |= 1ll << (i - 1 - 50);
					} 
				}
			}
		}
	}
	
	//×éºÏ
	int ans = -1, count = 0;
	long long record[2] = {0};
	for(int i = 0; i <= B; i++)
	{
		if(dpM[nMale][i] < 0) continue;
		for(int j = 0; j <= B - i; j++)
		{
			if(dpF[nFemale][j] < 0) continue;
			
			if(dpM[nMale][i] + dpF[nFemale][j] > ans || dpM[nMale][i] + dpF[nFemale][j] == ans && count > i + j)
			{
				ans = dpM[nMale][i] + dpF[nFemale][j];
				count = i + j;
				record[0] = recM[nMale][i][0] | recF[nFemale][j][0];
				record[1] = recM[nMale][i][1] | recF[nFemale][j][1];
			}
			else if(dpM[nMale][i] + dpF[nFemale][j] == ans && count == i + j)
			{
				long long record0 = recM[nMale][i][0] | recF[nFemale][j][0];
				long long record1 = recM[nMale][i][1] | recF[nFemale][j][1];
				if(record0 < record[0] || record0 == record[0] && record1 < record[1])
				{
					record[0] = record0;
					record[1] = record1;
				}
			}
		}	
	} 
	
	cout << ans << " " << count << endl;
	
	for(int i = 1; i <= 50; i++)
	{
		if(record[0] & 1) cout << i << " ";
		record[0] >>= 1;
	}
	
	for(int i = 51; i <= 100; i++)
	{
		if(record[1] & 1) cout << i << " ";
		record[1] >>= 1;
	}
	cout << endl;
	
	return 0;	
} 
