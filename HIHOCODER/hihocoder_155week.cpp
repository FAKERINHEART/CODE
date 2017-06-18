#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int main()
{
    int N, S, E, MAX = 0;
    vector<pair<int, int> > t;
    multiset<int> st;
    
    cin >> N;
    
    for(int i = 0; i < N; ++i)
    {
        cin >> S >> E; 
        t.push_back(make_pair(S, E));
    }
    
    sort(t.begin(), t.end());
    
    for(int i = 0; i< t.size(); ++i)
    {
        multiset<int>::iterator it = st.begin();
        
        while(it != st.end())
        {
            if(t[i].first >= *it) it = st.erase(it);
            else break;
        }
        
        st.insert(t[i].second);
        
        MAX = max(MAX, (int)st.size());
    }
    
    cout << MAX << endl;
    
    return 0;
}
