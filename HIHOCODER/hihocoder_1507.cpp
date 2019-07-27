#include <iostream>
#include <vector>

using namespace std;

std::vector<int> parent[100001];

int main()
{
    int N;
    std::cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        
        if (a == b || b == 1)
        {
            std::cout << i << std::endl;
            return 0;
        }
        
        parent[b].push_back(i);
    }

    for (int i = 1; i <= N; ++i)
    {
        if (parent[i].size() > 1)
        {
            std::cout << parent[i][0] << " " << parent[i][1] << std::endl;
            return 0;
        }
    }

    return 0;
}
