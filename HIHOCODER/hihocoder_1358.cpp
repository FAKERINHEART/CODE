#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	int N, K;
	int A[15];
	double B[15];

    cin >> N >> K;
    
    for (int i = 0; i < K; ++i)
    {
        cin >> A[i];
    }
    
    for (int i = 0; i < K; ++i)
    {
        double temp;
        cin >> temp;
        
        B[i] = 1.0 / temp;
    }
    
    while (N--)
    {
        int p = -1;
        double val = 0;
        
        for (int i = 0; i < K; ++i)
        {
            double temp = pow((A[i] + 1.0) / A[i], B[i]);
            
            if (temp > val)
            {
                p = i;
                val = temp;
            }
        }
        
        ++A[p];
    }
    
    double result = 1.0;
    
	for (int i = 0; i < K; ++i)
    {
        result *= pow(A[i], B[i]);
    }
    
	cout << fixed << setprecision(3) << result << endl;
    
	return 0;
}
