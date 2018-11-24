#include <iostream>
#include <string>

using namespace std;

int main()
{
    int K;
    string s, ans;

    cin >> K >> s;

    int delete_max = s.length() - K;

    for (int i = 0; i < s.length(); ++i)
    {
        while (ans.length()!= 0 && ans.back() > s[i] && delete_max > 0)
        {
            ans.pop_back();
            --delete_max;
        }

        ans.push_back(s[i]);
    }

    cout << ans.substr(0,K) << endl;

    return 0;
}
