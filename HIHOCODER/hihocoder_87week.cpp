#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <sstream>
#include <map>

using namespace std;

struct ans
{
	int index;
	int int_value;
	bool bool_value;
	string string_error;
	ans(){}
	ans(int int_v): index(1), int_value(int_v), bool_value(false), string_error(""){}
	ans(bool bool_v): index(2), int_value(0), bool_value(bool_v), string_error(""){}
	ans(string string_e): index(3), int_value(0), bool_value(false), string_error(string_e){}
};

vector<string> elements;//所有元素 
map<string, ans> identifier;//变量-值对 

bool is_digit(string s) //是否为数字 
{
	for(int i = 0; i < s.length(); i++) if(s[i] < '0' || s[i] > '9') return false;
	return true; 
}

ans look_identifier(string s) //查询变量值 
{
	if(s == "true") return ans(true);
	else if(s == "false") return ans(false);
	else
	{
		if(identifier.find(s) != identifier.end()) return identifier[s];
		return ans(string("Unbound Identifier"));
	}
}

int find_right_bracket(int left) //寻找左括号对应的右括号 
{
	int inc = 1;
	while(inc)
	{
		++left;
		if(elements[left] == "(") ++inc;
		else if(elements[left] == ")") --inc;
	}
	return left;
} 

ans caculate(string s, int x, int y)
{
	if(s == "+") return ans(x + y);
	if(s == "-") return ans(x - y);
	if(s == "*") return ans(x * y);
	if(s == "/") return y? ans(x / y): ans(string("Division By Zero"));
	if(s == "<") return ans(x < y);
	if(s == ">") return ans(x > y);
	if(s == "=") return ans(x == y); 
}

ans analysis_elements(int begin, int end)
{
	if(end - begin == 1)//除非表达式是一个单元素，否则都以"("开始 
	{
		if(is_digit(elements[begin])) return ans(atoi(elements[begin].c_str()));
		else return look_identifier(elements[begin]);
	}
	else if(elements[begin + 1] == "if")
	{
		ans ret;
		int next_begin = begin + 2;
		int next_end = begin + 3;
		if(elements[begin + 2] == "(") ret = analysis_elements(next_begin, next_end = find_right_bracket(next_begin) + 1);//如果是一个非单元素 
		else ret = analysis_elements(next_begin, next_end);//如果是一个单元素 
		
		if(ret.index == 3) return ret;
		else if(ret.index == 1) return ans(string("Type Mismatch"));
		else
		{
			int next_next_begin = next_end;
			int next_next_end;
			if(elements[next_next_begin] == "(") next_next_end = find_right_bracket(next_next_begin) + 1;
			else next_next_end = next_next_begin + 1;
			
			return ret.bool_value? analysis_elements(next_next_begin, next_next_end): analysis_elements(next_next_end, end - 1); 
		}
	}
	else if(elements[begin + 1] == "let")
	{
		int next_end = find_right_bracket(begin + 2) + 1;
		string key = elements[begin + 3];
		ans val = analysis_elements(begin + 4, next_end - 1);
		if(val.index == 3) return val;
		identifier[key] = val;
		ans ret = analysis_elements(next_end, end - 1);
		if(ret.index == 3) return ret; 
		identifier.erase(key);
		return ret;
	}
	else
	{
		int next_begin = begin + 2;
		int next_end = begin + 3;
		ans x, y;
		if(elements[next_begin] == "(") x = analysis_elements(next_begin, next_end = find_right_bracket(next_begin) + 1);
		else x = is_digit(elements[next_begin])? ans(atoi(elements[next_begin].c_str())): look_identifier(elements[next_begin]);
		if(x.index == 3) return x;
		else if(x.index == 2) return ans(string("Type Mismatch"));
		else
		{
			if(elements[next_end] == "(") y = analysis_elements(next_end, end - 1);
			else y = is_digit(elements[next_end])? ans(atoi(elements[next_end].c_str())): look_identifier(elements[next_end]);
			if(y.index == 3) return y;
			else if(y.index == 2) return ans(string("Type Mismatch"));
			else return caculate(elements[begin + 1], x.int_value, y.int_value);
		}
		
	}
}

int main()
{
	int n;
   	cin >> n;
   	cin.get();    
	while (n--) 
	{
		elements.clear();
		identifier.clear();
		
		string s;
		getline(cin, s);
		stringstream ss(s);
		while (ss >> s) elements.push_back(s);
		
		ans A = analysis_elements(0, elements.size());
		switch(A.index) 
		{
			case 1: cout << A.int_value << endl; break;
			case 2:	cout << (A.bool_value ? "true" : "false") << endl; break;
			case 3:	cout << A.string_error << endl;	break;
		}
	}
	return 0;	
} 
