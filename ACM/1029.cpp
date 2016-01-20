#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int status[1001], N, K, length, num_notequal_zero, sub;
	int left[1001], right[1001];
	bool sign[1001];
	string relation; 
	cin >> N >> K;
	for(int i = 1; i <= N; i++) status[i] = -3;
	for(int i = 0; i < K ; i++)
	{
		cin >> length;
		for(int j = 0; j < length; j++) cin >> left[j];
		for(int j = 0; j < length; j++) cin >> right[j];
		cin >> relation;
		if(relation == ">") 
		{
			relation = "<";
			swap(left, right);
		}
		if(relation == "=")
		{
			for(int j = 0; j < length; j++)
			{
				status[left[j]] = 0;
				status[right[j]] = 0;
			}
		}
		
		memset(sign, false, sizeof(sign));
		if(relation == "<")
		{
			for(int j = 0; j < length; j++)
			{
				sign[left[j]] = true;
				sign[right[j]] = true;
				
				if(status[left[j]] == 1) status[left[j]] = 0;
				else if(status[left[j]] == -3) status[left[j]] = -1;
				if(status[right[j]] == -1) status[right[j]] = 0;
				else if(status[right[j]] == -3) status[right[j]] = 1;
			}
			for(int j = 1; j <= N; j++) if(!sign[j]) status[j] = 0;
		}
	}
	num_notequal_zero = 0;
	for(int j = 1; j <= N; j++)
	{
		if(status[j])
		{
			num_notequal_zero++;
			sub = j;	
		}	
	} 
	if(num_notequal_zero == 1) cout << sub << endl;
	else cout << 0 << endl;
	return 0;	
} 
