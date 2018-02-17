#include<iostream>
#include <algorithm>

using namespace std;

int data[31];
int N, result;

bool check(int d)
{
    if (d > 1 && d & 1 && data[d] - data[d - 1] < 0 || d > 1 && !(d & 1) && data[d] - data[d - 1] > 0)
    {
        return true;
    }
    
    return false;
}

void dfs(int d, int s)
{
    if (d == N + 1)
    {
        result = min(result, s);
        return;
    }
    if (s >= result)
    {
        return;
    }
        
    int temp;
    
    if (check(d) == true || d == 1)
    {
        dfs(d + 1, s);
    }

    if (s + 1 >= result)
    {
        return;
    }

    for (int i = d + 1; i <= N; ++i)
    {
        if (check(i) == true)
        {
            continue;
        }
        
        swap(data[i], data[d]);
        
        if (check(d) == true || d == 1)
        {
            dfs(d + 1, s + 1);
        }

        swap(data[i], data[d]);
    }
}

int main()
{
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> data[i];
    }
    result = N;

    dfs(1, 0);
    
    for (int i = 1; i <= N; ++i)
    {
        data[i] = -data[i];
    }  
    
    dfs(1, 0);
    
    cout << result << endl;
}
