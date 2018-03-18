#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

double a[5000][5000], b[5000], ans[5000];
const double fbs = 1e-9;
int n, m;

bool Gauss()  
{  
    for (int k = 0, col = 0; k < m && col < n; ++k, ++col)  
    {  
        int max_r = k;
		 
        for(int i = k + 1; i < m; ++i)
		{
			if(fabs (a[i][col]) > fabs (a[max_r][col]))
			{
				max_r = i;
			}    
		}  
              
        if (fabs (a[max_r][col]) < fbs) 
		{
			return false;
		}
		
        if(k != max_r)  
        {  
            for(int j = col; j < n; ++j)  
            {  
                swap(a[k][j], a[max_r][j]);  
            }
            
            swap(b[k], b[max_r]);  
        }
		  
        b[k] /= a[k][col];
        
        for (int j = col + 1; j < n; ++j)
		{
			a[k][j] /= a[k][col];
		}  
              
        a[k][col] = 1;
		  
        for (int i = 0; i < m; ++i)
		{
		    if(i != k)  
	        {  
	            b[i] -= b[k] * a[i][col]; 
				 
	            for(int j = col + 1; j < n; ++j)
				{
					a[i][j] -= a[k][j] * a[i][col]; 
				}  
	                 
	            a[i][col] = 0;  
        	}		
		}
    }
	  
    return true;  
}

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
	int H, W, D;
	int A[110][110], B[110][110];
	cin >> H >> W >> D;
	m = (H - D + 1) * (W - D + 1);//一共有m行方程
	n = D * D;//每一个方程有n项 
	
	
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			cin >> A[i][j];
		}
	}
	
	for (int i = 0; i < H - D + 1; ++i)
	{
		for (int j = 0; j < W - D + 1; ++j)
		{
			cin >> B[i][j];
		}
	}
	
	int line_m = 0;
	
	for (int i = 0; i < H - D + 1; ++i)
	{
		for (int j = 0; j < W - D + 1; ++j)
		{
			for (int k = 0; k < D; ++k)
			{
				for (int l = 0; l < D; ++l)
				{
					a[line_m][k * D + l] = A[i + k][j + l];	
				}	
			}
			
			b[line_m] = B[i][j];
			++line_m;
		}	
	} 
	
/*	
	for(int i=1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++) cin >> a[i][j];
		cin >> b[i];
	}
*/	

	if(Gauss() == true)
	{
		for (int i = 0; i < D; ++i)
		{
			for (int j = 0; j < D; ++j)
			{
				if (b[i * D + j] > -1e-6)
				{
					b[i * D + j] += 1e-6;
				}
				else
				{
					b[i * D + j] -= 1e-6;
				}
				
				cout << round(b[i * D + j]) << " "; 
			}
			
			cout << endl;
		}
	}
	
	/*
	for(int i = 1; i <= n; i++) cout << (int)(ans[i]) << endl;
	*/
	
	return 0;
}

