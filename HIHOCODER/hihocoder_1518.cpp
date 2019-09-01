#include <iostream>
#include <cstring>

using namespace std;

int A[100001];
bool visited[100001];

void dfs(int i, int start, int &ret)
{
    if (i == start && ret != 0)
    {
        return;
    }   
    
    ++ret;
    visited[i] = true;
    dfs(A[i], start, ret);
    
    return;
}

int main()
{
    int N;
    std::cin >> N;
    
    for (int i = 1; i <= N; ++i)
    {
        std::cin >> A[i];
    }
    
    memset(visited, 0, sizeof(visited));
    
    int ret = 0;

    for (int i = 1; i <= N; ++i)
    {
        if (visited[i] == false)
        {
            int ret_temp = 0;
            dfs(i, i, ret_temp);
            ret = std::max(ret, ret_temp);   
        }
    }

    std::cout << ret << std::endl;

    return 0;
}
