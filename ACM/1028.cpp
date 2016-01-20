#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{	
	vector<string> v_f, v_b;
	string str, web_site = "http://www.acm.org/";
	while(cin >> str)
	{
		if(str == "QUIT")
		{
			v_f.clear();
			v_b.clear();
			break;
		}
		else if(str == "BACK")
		{
			if(v_b.empty()) cout << "Ignored" << endl;
			else
			{
				if(!web_site.empty()) v_f.push_back(web_site);
				web_site = v_b.back();
				cout << web_site << endl;
				v_b.pop_back();
			}
		}
		else if(str == "FORWARD")
		{
			if(v_f.empty()) cout << "Ignored" << endl;
			else
			{
				if(!web_site.empty()) v_b.push_back(web_site);
				web_site = v_f.back();
				cout << web_site << endl; 
				v_f.pop_back();
			}
		}
		else if(str == "VISIT")
		{
			if(!web_site.empty()) v_b.push_back(web_site);
			cin >> web_site;
			cout << web_site << endl; 
			v_f.clear();
		}
	}
	return 0;
} 
