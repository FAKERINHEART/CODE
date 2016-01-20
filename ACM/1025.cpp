#include <iostream> 
#include <string>
#include <deque>
#include <queue>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
 
using namespace std; 

enum STATUS_EVENT
{
	_ENTRY,  //等待进入大楼 
	_EXIT, //等待离开大楼 
	_WAITING_IN_FRONT_OF_ROOM, //等在房间外面
	_WAITING_IN_ELEVATOR_QUEUE, //等在电梯外面
};

class item
{
	public:
		int id_room;
		int time_stay;
		item(int id, int time)
		{
			id_room = id;
			time_stay = time;
		}
};

class Agent
{
	public:
		int id;
		int time_start;
		deque<item> item_list;
		string str_record;
		Agent(int _id)
		{
			str_record = "";
			id = _id;
			
			stringstream ss;
			string str;
			int time = 0, time_stay, room_id;
			cin >> str;
			ss << str;
			getline(ss, str, ':');
			time += atoi(str.c_str()) * 3600;
			getline(ss, str, ':');
			time += atoi(str.c_str()) * 60;
			getline(ss, str, ':');
			time += atoi(str.c_str());
			ss.clear();
			time_start = time;
			item_list.push_back(item(0, 30));
			while(cin >> room_id)
			{
				if(!room_id) break;
				cin >> time_stay;
				item_list.push_back(item(room_id, time_stay));
			}
			item_list.push_back(item(0, 30));
		}
};

bool cmp(Agent one, Agent two)
{
	return one.id < two.id;
}

class Room
{
	public:
		int id_Room;
		int time_last_free;	
		void Init(int id_r)
		{
			id_Room = id_r;
			time_last_free = 0;
		}
};

class event
{
	public:
		Agent* agent;
		Room* room;
		int time_start;
		STATUS_EVENT SE;
		friend bool operator<(const event& one, const event& two)
		{
			if(one.time_start != two.time_start) return one.time_start > two.time_start;
			else return (one.agent)->id > (two.agent)->id;
		}
		event(Agent* a, Room* r, int tstart, STATUS_EVENT S)
		{
			agent = a;
			room = r;
			time_start = tstart;
			SE = S;
		}
};

priority_queue<event> q;
Room rooms[11][11]; //楼层房间id为:xxyy,0<xx,yy<=10;楼层电梯id为:xx00,0<xx<=10;楼门口id为:0000

void timeseconds2structure(int time_in_seconds, string& str_h, string& str_m, string& str_s)
{
	stringstream ss;
	int h, m, s;
	h = time_in_seconds / 3600;
	ss << h;
	ss >> str_h;
	ss.clear();
	m = (time_in_seconds % 3600) / 60;
	ss << m;
	ss >> str_m;
	ss.clear();
	s = (time_in_seconds % 3600) % 60;
	ss << s;
	ss >> str_s;
	ss.clear();
	if(h < 10) str_h = "0" + str_h;
	if(m < 10) str_m = "0" + str_m;
	if(s < 10) str_s = "0" + str_s;
	return;
}

string roomidint2string(int id)
{
	stringstream ss;
	string str_xx, str_yy;
	int xx, yy;
	xx = id / 100;
	ss << xx;
	ss >> str_xx;
	ss.clear();
	yy = id % 100;
	ss << yy;
	ss >> str_yy;
	ss.clear();
	if(xx < 10) str_xx = "0" + str_xx;
	if(yy < 10) str_yy = "0" + str_yy;
	return str_xx + str_yy;
}

void deal_program(event e)
{
	string sstr_h, sstr_m, sstr_s, estr_h, estr_m, estr_s;
	int next_time_start;
	
	switch(e.SE)
	{
		case _ENTRY: 
			timeseconds2structure(e.time_start, sstr_h, sstr_m, sstr_s);
			next_time_start = e.time_start + e.agent->item_list.front().time_stay;
			timeseconds2structure(next_time_start, estr_h, estr_m, estr_s);
			e.agent->str_record += (sstr_h + ":"+ sstr_m + ":" + sstr_s + " " + estr_h + ":"+ estr_m + ":" + estr_s + " " + "Entry\n");
			e.agent->item_list.pop_front();
			
			if(e.agent->item_list.front().id_room / 100 == 1) q.push(event(e.agent, &rooms[e.agent->item_list.front().id_room / 100][e.agent->item_list.front().id_room % 100], next_time_start, _WAITING_IN_FRONT_OF_ROOM));
			else if(e.agent->item_list.front().id_room / 100 == 0) q.push(event(e.agent, &rooms[0][0], next_time_start, _EXIT));
			else q.push(event(e.agent, &rooms[1][0], next_time_start, _WAITING_IN_ELEVATOR_QUEUE));
			break;	
		case _EXIT: 
			timeseconds2structure(e.time_start, sstr_h, sstr_m, sstr_s);
			next_time_start = e.time_start + e.agent->item_list.front().time_stay;
			timeseconds2structure(next_time_start, estr_h, estr_m, estr_s);
			e.agent->str_record += (sstr_h + ":"+ sstr_m + ":" + sstr_s + " " + estr_h + ":"+ estr_m + ":" + estr_s + " " + "Exit\n");
			e.agent->item_list.pop_front();
			break;
		case _WAITING_IN_FRONT_OF_ROOM:
			if(e.room->time_last_free > e.time_start)
			{
				timeseconds2structure(e.time_start, sstr_h, sstr_m, sstr_s);
				timeseconds2structure(e.room->time_last_free , estr_h, estr_m, estr_s);
				e.agent->str_record += (sstr_h + ":"+ sstr_m + ":" + sstr_s + " " + estr_h + ":"+ estr_m + ":" + estr_s + " " + "Waiting in front of room " + roomidint2string(e.room->id_Room) + "\n");
				e.time_start = e.room->time_last_free; 
			}
			timeseconds2structure(e.time_start, sstr_h, sstr_m, sstr_s);
			next_time_start = e.time_start + e.agent->item_list.front().time_stay;
			timeseconds2structure(next_time_start, estr_h, estr_m, estr_s);
			e.agent->str_record += (sstr_h + ":"+ sstr_m + ":" + sstr_s + " " + estr_h + ":"+ estr_m + ":" + estr_s + " " + "Stay in room " + roomidint2string(e.room->id_Room) + "\n");
			e.room->time_last_free = next_time_start;
			e.agent->item_list.pop_front();
			
			//接下来应该判断下一个任务 
			if(e.room->id_Room / 100 == e.agent->item_list.front().id_room / 100)
			{
				timeseconds2structure(next_time_start, sstr_h, sstr_m, sstr_s);
				next_time_start += 10;
				timeseconds2structure(next_time_start, estr_h, estr_m, estr_s);
				e.agent->str_record += (sstr_h + ":"+ sstr_m + ":" + sstr_s + " " + estr_h + ":" + estr_m + ":" + estr_s + " " + "Transfer from room " + roomidint2string(e.room->id_Room) + " to room " + roomidint2string(e.agent->item_list.front().id_room) + "\n");
				q.push(event(e.agent, &rooms[e.agent->item_list.front().id_room / 100][e.agent->item_list.front().id_room % 100], next_time_start, _WAITING_IN_FRONT_OF_ROOM));
			}	
			else
			{
				if(e.agent->item_list.front().id_room / 100 == 0 && e.room->id_Room / 100 == 1) q.push(event(e.agent, &rooms[0][0], next_time_start, _EXIT));
				else
				{
					timeseconds2structure(next_time_start, sstr_h, sstr_m, sstr_s);
					next_time_start += 10;
					timeseconds2structure(next_time_start, estr_h, estr_m, estr_s);
					e.agent->str_record += (sstr_h + ":"+ sstr_m + ":" + sstr_s + " " + estr_h + ":" + estr_m + ":" + estr_s + " " + "Transfer from room " + roomidint2string(e.room->id_Room) + " to elevator" + "\n");
					q.push(event(e.agent, &rooms[e.room->id_Room / 100][0], next_time_start, _WAITING_IN_ELEVATOR_QUEUE));
				}
			}
			break;
		case _WAITING_IN_ELEVATOR_QUEUE:
			if(e.room->time_last_free > e.time_start)
			{
				timeseconds2structure(e.time_start, sstr_h, sstr_m, sstr_s);
				timeseconds2structure(e.room->time_last_free , estr_h, estr_m, estr_s);
				e.agent->str_record += (sstr_h + ":"+ sstr_m + ":" + sstr_s + " " + estr_h + ":"+ estr_m + ":" + estr_s + " " + "Waiting in elevator queue" + "\n");
				e.time_start = e.room->time_last_free;
			}
			else if(e.time_start % 5)
			{
				timeseconds2structure(e.time_start, sstr_h, sstr_m, sstr_s);
				timeseconds2structure(e.time_start + (5 - e.time_start % 5) , estr_h, estr_m, estr_s);
				e.agent->str_record += (sstr_h + ":"+ sstr_m + ":" + sstr_s + " " + estr_h + ":"+ estr_m + ":" + estr_s + " " + "Waiting in elevator queue" + "\n");
				e.time_start += (5 - e.time_start % 5);
			}
			e.room->time_last_free = e.time_start + 5;
			
			//判断要在电梯里待多久 
			timeseconds2structure(e.time_start, sstr_h, sstr_m, sstr_s);
			if(e.agent->item_list.front().id_room / 100 == 0) next_time_start = e.time_start + 30 * abs(e.room->id_Room / 100 - 1); 
			else next_time_start = e.time_start + 30 * abs(e.room->id_Room / 100 - e.agent->item_list.front().id_room / 100); 
			timeseconds2structure(next_time_start, estr_h, estr_m, estr_s);
			e.agent->str_record += (sstr_h + ":"+ sstr_m + ":" + sstr_s + " " + estr_h + ":"+ estr_m + ":" + estr_s + " " + "Stay in elevator" + "\n");
			
			//接下来应该判断下一个任务
			if(e.agent->item_list.front().id_room / 100)
			{
				timeseconds2structure(next_time_start, sstr_h, sstr_m, sstr_s);
				next_time_start += 10;
				timeseconds2structure(next_time_start, estr_h, estr_m, estr_s);
				e.agent->str_record += (sstr_h + ":"+ sstr_m + ":" + sstr_s + " " + estr_h + ":"+ estr_m + ":" + estr_s + " " + "Transfer from elevator to room " + roomidint2string(e.agent->item_list.front().id_room) + "\n");
				q.push(event(e.agent, &rooms[e.agent->item_list.front().id_room / 100][e.agent->item_list.front().id_room % 100], next_time_start, _WAITING_IN_FRONT_OF_ROOM));
			}
			else q.push(event(e.agent, &rooms[0][0], next_time_start, _EXIT));
			break;
	}
	return;
}

int main()
{
	vector<Agent> agents;
	char id;
	while(cin >> id)
	{
		if(id == '.') break;
		agents.push_back(Agent(id - 'A'));
	}
	sort(agents.begin(), agents.end(), cmp);
	//初始化房间
	for(int i = 0; i <=10; i++) for(int j = 0; j <= 10;j++) rooms[i][j].Init(i * 100 + j);
	vector<Agent>::iterator iter = agents.begin();
	while(iter != agents.end())
	{
		q.push(event(&(*iter), &rooms[(iter->item_list).front().id_room / 100][(iter->item_list).front().id_room % 100], iter->time_start, _ENTRY));
		iter++;
	}	
	while(!q.empty())
	{
		deal_program(q.top());
		q.pop();
	}
	iter = agents.begin();
	while(iter != agents.end())
	{
		cout << (char)(iter->id + 'A') << endl;
		cout << iter->str_record << endl;
		iter++;
	}
	return 0;
}
