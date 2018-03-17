#include<iostream>

using namespace std;  

int N, M, L;  
int A[1000];
 
int solve(int max_length, int start_index)
{  
    int num = 0;
	  
    for (int i = 0; i < N; ++i)
	{  
        if(A[(i + start_index) % N] < max_length)
		{  
            ++num;  
            i += L - 1;  
        }
	}
	
    return num;  
}

int main()  
{  
    cin >> N >> M >> L;
	  
    for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	
    int begin = 0, end = 100000000; 
    
	while (begin <= end)
	{  
        int mid = (begin + end) / 2;  
        int num=1000000000;
		  
        for (int i = 0; i < L; ++i)
		{  
            num = min(num, solve(mid, i));  
        }
        
        if (num <= M)
		{
			begin = mid+1;
		}  
        else 
		{
			end = mid - 1;
		}  
    }  
    
    cout << end << endl;
    
    return 0;
}  

