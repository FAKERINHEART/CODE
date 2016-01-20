#include <iostream>
#include <set>
#include <vector>

using namespace std;

class fs
{
	public:
		string name;
		vector<fs> di;
		set<string> fi;
		void init(string n) {name = n;}
};

void inp(fs& f, string str)
{
	string temp;
	if(str[0] == '*' || str[0] == ']') return;
	if(str[0] == 'f') f.fi.insert(str);
	else if(str[0] == 'd')
	{
		fs sf;
		sf.init(str);
		cin >> temp;
		inp(sf, temp);
		f.di.push_back(sf);
	} 
	cin >> temp;
	inp(f, temp);
	return;
}


void oup(const fs& f, int level)
{
	for(int j = 0; j < level; j++ ) cout << "|     ";
	cout << f.name << endl;
	for(int i = 0; i < f.di.size(); i++)
	{
		oup(f.di[i], level + 1);
	}
	set<string>::iterator iter = f.fi.begin();
	while(iter != f.fi.end())
	{
		for(int j = 0; j < level; j++ ) cout << "|     ";
		cout << *iter << endl;
		iter++;
	}
	return;
}

int main()
{
	string str;
	fs f;
	int count = 0;
	while(1)
	{
		cin >> str;
		if(str[0] == '#') break;
		f.init("ROOT");
		inp(f, str);
		cout << "DATA SET " << ++count << ":" << endl;
		oup(f, 0);	
		cout << endl;	
		f.di.clear();
		f.fi.clear();
	}
	return 0;	
} 
