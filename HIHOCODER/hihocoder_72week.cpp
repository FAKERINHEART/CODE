#include <iostream>
#include <vector>  
#include <algorithm>
  
using namespace std;  
  
int main() 
{  
    int N, M, H ,R;
    cin >> N >> M >> H >> R;
    int arr[N];
    vector<int> temp;
    vector<vector<int> > v;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    
    for(int i = 0; i < N; i++)
    {
    	if(i == 0 || arr[i] - arr[i - 1] > M)
    	{
    		temp.clear();
    		temp.push_back(arr[i]);
    		v.push_back(temp);
		}
		else v.back().push_back(arr[i]);
	}
	
	
	int MAX = 0;
	for(int i = v.size() - 1; i >= 0; i--)
	{
		if(v[i][0] <= R)
		{
			for(int j = 0; j < v[i].size(); j++)
			{
				if(v[i][j] <= R + j) MAX++;
				else break;
			}
			for(int j = 0; j < i; j++) MAX += v[j].size();
			break;
		}
	}
	cout << min(MAX, H) << endl;
}  
