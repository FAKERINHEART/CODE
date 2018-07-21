#include <iostream>
#include <cstring>

using namespace std;
 
int main()
{
	long long dp[100001];
	int A[100];
    int N, S, sum = 0;
    
    cin >> N >> S;

    for (int i = 0; i < N; ++i)
	{
        cin >> A[i];
        sum += A[i];
    }

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    sum -= S;
    sum /= 2;
    
    for (int i = 0; i < N; ++i)
	{
        for (int j = sum; j >= A[i]; --j)
		{
            dp[j] += dp[j - A[i]];
            dp[j] %= (1000000007);
        }
    }

    cout << dp[sum] << endl;
    
    return 0;
}
