#include <iostream>
#include <vector>
#include <map>

int sit1[30], sit2[30];

int exchange(int n)
{
    std::map<int, int> mp;

    for (int i = 0; i < n; ++i)
    {
        mp[sit1[i]] = i;
    }

    int b[30];

    for (int i = 0; i < n; ++i)
    {
        b[i] = mp[sit2[i]];
    }

    bool vis[30] = {0};
    int res = 0;

    for (int i = 0; i < n; ++i)
    {
        if (vis[i] == true)
        {
            continue;
        }
        int now = i, cnt = 0;

        while (vis[now] == false)
        {
            ++cnt;
            vis[now] = true;
            now = b[now];
        }
        res += cnt - 1;
    }

    return res;
}

int main()
{
    int T;
    std::cin >> T;

    while (T--)
    {
        std::string str1, str2;
        std::cin >> str1 >> str2;

        int str_length = str1.length();
        int cnt[30] = {0};

        for (int i = 0; i < str_length; ++i)
        {
            ++cnt[str1[i] - 'a'];
            sit1[i] = str1[i] - 'a';
        }

        for (int i = 0; i < str_length; ++i)
        {
            sit2[i] = str2[i] - 'a';
        }

        int num = 0;
        std::vector<char> vec;

        if (cnt['m' - 'a'] == 2)
        {
            vec.push_back('m');
            ++num;
        }

        if (cnt['s' - 'a'] == 2)
        {
            vec.push_back('s');
            ++num;
        }

        if (cnt['f' - 'a'] == 2)
        {
            vec.push_back('f');
            ++num;
        }

        if (cnt['t' - 'a'] == 2)
        {
            vec.push_back('t');
            ++num;
        }

        int ans = str_length;

        if (num == 0)
        {
            ans = std::min(ans, exchange(str_length));
        }

        for (int i = 0; i < (1 << (num + num)); ++i)//一共有2^(2*num)种选择
        {
            for (int j = 0; j < num; ++j)
            {
                int tmp = 0;
                int cc1 = (i >> j) & 1;//表示的是第二个该字母是选还是不选, 如果不选就表示选第一个字母
                int cc2 = (i >> (j + num)) & 1;

                for (int k = 0; k < str_length; ++k)
                {
                    if (str1[k] == vec[j])
                    {
                        if (cc1 == 0)
                        {
                            sit1[k] += 26;
                        }

                        --cc1;
                    }

                    if (str2[k] == vec[j])
                    {
                        if (cc2 == 0)
                        {
                            sit2[k] += 26;
                        }

                        --cc2;
                    }
                }
            }

            ans = std::min(ans, exchange(str_length));

            for (int j = 0; j < num; ++j)
            {
                int cc1 = (i >> j) & 1;
                int cc2 = (i >> (j + num)) & 1;

                for (int k = 0; k < str_length; ++k)
                {
                    if (str1[k] == vec[j])
                    {
                        if (cc1 == 0)
                        {
                            sit1[k] -= 26;
                        }

                        --cc1;
                    }

                    if (str2[k] == vec[j])
                    {
                        if (cc2 == 0)
                        {
                            sit2[k] -= 26;
                        }

                        --cc2;
                    }
                }
            }
        }

        std::cout << ans << std::endl;

    }
    return 0;
}
