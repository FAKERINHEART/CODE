#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int array[3];
	
    cin >> array[0] >> array[1] >> array[2];
    sort(array, array + 3);
    
    //cout << array[0] << endl;
    int num = 0;
    
    while(array[2] > 0) 
	{
        int MAX = 0;
        int temp[3];
        
        for(int i = 0; i <= array[0]; ++i)
		{
            if (i > 20)
			{
            	break;	
			}
            
            for(int j = 0; j <= array[1]; ++j) 
			{
                if (i + j > 20)
				{
					break;
				}
                
                for (int k = 0; k <= array[2]; ++k)
				{
                    int sum = i + j + k;
                    
                    if(sum > 20)
					{
						break;
					}
                    else if(sum > 15 && max(i, max(j, k)) * 2 > sum)
					{
						continue;
					}
                    else if(sum > MAX)
					{
                        MAX = sum;
                        temp[0] = i;
                        temp[1] = j;
                        temp[2] = k;
                    }
                }
            }
        }
        
        for (int i = 0; i < 3; ++i) {
            array[i] -= temp[i];
        }
        sort(array, array + 3);
        ++num;
    }
    cout << num * 6 << endl;
    
	return 0;
}
