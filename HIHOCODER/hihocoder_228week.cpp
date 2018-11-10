#include <iostream>
#include <string>
#include <vector>
#include <cstring>

int main()
{
    std::string str;
    std::cin >> str;
    std::vector<int> v;
    int array[100000];
    memset(array, 0, sizeof(array));

    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == '(')
        {
            v.push_back(i);
        }
        else
        {
            array[v.back()] = i;
            v.pop_back();
        }
    }
    
    for (int i = 0; i < 100000; ++i)
    {
        if (array[i] != 0)
        {
            std::cout << i + 1 << " " << array[i] + 1 << std::endl;
        }
    }
    
    return 0;
}
