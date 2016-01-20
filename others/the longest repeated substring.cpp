#include <iostream>
#include <algorithm>

using namespace std;

class arr
{
public:
	string str;
	int sub;
};

bool cmp(arr one, arr two)
{
	return one.str < two.str;
}

int main()
{
	string str;
	getline(cin, str);
	arr arrstr[str.length()];
	for(int i = 0; i < str.length(); i++) 
	{
		arrstr[i].str = str.substr(i);
		arrstr[i].sub = i;
	}
	sort(arrstr, arrstr + str.length(), cmp);
	//for(int i = 0; i < str.length(); i++) cout << arrstr[i].str << "###" << arrstr[i].sub << endl;
	
	int MAX = 0, SUB, temp;
	for(int i = 0; i < str.length() - 1; i++)
	{
		temp = 0;
		while(temp < arrstr[i].str.length() && temp < arrstr[i + 1].str.length() && arrstr[i].str[temp] == arrstr[i + 1].str[temp]) temp++;
		if(temp > MAX)
		{
			MAX = temp;
			SUB = min(arrstr[i].sub, arrstr[i + 1].sub);
		}
		else if(temp == MAX) SUB = min(SUB, min(arrstr[i].sub, arrstr[i + 1].sub));
	}
	
	if(!MAX) cout << -1;
	else 
	{
		cout << SUB << " ";
		for(int i = SUB; i < SUB + MAX; i++) cout << str[i];
	}
	cout << endl;
	return 0;
}
