#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct Member
{
    int color = 0;
    vector<int> sons;
    vector<int> parents;
};

Member members[100001];
bool isUnstable[100001];
int N;

void topo(int index)
{
    if(members[index].color != 0)
    {
        return;
    }

    members[index].color = index;
    queue<int> q;
    q.push(index);
    
    while(!q.empty())
    {
        int head = q.front();
        q.pop();
        
        for (int i = 0; i < members[head].sons.size(); ++i)
        {
            bool flag = true;
            
            for (int j = 0; j < members[members[head].sons[i]].parents.size(); ++j)
            {
                if(members[members[members[head].sons[i]].parents[j]].color != index)
                {
                    flag = false;
                    
                    break;
                }
            }
            
            if(flag == true)
            {
                members[members[head].sons[i]].color = index;
                q.push(members[head].sons[i]);
                isUnstable[members[head].sons[i]] = true;
            }
        }
    }

}

int main()
{
    cin >> N;
    
    for (int i = 1; i <= N; ++i)
    {
        int K;
        cin >> K;
        
        int parent;
        
        for (int j = 0; j < K; ++j)
        {
            
            cin >> parent;
            
            members[parent].sons.push_back(i);
            members[i].parents.push_back(parent);
        }
    }
    
    memset(isUnstable, false, sizeof(isUnstable));

    for (int i = 1; i <= N; ++i)
    {
        topo(i);
    }

    int ans = 0;
    
    for (int i = 1; i <= N; ++i)
    {
        if(isUnstable[i] == true)
        {
            ++ans;
        }
    }
    cout << N - ans << endl;
    
    return 0;
}
