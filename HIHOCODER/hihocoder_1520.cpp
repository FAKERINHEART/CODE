#include <string>
#include <iostream>
#include <vector>
#include <cstring>

std::string s;
int x, y, sum;

std::vector<int> p;
std::vector<int> base;
int dp[201][200000];//第i个低位填的dp[i][j]余数为j

void solve()
{
    if(p.size()==0)
	{
		if(sum != 0)
		{
		    std::cout << "No solution" << std::endl;
        }
		else
        {
            std::cout << s << std::endl;
        }

		return;
	}

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i <= 9; ++i)
	{
	    dp[0][(i * base[0] + sum) % x] = i;
    }
		
	for (int i = 1; i < p.size(); ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			int start = 0;

			if (i == p.size() - 1 && s[0] == '?')
			{
			    start = 1;
            }

			for (int k = start; k <= 9; ++k)
			{
				int to = ((j - k * base[i]) % x + x) % x;

                if (dp[i - 1][to] >= 0)
				{
					dp[i][j] = k;
					break;
				}
			}
		}
	}

    int m = p.size();

    if (dp[m - 1][0] < 0)
    {
		std::cout << "No solution" << std::endl;
    }
	else
	{
		int pos = 0;

        for (int i = m - 1; i >= 0; --i)
		{
			s[p[i]] = dp[i][pos] + '0';
			pos -= dp[i][pos] * base[i];
			pos = (pos %x + x) % x;
		}

		std::cout << s << std::endl;
	}
}

int main()
{
    std::cin >> s >> x >> y;

    int b = 1;
	sum = x - y;

    for (int i = s.length() - 1; i >= 0; --i)
	{
		if(s[i]=='?')
		{
			p.push_back(i);
			base.push_back(b);
		}
		else
		{
			sum += (s[i] - '0') * b;
			sum %= x;
		}

        b = b * 10 % x;
	}

    solve();
	
	return 0;
}
