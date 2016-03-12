#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string transfer_to_lower_case(string& str)
{
	string str2(str);
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			str2[i] = str[i] - 'A' + 'a';
		}
	}
	return str2;
}

int main()
{
	string str, str2;
	int index;
	while(getline(cin, str))
	{
		stringstream ss(str);
		while(ss >> str)
		{
			str2 = transfer_to_lower_case(str);
			index = str2.find("marshtomp");
			if(index != string::npos)
			{
				cout << str.substr(0, index) << "fjxmlhx" << str.substr(index + 9) << " ";
			}
			else cout << str << " "; 
		}
		cout << endl;
	}
	return 0;	
} 
