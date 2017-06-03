#include<iostream>
#include<set>
#include<map>
using namespace std;

int main()
{
    int N, time, price, curTime;
    char ch;
    set<pair<int, int> > st;
    map<int, int> hash;

    cin>>N;

    for(int i =0; i< N; ++i)
    {
        cin >> ch;
        if(ch == 'P')
        {
            cin >> time >> price;
            st.insert(make_pair(price, time));
            hash[time] = price;
            curTime = time;
        }
        else if(ch == 'Q')
        {
        	cout << st.rbegin()->first << " " << st.begin()->first << " " << hash[curTime] << endl; 
		}
        else if(ch == 'R')
        {
            int dtime;
            cin >> dtime;
            while(hash.begin()->first<= dtime)
            {
                st.erase(make_pair(hash.begin()->second, hash.begin()->first));
                hash.erase(hash.begin()); 
            }
        }
    }
	
    return 0;
}
