#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

unordered_map<string, int> M;

int dfs(string S)
{
	//�������С��4, ����ѹ��, ��Ϊѹ����������Ҫ��3, ����ֱ�ӷ��� 
    if(S.size() < 4) return S.size();
    
    //���M���Ѿ�����Сֵ, ��ֱ�ӷ��� 
    if(M.find(S) != M.end()) return M[S];
    
    int len = S.length(), MIN = 1 << 30;
    
    //��Գ� 
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
    
    //��ʼ�ָ� 
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
