#include <iostream>

using namespace std;

int main()
{
	int N, X;
    cin >> N >> X;
    
    int s = 0, a[N];
    
    for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
        s += a[i];
    }

    if (s < X)
	{
        cout << -1 << endl;
    }
    else
    {
    	int ans = 1 << 30;
    
	    for (int i = 1; i < (1 << N); ++i)
		{
	        int t = 0;
	        
			for (int j = 0; j < N; ++j)
			{
	            if (i >> j & 1)
				{
	                t += a[j];
	            }
	        }
	        
	        if(t >= X)
			{
				ans = min(ans, t);
			}
	    }
	    cout << ans << endl;
	}
    
    return 0;
}
