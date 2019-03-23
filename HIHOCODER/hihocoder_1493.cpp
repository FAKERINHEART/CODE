#include <iostream>

using namespace std;

bool is_not_prime[1000001];

int main()
{
    for (int i = 2 ; i <= 1000000; ++i)
    {
        if(is_not_prime[i] == false)
        {
            for (int j = 2 * i; j <= 1000000; j += i)
            {
                is_not_prime[j] = true;
            }
        }
    }

    int n;

    cin >> n;

    int p = 2, q = n - 2;

    while (is_not_prime[p] == true || is_not_prime[q])
    {
        ++p;
        --q;
    }
    
    cout << p << " " << q << endl;

    return 0;
}

