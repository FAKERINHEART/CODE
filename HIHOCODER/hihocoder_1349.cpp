#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    if(n == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        long long sum = 0, num = 9, len = 1;

        while(n > sum + num * len)
        {
            sum = sum + num * len;

            ++len;
            num = num * 10;
        }

        num = (num / 9) - 1;
        n = n - sum;

        num = num + ceil(n * 1.0 / len);
        n = (n % len == 0?0: len - n % len);


        //cout << num << endl;
        //cout << n << endl;
        for(int i = 0; i < n; ++i)
        {
            num = num / 10;
        }
        cout << num % 10 << endl;
    }

    return 0;
}
