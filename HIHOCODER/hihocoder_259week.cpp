#include <iostream>
#include <string>

int main()
{
    int N;
    std::string str;
    
    std::cin >> N;
    
    while (N--)
    {
        std::cin >> str;
        
        std::string result;
        
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                result += str[i];
            }
            else if (str[i] >= 'A' && str[i] <= 'Z')
            {
                result += '_';
                result += (str[i] + 'a' - 'A');
            }
            else if (str[i] == '_')
            {
                result += (str[++i] + 'A' - 'a');
            }
        }
        
        std::cout << result << std::endl;
    }

    return 0;
}
