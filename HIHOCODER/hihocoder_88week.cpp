#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int P, Q;
	vector<int> p, q;
	cin >> P >> Q;
	for(int i = 1; i <= P; i++) if(!(P % i)) p.push_back(i);
	for(int i = 1; i <= Q; i++) if(!(Q % i)) q.push_back(i);
	for(int i = 0; i < p.size(); i++) for(int j = 0; j < q.size(); j++) cout << p[i] << " " << q[j] << endl;
	return 0;	
} 
