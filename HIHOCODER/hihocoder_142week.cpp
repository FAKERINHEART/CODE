#include<iostream>

using namespace std;

int x[1005], y[1005], zhong[1005];

int main()
{
	int Q, i, j, n, m, ans;

	cin >> Q;
	while (Q--)
	{
		cin >> n >> m;
		
		for (i = 0; i < n; ++i)
		{
			cin >> x[i] >> y[i];
		}

		for (i = 0; i < n; ++i)
		{
			j = (i + 1) % n;
			
			if (y[i] < y[j]) zhong[i] = 0;
			if (x[i] < x[j]) zhong[i] = 1;
			if (y[i] > y[j]) zhong[i] = 2;
			if (x[i] > x[j]) zhong[i] = 3;
		}

		ans = 1;
		for (i = 0; i < n && ans; ++i)
		{
			if (zhong[i] == 0)
			{//ио
				for (j = 0; j < n; ++j)
				{
					if (zhong[j] == 2)
					{//об
						if ((zhong[(i + 1) % n] == 1 && y[(i + 1) % n] <= y[(j + 1) % n]) || y[(i + 1) % n] + m <= y[(j + 1) % n])
						{ 
							//if(i==2&&j==4)printf("x\n");
							continue; 
						}
						if ((zhong[(i + 1) % n] == 3 && y[i] >= y[j]) || y[i] >= y[j] + m)
						{
							//if (i == 2 && j == 4)printf("y\n"); 
							continue;
						}
						if (x[i] >= x[j] || x[i]+m <= x[j])
						{ 
							//if (i == 2 && j == 4)printf("z\n");
							continue;
						}
						ans = 0; 
						break;
					}
				}
			}
			if (zhong[i] == 1)
			{//ср
				for (j = 0; j < n; ++j)
				{
					if (zhong[j] == 3)
					{//вС
						if ((zhong[(i + 1) % n] == 2 && x[(i + 1) % n] <= x[(j + 1) % n]) || x[(i + 1) % n] + m <= x[(j + 1) % n])
						{
							continue;
						}
						if ((zhong[(i + 1) % n] == 0 && x[i] >= x[j]) || x[i] >= x[j] + m)
						{
							continue;
						}
						if (y[i] <= y[j] || y[i] >= y[j] + m)
						{
							continue;
						}
						
						ans = 0; 
						break;
					}
				}
			}
		}

		if (ans)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	
	return 0;
}
