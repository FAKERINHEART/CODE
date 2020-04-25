#include <iostream>
#include <string>
#include<map>

std::map<std::string, int> son[500003];
std::string str[10001];

int main()
{
    int N;
    std::cin >> N;
    
    int ID = 0;
    
    for (int i = 1; i <= N; ++i)
    {
        int u = 0;
        std::cin >> str[i];

        int start = 1;
        int len = 0;

        for (int j = 1; j < str[i].size(); ++j)
        {
            if (str[i][j] != '/' && j != str[i].size() - 1)
            {
                continue;
            }

            if (str[i][j] == '/')
            {
                len = j - start;
            }
            else if (j == str[i].size() - 1)
            {
                len = j + 1 - start;
            }

            std::string tmp = str[i].substr(start, len);

            if (son[u].find(tmp) == son[u].end())
            {
                son[u][tmp] = ++ID;
            }

            u = son[u][tmp];

            start = j + 1;
        }
    }
    
    for (int i = 1; i <= N; ++i)
    {
        std::string res = "";
        int u = 0;
        
        int start = 1;
        int len = 0;
        
        for (int j = 1; j < str[i].size(); ++j)
        {
            if (str[i][j] != '/' && j != str[i].size() - 1)
            {
                continue;
            }

            if (str[i][j] == '/')
            {
                len = j - start;
            }
            else if (j == str[i].size() - 1)
            {
                len = j + 1 - start;
            }

            std::string tmp = str[i].substr(start, len);
            start = j + 1;
            
            if (son[u].size() == 1 && u != 0)
            {
                res += '-';
            }
            else
            {
                res += '/';
            }
            
            res += tmp;
            u = son[u][tmp];
        }

        for (int j = res.size() - 1; j >= 0; --j)
        {
            if (res[j] == '/')
            {
                break;
            }
            else if(res[j] == '-')
            {
                res[j] = '/';
                break;
            }
        }

        std::cout << res << std::endl;
    }

    return 0;
}
