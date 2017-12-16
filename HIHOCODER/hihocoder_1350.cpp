#include <iostream>

using namespace std;

int count(int i) 
{
    int cnt = 0;
    
    while(i)
	{
        if(i & 1)
        {
        	++cnt;
		}
            
        i >>= 1;
    }
    
    return cnt;
}
int main()
{
    int x;
   	cin >> x;
   	
   	int num[60];
    
    for (int i = 0; i < 60; ++i)
    {
    	num[i] = count(i);
	}
        
    for (int i = 0; i < 24; ++i)
	{
        for (int j = 0; j < 60; ++j)
		{
            if (num[i] + num[j] == x)
            {
            	printf("%02d:%02d\n", i, j);
			}
        }
    }
    
    return 0;
}

