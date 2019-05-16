#include <iostream>
#include <cstring> 
#include <algorithm>

using namespace std;

int T, n, a[100001];
int g[(1 << 20) + 1][3], cnt[(1<<20) + 1];

int main()
{
   std::cin >> T;
 
   while(T--)
   {
        std::cin >> n; 
        memset(cnt, 0, sizeof(cnt));
        
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
        }
        
        sort(a + 1, a + 1 + n);
        
        for (int i = 1; i <= n; ++i)
        {
            for (int j = a[i]; j != 0; j =a[i] & (j - 1))
            {
                if (cnt[j] < 2)
                {
                    g[j][++cnt[j]] = a[i];
                }
                else
                {
                    g[j][1] = g[j][2];
                    g[j][2] = a[i];
                }
            }
        }

        long long ret = 0;
        
        for (int i = 0; i < (1 << 20) + 1; ++i)
        {
           if (cnt[i] == 2)
           {
              ret = max(ret, 1ll * g[i][1] * g[i][2] * i);
           }
        }
        
        std::cout << ret << std::endl;
   }
   return 0;
}

