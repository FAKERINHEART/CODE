#include <iostream>

using namespace std;

class edge;

class node
{
public:
	int in_degree;
	int num_virus; 
	edge* first;     
}; 

class edge
{
public:
	int value;
	edge* next;
};

class q_node
{
public:
	int value;
	q_node* next;	
};

class q
{
public:
	q_node* head;
	q_node* tail;	
};

int main()
{
	int N, M, K; 
	cin >> N >> M >> K;
	node* _node = new node[N];
	for(int j = 0; j < N; j++)
	{
		_node[j].in_degree = 0;
		_node[j].num_virus = 0;
		_node[j].first = NULL;
	}
	
	for(int j = 0; j < K; j++)
	{
		int _temp;
		cin >> _temp;
		_node[_temp - 1].num_virus = 1;
	}
	
	int _node_first, _node_second;
	for(int j = 0; j < M; j++)
	{
		cin >> _node_first >> _node_second;
		edge* temp = new edge;
		temp->value = _node_second;
		temp->next = _node[_node_first - 1].first;
		_node[_node_first - 1].first = temp;
		_node[_node_second - 1].in_degree++;
	}		
	
	q* _queue = new q;
	_queue->head = new q_node;
	_queue->head->value = -1;
	_queue->head->next = NULL;
	_queue->tail = _queue->head;
	
	for(int j = 0; j < N; j++)
	{
		if(_node[j].in_degree == 0)
		{
			q_node* temp = new q_node;
			temp->value = j + 1;
			temp->next = NULL;
			_queue->tail->next = temp;
			_queue->tail = temp;
		}
	}
	
	q_node* test;
	while(_queue->head->next)
	{
		test = _queue->head->next;
		edge* temp = _node[test->value - 1].first;
		while(temp)
		{
			_node[temp->value - 1].in_degree--;
			_node[temp->value - 1].num_virus = (_node[temp->value - 1].num_virus + _node[test->value - 1].num_virus) % 142857;
			if(_node[temp->value - 1].in_degree == 0)
			{
				q_node* newtemp = new q_node;
				newtemp->value = temp->value;
				newtemp->next = NULL;
				_queue->tail->next = newtemp;
				_queue->tail = newtemp;
			}
			temp = temp->next;
		}
		_queue->head->next = test->next;
		delete test;
	}
	delete _queue->head;
	delete _queue;
	
	int sum = 0;
	for(int j = 0; j < N; j++) sum = (sum + _node[j].num_virus) % 142857; 
	cout << sum << endl;
	
	for(int j = 0; j < N; j++)
	{
		while(_node[j].first)
		{
			edge* temp = _node[j].first;
			_node[j].first = temp->next;
			delete temp;
		}	
	}
	delete[] _node;
	return 0;
} 
