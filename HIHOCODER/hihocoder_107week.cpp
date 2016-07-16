#include <iostream>
#include <vector> 


using namespace std;

int main()
{
	string temp, str = "", str_symbol = "";
	vector<string> v;
	while(getline(cin, temp, '\n'))
	{
		for(int i = 0; i < temp.length(); ++i)
		{
			if(temp[i] >= 'a' && temp[i] <= 'z' || temp[i] >= 'A' && temp[i] <= 'Z')
			{
				if(temp[i] >= 'A' && temp[i] <= 'Z') str.append(1, temp[i] - 'A' + 'a');
				else str.append(1, temp[i]);
			}
			else
			{
				v.push_back(str);
				str = "";
				
				if(temp[i] != ' ')
				{
					str_symbol.append(1, temp[i]);
					v.push_back(str_symbol);
					str_symbol = ""; 
				}
			}
		}
		v.push_back("\n");
	}
	
	bool firstWord = true;
	for(int i = 0; i < v.size(); ++i)
	{
		if(v[i][0] >= 'a' && v[i][0] <= 'z')
		{
			if(firstWord == true)
			{
				firstWord = false;
				v[i][0] = v[i][0] + 'A' - 'a';
			}
			if(i > 0 && v[i - 1] != "\n") cout << " ";
			cout << v[i];
		}
		else
		{
			cout << v[i];
			if(v[i] == ".") firstWord = true;
		}
	}
	return 0;
} 
