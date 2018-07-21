#include <iostream>
#include <cstring>

int main() 
{
	long long bit[32];
	memset(bit, 0, sizeof(bit));
	
    int N;
    std::cin >> N;
    
    for (int i = 0; i < N; ++i)
	{
        long long A, j = 0;
        std::cin >> A;
        
        while (A != 0) 
		{
            bit[j++] += (A & 1);
            A >>= 1;
        }
    }
    
    long long ans = 0;

    for (int i = 0; i < 32; ++i)
	{
        ans = ans + bit[i] * (N - bit[i]);
    }

    std::cout << ans << std::endl;

    return 0;

}

