#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

class row
{
public:
	int childId;
	int expandLength;
	row(int Id):childId(Id), expandLength(0){}
};
class section 
{
public:
    vector<row> rows; 
    int selfLength;      
    int expandLength;    
    int delta;           
    section():selfLength(0),expandLength(0),delta(0) {};
};

class panel 
{
public:
    vector<section> sections; 
    vector<int> rowIds;     
};

panel panels[1001];

void dealPanel(panel& p)
{
	if(!p.rowIds.size()) return;
	
	p.rowIds.push_back(0);
	int sectionId = 0;
	p.sections.push_back(section());
	
	for(int i = 0; i < p.rowIds.size(); i++)
	{
		if(p.rowIds[i]) p.sections[sectionId].rows.push_back(row(p.rowIds[i]));
		else
		{
			sectionId++;
			p.sections.push_back(section());
		}
	}
	return;
}

bool sortByExpandLength(row x, row y) 
{
    return x.expandLength > y.expandLength;
}

bool sortByDelta(section x, section y) 
{
    return x.delta > y.delta;
}

int getExpandLength(panel& p)
{
	int ret = 0;
	for(int i = 0; i < p.sections.size(); i++)
	{
		for(int j = 0; j < p.sections[i].rows.size(); j++) p.sections[i].rows[j].expandLength = getExpandLength(panels[p.sections[i].rows[j].childId]);
		sort(p.sections[i].rows.begin(), p.sections[i].rows.end(), sortByExpandLength);
		
		p.sections[i].selfLength = p.sections[i].rows.size();
		p.sections[i].expandLength = p.sections[i].selfLength;
		for(int j = 0; j < p.sections[i].rows.size(); j++) p.sections[i].expandLength = max(p.sections[i].expandLength, j + p.sections[i].rows[j].expandLength);
		p.sections[i].delta = p.sections[i].expandLength - p.sections[i].selfLength;
		
		ret += p.sections[i].selfLength;
	}
	sort(p.sections.begin(), p.sections.end(), sortByDelta);
	
	int now = 0;
	
	for(int i = 0; i < p.sections.size(); i++)
	{
		ret = max(ret, now + p.sections[i].expandLength);
		now += p.sections[i].selfLength;
	}
	return ret;
}

int main()
{
	int N;
	cin >> N;
	int numOfIds, id;
	for(int i = 0; i <= N; i++)
	{
		cin >> numOfIds;
		while(numOfIds--)
		{
			cin >> id;
			if(!id) ++numOfIds;
			panels[i].rowIds.push_back(id);
		}
		dealPanel(panels[i]);
	}
	cout << getExpandLength(panels[0]) << endl;
	return 0;
}
