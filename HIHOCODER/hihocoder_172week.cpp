#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int n, m;
long long bitnum[1001][1001];
long long mod = 1e9 + 7;

void add(int xx , int yy, int num)
{
    for(int x = xx; x <= n; x += (x & -x))
    {
        for(int y = yy; y <= n; y += (y & -y))
        {
            bitnum[x][y] += num;
        }
    }
    
    return;
}

long long sum(int l, int r)
{
    long long ans = 0;
    for(int x = l; x > 0; x -= (x & -x))
    {
        for(int y = r; y > 0; y -= (y & -y))
        {
            ans += bitnum[x][y] % mod;
        }
    }
    
    return ans % mod;
}

long long getsum(int x1, int y1, int x2, int y2)
{
    long ans = sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
    
	while(ans < 0) ans += mod;
    
	return ans;
}

int main()
{
    memset(bitnum, 0, sizeof(bitnum));
	cin >> n >> m;
    
	while(m--)
    {
        string str;
        int x1, y1, x2, y2, val;
        cin >> str;
        
        if(str == "Add")
        {
            cin >> x1 >> y1 >> val;
            add(x1 + 1, y1 + 1, val);
        }
        else
        {
            cin >> x1 >> y1 >> x2 >> y2;
            cout << getsum(x1 + 1, y1 + 1, x2 + 1, y2 + 1) << endl;
        }
    }
    
	return 0;
}
