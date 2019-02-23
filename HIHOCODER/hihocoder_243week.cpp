#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    if (str.length() < 4)
    {
        cout << -1 << endl;
        return 0;
    }
    
    int l = 0, ans = str.length() + 1, h = 0,i = 0, o = 0;

    for(int r = 0; r < str.length(); ++r)
    {
        if (str[r] == 'h')
        {
            ++h;
        }
        else if (str[r] == 'i')
        {
            ++i;
        }
        else if (str[r]=='o')
        {
            ++o;
        }

        while (h >= 2 && i >= 1 && o >= 1)
        {
            if(h == 2 && i==1 && o==1)
            {
                ans = min(ans, r - l + 1);
            }
            
            if(str[l] == 'h')
            {
                --h;
            }
            else if (str[l] == 'i')
            {
                --i;
            }
            else if (str[l]=='o')
            {
                --o;
            }

            ++l;
        }
    }

    if (ans == str.length() + 1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }

    return 0;
}

