#include<vector>
#include<iostream>
#include<queue>
#include<stack>
#include <math.h>
#include<map>
#include<set>

using namespace std;
const int MA = 100005;

int nums[MA];
long long Q;
int n;

bool check(int len)
{
    priority_queue<int> que;
    for(int i = 0; i < len; ++i)
	{
        que.push(nums[i]);
    }
    int now = 0;
    long long sum = 0;
    for (int i = len; i < n; ++i)
	{
        int temp = que.top();
        que.pop();
        sum += (++now) * temp;
        que.push(nums[i]);
        if (sum > Q)
        {
        	return false;
		}  
    }
    while (!que.empty())
	{
        sum += (++now) * que.top();
        que.pop();
        if (sum > Q)
        {
        	return false;
		}  
    }
    return true;
}

int main() 
{
    cin >> n >> Q;
    
    for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
    }
    
    int l = 1;
    int r = n;
    while (l <= r)
	{
        int mid = (l + r) >> 1;
        if (!check(mid))
		{
            l = mid + 1;
        }
        else
		{
            r = mid - 1;
    	}
    }
    
    if (l > n)
	{
        cout << -1 << endl; 
    }
    else{
        cout << l << endl;
    }
    
    return 0;
}
