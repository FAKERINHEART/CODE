#include <iostream>
  
using namespace std;  
  
int main()  
{  
    int TASKS;
    cin >> TASKS; 
	int n, w, h, p;  
	int a[1001];
	 
    while(TASKS--) 
	{  
        cin >> n >> p >> w >> h;  
        for(int i = 0; i < n; ++i)
		{
			cin >> a[i]; 
		} 
        
		int l = 0, r = min(w, h) + 1;
		while(l < r - 1)
		{
			int m = (l + r ) >> 1;
			
			int cnt = 0;
			int num = w / m;
			
			for(int i = 0; i < n; ++i) 
			{  
        		cnt += (a[i] / num + ((a[i] % num)? 1 : 0));  
    		}
    		
    		if(cnt > p * (h / m))
    		{
    			r = m;
			}
			else 
			{
				l = m;
			}
		}
		
        cout << l << endl;  
    }  
    return 0;  
}   
