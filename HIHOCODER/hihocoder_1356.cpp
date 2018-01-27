#include <iostream>
#include <map>
#include <set>
#include <utility>

using namespace std;

int main()
{
	int n;
	int A[100000];
	map<int, int> count;
	set<pair<int, int>> s;
	
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
        ++count[A[i]];
    }
    
    for (map<int, int>::iterator iter = count.begin(); iter != count.end(); ++iter)
    {
    	s.insert(make_pair(iter->second, iter->first));
	}

	if ((--s.end())->first * 2 - 1 > n)
    {
        cout << -1 << endl;
    }
    else
    {
    	int pre_x = -1;
    	
	    for (int i = 1; i <= n; ++i)
	    {
	        int x;
	        
	        if ((--s.end())->first * 2 - 1 == (n + 1 - i))
	        {
	        	x = (--s.end())->second;
			}
	        else
	        {
	            map<int, int>::iterator iter = count.begin();
	            
	            if (iter->first == pre_x) 
				{
					++iter;
				}
	            x = iter->first;
	        }
	        
	        s.erase(make_pair(count[x], x));
	        
			if (--count[x] > 0)
	        {
	        	s.insert(make_pair(count[x], x));
			}
	        else
	        {
	        	count.erase(x);
			}
	        pre_x = x;
	        
	        cout << x << " ";
	    }
	    cout << endl;
	}
	
	return 0;
}
