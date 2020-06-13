#include <iostream>
#include <string>
#include <map>
#include <algorithm>

struct Person
{
    std::string name, number;
    int value;
    
    void Init()
    {
        value = 0;

        for (int i = 0; i < (int)number.size(); i++)
        {
            int sign = 1;
            if (i + 1 < (int)number.size() && cost[number[i]] < cost[number[i + 1]])
            {
                sign = -1;
            }
            value += sign * cost[number[i]];
        }
    }
    bool operator<(const Person &other) const
    {
        return name < other.name || (name == other.name && value < other.value);
    }

    static std::map<char, int> cost;
}; 

Person p[100000];
std::map<char, int> Person::cost = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

void Solve(int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].Init();
    }

    std::sort(p, p + n);
}

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i].name >> p[i].number;
    }

    Solve(n);

    for (int i = 0; i < n; i++)
    {
        std::cout << p[i].name << ' ' << p[i].number << std::endl;
    }

    return 0;
}

