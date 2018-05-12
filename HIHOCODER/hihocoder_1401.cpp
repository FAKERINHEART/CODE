#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

struct Student
{
    int id;
    int arrive_time;
    int office_num;
    int finish_time;
    vector<pair<int, int> > register_offices;
};

struct Event
{
    int student_idx;
    int office;
    int begin;
    int duration;
    Event(int s, int o, int b, int d): student_idx(s), office(o), begin(b), duration(d){}; 
};

Student students[10001];

struct Cmp
{
	bool operator()(const Event& e1, const Event& e2)
	{
	    if (e1.begin == e2.begin)
	    {
	    	return students[e1.student_idx].id > students[e2.student_idx].id;
		}
		
	    return e1.begin > e2.begin;
	}
};
 
int N, M, K;
priority_queue<Event, vector<Event>, Cmp> pq;
int pre[101];//每个office下一次可以开始工作的时间 
int pos[10001];//每个学生当前完成了几个office 

void Solve()
{
    for (int i = 0; i < N; ++i)
	{
        pq.push(Event(i, students[i].register_offices[0].first, students[i].arrive_time + K, students[i].register_offices[0].second));
        pos[i] = 1;
    }
    
    memset(pre, 0, sizeof(pre));
    
	while (pq.empty() == false)
	{
        Event e = pq.top();
        pq.pop();
        
        int st = e.student_idx;
        
		if (pre[e.office] > e.begin)
		{
            e.begin = pre[e.office];
        }
        
        int finish_time = e.begin + e.duration; 
		   
        if (pos[st] == students[st].office_num)
		{
            students[st].finish_time = finish_time;
        }
        else
		{
            int office = students[st].register_offices[pos[st]].first;
            int duration = students[st].register_offices[pos[st]].second;
            pq.push({st, office, finish_time + K, duration});
            ++pos[st];
        }
        
        pre[e.office] = finish_time;
    }
}
int main()
{
    cin >> N >> M >> K;

    for (int i = 0; i < N; ++i)
	{
		cin >> students[i].id >> students[i].arrive_time >> students[i].office_num;

        for (int j = 0; j < students[i].office_num; j++)
		{
            int o, w;
            
            cin >> o >> w;
            students[i].register_offices.push_back({o, w});
        }
    }
    
    Solve();
    
    for (int i = 0; i < N; ++i)
	{
        cout << students[i].finish_time << endl;
    }
    
    return 0;
}
