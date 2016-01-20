#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

double a[1010][510], b[1010], ans[510];
const double fbs = 1e-7;
int n, m;
bool solve()
{
	for(int i = 1; i <= n; i++)
	{
		bool flag = false;
		for(int j = i; j <= m; j++) 
		{
			if(fabs(a[j][i]) > fbs)
			{    
				for(int k = i; k <= n; k++) swap(a[j][k], a[i][k]);
				swap(b[i], b[j]);
				flag = true;
				break;
			}
		}
		
		if(!flag) 
		{
			cout << "Many solutions" << endl;
			return false;
		}

		for(int j = i + 1; j <= m; j++)
		{
			double tt=a[j][i];
			for(int k = i; k <= n; k++) a[j][k] -= a[i][k] * (tt / a[i][i]);
			b[j] -= b[i] * (tt / a[i][i]);
		}
	}

	for(int i = 1; i <= m; i++)
	{
		bool flag = false;
		for(int j = 1;j <= n; j++) if(fabs(a[i][j]) > fbs)
		{
			flag = true;
			break;
		}
		if(!flag && fabs(b[i]) > fbs) 
		{
			cout << "No solutions" << endl;
			return false;
		}
	}

	for(int i = n; i >= 1; i--)
	{
		for(int j = i + 1; j <= n; j++)
		{
			b[i] -= a[i][j] * ans[j];
			a[i][j] = 0;
		}
		ans[i] = b[i] / a[i][i];
	}
	return true;
}
int main()
{
	cin >> n >> m;
	for(int i=1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++) cin >> a[i][j];
		cin >> b[i];
	}
	
	if(solve())	for(int i = 1; i <= n; i++) cout << (int)(ans[i]+0.5) << endl;
	return 0;
}
