#include <iostream>
#include <string> 

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    while(T--)
    {
        string str;
        
        cin >> str;
        str = str.substr(2);
        
        bool judge = true;
        string result;
        
        while(true)
        {
            //result += mutiply(str, judge);
            int len = str.length(), size = 0, carry = 0;
            bool flag = false;
            
            for(int i = len - 1; i >= 0; --i)
			{
			    int x = (str[i] - '0') * 2 + carry;
			    str[i] = x % 10 + '0';
			    
			    if(!flag && str[i] == '0')
			    {
			    	++size;
				}
				
			    if(str[i] != '0')
			    {
			    	flag = true;
				}
				
			    carry = x /10;
			}
			
			if(size == 0)
			{ 
				judge = false;
			}
			
			str.resize(len - size);
			
			result += (carry + '0');
            
            if(judge == false) 
			{ 
				cout << "NO" << endl; 
				break;
			}
            else if(str.size() == 0)
			{	
				cout << "0." << result << endl;
				break;
			}
        } 
    }
    return 0;
}
