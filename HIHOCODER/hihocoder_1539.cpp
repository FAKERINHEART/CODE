#include <iostream>
#include <string>
#include <map>
#include <queue>

std::string str;
std::map<int, int> m;
int original_num;
int target_num;

void bfs(int n)
{
    m.clear();
    ++m[n];

    std::queue<int>p;
    p.push(n);

    while (p.empty() == false)
    {
        int now = p.front();
        p.pop();

        if (now == target_num)
        {
            std::cout << m[now] - 1 << std::endl;
            return;
        }

        int array[10];

        for(int i = str.length(), x = now; x > 0; x /= 10, --i)
        {
            array[i] = x % 10;
        }

        for (int i = 1; i + 1 <= str.length(); ++i)
        {
            for (int j = 1; j <= str.length() + 1; ++j)
            {
                int sum=0;

                if (j == i || j == i + 1)
                {
                    continue;
                }

                for(int k = 1; k < j; ++k)
                {
                    if (k != i && k != i + 1)
                    {
                        sum = sum * 10 + array[k];
                    }
                }

                sum = sum * 10 + array[i];
                sum = sum * 10 + array[i + 1];

                for (int k = j; k <= str.length(); ++k)
                {
                    if (k != i && k != i + 1)
                    {
                        sum = sum * 10 + array[k];
                    }
                }

                if (m[sum]==0)
                {
                    m[sum] = m[now] + 1;
                    p.push(sum);
                }
            }
        }
    }

    std::cout << -1 << std::endl;

    return;
}

int main()
{
    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i)
    {
        std::cin >> str;
        original_num = 0;
        target_num = 0;
        
        for (int j = 0, k = 1; j < str.length(); ++j, ++k)
        {
            target_num = target_num * 10 + k;
            original_num = original_num * 10 + str[j] - '0';
        }
        
        //std::cout << original_num << "->" << target_num << std::endl;
        bfs(original_num);
    }
    return 0;
}
