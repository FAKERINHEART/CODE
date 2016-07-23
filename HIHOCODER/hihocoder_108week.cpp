#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct block
{
	block* previous;
	block* next;
	int key;
	int length;
};

block* head;
block* position[5000];
int N, M;

struct node
{
	int key;
	int start;	
	node(int x, int y): key(x), start(y){}
};

vector<node> v;

block* findEmpty(int l)
{
	block* temp = head;
	while(temp)
	{
		if(temp->key == 0 && temp->length >= l) return temp;
		temp = temp->next;
	}
	return NULL;
}

void Insert(block* empty, int k, int l)
{
	if(empty->length == l) empty->key = k;
	else
	{
		block* temp = new block();
		temp->key = 0;
		temp->length = empty->length - l;
		temp->next = empty->next;
		temp->previous = empty;
		if(temp->next) temp->next->previous = temp;
		
		empty->key = k;
		empty->length = l;
		empty->next = temp;
	}
	
	position[k] = empty;
	
	return;
}

void Delete(int k)
{
	block* temp = position[k];
	//cout << "qqq" << temp->key << " " << temp->length << endl;
	block* temp_previous = temp->previous;
	block* temp_next = temp->next;
	
	if(temp_previous && temp_previous->key == 0)
	{
		temp->length += temp_previous->length;
		temp->previous = temp_previous->previous;
		if(temp_previous->previous) temp_previous->previous->next = temp;
		else head = temp;
		delete temp_previous;
	}
	
	if(temp_next && temp_next->key == 0)
	{
		temp->length += temp_next->length;
		temp->next = temp_next->next;
		if(temp_next->next) temp_next->next->previous = temp;
		delete temp_next;
	}
	
	temp->key = 0;
	
	return;
}

bool compare(node a, node b)
{
	return a.key <= b.key;
}

int main()
{	
	cin >> N >> M;
	head = new block();
	head->key = 0;
	head->length = M;
	head->previous = NULL;
	head->next = NULL;
	
	int lastDeleteData = 0;
	int l;
	block* p;
	for(int i = 0; i < N; i++)
	{
		cin >> l;
		while(true)
		{
			p = findEmpty(l);
			if(p)
			{
				Insert(p, i + 1, l);
				break;
			}
			else
			{
				lastDeleteData++;
				Delete(lastDeleteData);
			}
		}
	}
	
	block* temp = head;
	int start = 0;
	while(temp)
	{
		if(temp->key != 0) v.push_back(node(temp->key, start));
		start += temp->length;
		temp = temp->next;
	}
	sort(v.begin(), v.end(), compare);
	for(int i = 0; i < v.size(); i++) cout << v[i].key << " " << v[i].start << endl;
	
	return 0;
}
