#include <iostream>
#include <string>

int main()
{
    int T;
    std::string str;

    std::cin >> T;

    while (T--)
    {
        std::cin >> str;
        int L = 0, A = 0;
        bool qualified = true;

        for (unsigned int i = 0; i < str.length(); ++i)
        {
            if (str[i] == 'O')
            {
                L = 0;
            }
            else if (str[i] == 'A')
            {
                L = 0;

                if (++A > 1)
                {
                    qualified = false;
                    break;
                }
            }
            else
            {
                if (++L >= 3)
                {
                    qualified = false;
                    break;
                }
            }
        }

        if (qualified == true)
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
