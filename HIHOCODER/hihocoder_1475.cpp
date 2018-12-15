#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> f(N, 0);
    f[0] = 1;
    
    unordered_map<int, int> m;
    m.insert(make_pair(0, 1));

    int s = 0, total_s = 1;

    for (int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        s += x;

        f[i] = (total_s - m[s] + 1000000007) % 1000000007;

        m[s] = (m[s] + f[i]) % 1000000007;

        total_s = (total_s + f[i]) % 1000000007;
    }

    cout << f[N - 1] << endl;

    return 0;
};
