#include <iostream>
#include <string>
#include <cstring>

int cnt[7], num[10], cnt_person[10][7];

bool win()
{
	if (cnt[0] == 5 || cnt[1] == 5 || cnt[2] == 5 || cnt[3] == 5)
	{
	    return true;
    }

	if(cnt[4] > 0 && cnt[3] == 0 && cnt[0] + cnt[1] + cnt[2] > 0)
    {
        return true;
    }

	if(cnt[5] > 0 && cnt[1] == 0 && cnt[0] + cnt[2] + cnt[3] > 0)
	{
	    return true;
    }
	if(cnt[6] > 0 && cnt[0] + cnt[1] + cnt[2] + cnt[3] > 0)
	{
	    return true;
    }

	return false;
}

int main()
{
	int n, k;

	std::cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
	    num[i] = 10000000;
    }
		
	int now_person = 0;

	while(k--)
	{
		std::string s;
        int param1;
        
        std::cin >> s >> param1;

		if(s[0] == 'R')
		{
			if(win() == true)
			{
				num[param1] = n * 10000000;

				for(int i = 0; i < n; ++i)
				{
				    if(i != param1)
				    {
				        num[param1] -= num[i];
                    }
                }
					
				memset(cnt, 0, sizeof cnt);
				memset(cnt_person, 0, sizeof cnt_person);
			}
			else
			{
				num[param1] -= n - 1;

				for(int i = 0; i < n; i++)
				{
				    if(i != param1)
				    {
				        ++num[i];
                    }
                }	
			}

			now_person = param1;
		}
		else if(s[0] == 'A')
		{
			--num[now_person];

			for (int i = 0; i < 7; ++i)
			{
				cnt[i] -= cnt_person[now_person][i];
				cnt_person[now_person][i] = 0;
			}

			++cnt[param1 + 4];
			++cnt_person[now_person][param1 + 4];

			now_person = (now_person + 1) % n;
		}
		else
		{
			--num[now_person];

            for (int i = 0; i < 7; ++i)
			{
				cnt[i] -= cnt_person[now_person][i];
				cnt_person[now_person][i] = 0;
			}

			while(param1--)
			{
				int param2;
				std::cin >> param2;

				++cnt[param2];
				++cnt_person[now_person][param2];
			}

			now_person = (now_person + 1) % n;
		}
	}

	for (int i = 0; i < n; ++i)
	{
	    std::cout << num[i] << std::endl;
    }

	return 0;
}
