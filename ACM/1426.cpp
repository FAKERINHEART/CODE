#include <iostream>
#include <deque>

using namespace std;

int main()
{
	int n;
	deque<long long> dq;
	while(cin >> n)
	{
		if(!n) break;
		dq.push_back(1);
		while(!dq.empty())
		{
			long long temp = dq.front();
			if((temp * 10) % n) dq.push_back(temp * 10);
			else
			{
				cout << temp * 10 << endl;
				break;
			}
			if((temp * 10 + 1) % n) dq.push_back(temp * 10 + 1);
			else
			{
				cout << temp * 10 + 1 << endl;
				break;
			}
			dq.pop_front();
		}
		dq.clear();
	}
	return 0; 
} 
