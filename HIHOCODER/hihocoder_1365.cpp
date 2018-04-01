#include <iostream>
#include <algorithm>

using namespace std;

int M, N, w[100001], h[100001], first_h[100001];//first_h为当第i部分为行首时, 以i为第一行的排好版的高度总和 

void calculate_line_before(int i, int &wi, int &hi)
{
    if (wi + w[i] > M)
    {
    	hi = max(hi, (int)ceil(1.0 * (M - wi) * h[i] / w[i]));
	}
    else
    {
    	hi = max(hi, h[i]);
	}
        
    wi = min(M, wi + w[i]);
    
    return;
}

int calculate_after_line_height(int i, int wi, int hi)
{
    while (i < N && wi < M)
    {
    	calculate_line_before(i, wi, hi);
    	++i;
	}
        
    return hi + first_h[i];
}

int main()
{
    cin >> M >> N;
    
    for (int i = 0; i < N; ++i)
    {
    	cin >> w[i] >> h[i];
	}
	
	for (int i = N - 1; i >= 0; --i)
	{
		//计算first_h
		first_h[i] = calculate_after_line_height(i, 0, 0);
	}
    
    int ans, wi, hi, pre_h, temp_h;
    ans = 10000000, wi = hi = pre_h = 0;
	 
    for (int i = 0; i < N; ++i)
    {
        temp_h = calculate_after_line_height(i + 1, wi, hi);
        ans = min(ans, pre_h + temp_h);
        calculate_line_before(i, wi, hi);
        
        if (wi == M)
        {
            pre_h += hi;
            wi = hi = 0;
        }
    }
    cout << ans << endl;
    
	return 0;
}  
