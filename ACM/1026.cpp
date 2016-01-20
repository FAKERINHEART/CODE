#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

void test(int length_code, int num_replacement, string str_replacement, vector<int>* v, int length_vector)
{
	str_replacement.append(length_code - str_replacement.length(), ' ');
	str_replacement.insert(0, "-");
	
	int temp_replacement[length_code + 1];
	for(int i = 0; i < length_vector; i++)
	{
		if(!num_replacement % v[i].size()) continue;
		else
		{
			for(int j = 0; j < v[i].size(); j++) temp_replacement[v[i][(j + num_replacement % v[i].size()) % v[i].size()]] = str_replacement[v[i][j]];
			for(int j = 0; j < v[i].size(); j++) str_replacement[v[i][j]] = temp_replacement[v[i][j]];
		}
	}
	str_replacement.erase(0, 1);
	cout << str_replacement << endl;
	return;
}

int main()
{
	int length_code, length_vector;
	int replacement_code[201];
	bool visited[201];
	vector<int> v[200];
	string str;
	while(cin >> length_code)
	{
		if(!length_code) break;
		for(int i = 1; i <= length_code; i++) cin >> replacement_code[i];
		memset(visited, 0, sizeof(visited));
		length_vector = 0;
		for(int i = 1; i <= length_code; i++)
		{
			if(!visited[i])
			{
				visited[i] = true;
				v[length_vector].push_back(i);
				int j = replacement_code[i];
				while(j != i)
				{
					visited[j] = true;
					v[length_vector].push_back(j);
					j = replacement_code[j];
				}
				length_vector++;
			}
		}
		
		int temp, temp2;
		string str_temp;
		getline(cin, str); 
		while(1)
		{
			getline(cin, str);		
			if(str == "0") break;
			test(length_code, atoi(str.substr(0, str.find_first_of(" ")).c_str()), str.substr(str.find_first_of(" ") + 1), v, length_vector);
		}
		cout << endl;
		for(int i = 0; i < length_vector; i++) v[i].clear();
	} 
	return 0;
}
