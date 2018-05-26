#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    int L,F,D;

    cin >> T;

    while(T--)
    {
        cin >> L >> F >> D;
        cout << (F <= __gcd(L,D)?"YES": "NO") << endl;
    }

    return 0;
}

