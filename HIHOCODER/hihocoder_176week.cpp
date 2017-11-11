#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

int N;
string constrains[20];
int letters_data[26];

int GetValue(string str)
{
    if(str[0] >= 'A' && str[0] <= 'Z')
    {
    	return letters_data[str[0] - 'A'];
	}
	else
    {
        stringstream ss;
        ss << str;
        
        int num;
        ss >> num;
        
		return num;
    }
}

bool Check(string constrain)
{
	vector<string> split_strs;
	int last = 0;
	int index = constrain.find_first_of('<', last);
	
	while(index != string::npos)
	{
		split_strs.push_back(constrain.substr(last, index - last));
		last = index + 1;
		index = constrain.find_first_of('<', last);
	}
	
	split_strs.push_back(constrain.substr(last));
	
	for(int i = 0; i < split_strs.size() - 1; ++i)
	{
		bool equal = false;
		
		if(split_strs[i + 1][0] == '=')
		{
			equal = true;
			
			split_strs[i + 1] = split_strs[i + 1].substr(1);
		}

		int first = GetValue(split_strs[i]);
		int second = GetValue(split_strs[i + 1]);
		
		//cout << first << "________" << second << "___________" << equal << endl;
		
		if((equal == false && first >= second) || (equal == true && first > second))
		{
			return false;	
		}	
	}
	
	return true;
}

int main()
{
    cin >> N;
    bool letters[26];
    int count = 0;
    memset(letters, false, sizeof(letters));
    
    for (int i = 0; i < N; ++i)
    {
    	cin >> constrains[i];
    	
    	for(int j = 0; j < constrains[i].length(); ++j)
    	{
    		if(constrains[i][j] >= 'A' && constrains[i][j] <= 'Z' && letters[constrains[i][j] - 'A'] == false)
    		{
    			letters[constrains[i][j] - 'A'] = true;
    			++count;
			}
		}
	}
	
	//cout << count << endl;

    int T; 
    cin >> T;
    
    while (T--)
    {
        for (int i = 0; i < count; ++i)
        {
            char temp;
            cin >> temp;
            cin >> letters_data[temp - 'A'];
        }
	
		bool flag = true;
		
		for(int i = 0; i < N; ++i)
		{
			if(Check(constrains[i]) == false)
			{
				flag = false;
				break;
			}
		}
        
        if(flag == true)
        {
        	cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
    }
    
    return 0;
}
