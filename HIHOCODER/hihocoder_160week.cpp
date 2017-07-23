#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

unordered_map<string, int> M;

int dfs(string S)
{
	//如果长度小于4, 不用压缩, 因为压缩长度至少要加3, 所以直接返回 
    if(S.size() < 4) return S.size();
    
    //如果M中已经有最小值, 则直接返回 
    if(M.find(S) != M.end()) return M[S];
    
    int len = S.length(), MIN = 1 << 30;
    
    //算对称 
    for(int i = 1; i <= len/2; ++i)
    {
        string temp = S.substr(0, i);
        
        int j;
        
        for(j = 0; j <= len - i; j += i)
        {
        	if(S.substr(j, i) != temp) break;	
		}
            
        if(j >= len)
        {
        	return  dfs(temp) + 2 + to_string(len / i).length();
		}
    }
    
    //开始分割 
    for(int i = 1; i < len; ++i)
    {
        string left = S.substr(0, i), right = S.substr(i);
        int v_left = dfs(left), v_right = dfs(right);
        
        if(left.size() >= 4) M[left] = v_left;
        if(right.size() >= 4) M[right] = v_right;
        
        MIN = min(MIN , v_left + v_right);
    }
    
    return MIN;
}

int main()
{
    int T;
    cin >> T;
    
    string S;
    
    while(T--)
    {
        cin >> S;
		M.clear();
		
		cout << dfs(S) << endl;
    }
    
    return 0;
} 
