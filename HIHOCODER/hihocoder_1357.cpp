#include <iostream>

using namespace std;

int N;

bool check(int ttime, int M, int K, int* A)
{
    int attacks = 0;
    
    for(int i = 0; i < N; ++i)
	{
        attacks -= ttime;
        
        if(attacks < 0)
		{
			attacks = 0;
		}
        
		attacks += A[i];
        
        if(attacks >= M )
		{
            --K;
            attacks = 0;
        }
    }
    
    if(K > 0)
	{
        return true;
    }
	else
	{
        return false;
    }
}

int main()
{
    int M, K;
    cin >> N >> M >> K;
    int A[N];
    
    for(int i = 0; i < N; ++i)
	{
        cin >> A[i];
    }
    
    int mid, low = 1, high = M + 1, ans = -1;
    
    while(low < high)
	{
        mid = (high + low) / 2;
        
        if(check(mid, M, K, A) == true)
		{
            high = mid;
            ans = mid;
        }
		else
		{
            low = mid + 1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
