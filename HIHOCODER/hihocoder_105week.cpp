#include <iostream>

using namespace std;

struct node
{
	node* upper;
	node* left;
	node* right;
	long long value;//ID 
	long long intre;//兴趣值 
	long long num;
	long long total_intre;
	long long lazy;
};

node* head;

void marking(node* now, long long delta)
{
	now->lazy = now->lazy + delta;
	now->total_intre = now->total_intre + now->num * delta;
	now->intre = now->intre + delta;
	return;
}

void update(node* now)
{
	now->num = 1;
	now->total_intre = now->intre;
	
	if(now->left)
	{
		now->num = now->num + now->left->num;
		now->total_intre = now->total_intre + now->left->total_intre;
	}
	
	if(now->right)
	{
		now->num = now->num + now->right->num;
		now->total_intre = now->total_intre + now->right->total_intre; 
	}
	
	return;
}

void send(node* now)
{
	if(now->left) marking(now->left, now->lazy);
	if(now->right) marking(now->right, now->lazy);
	now->lazy = 0;
	update(now);
}

node* insert(node*& now, long long v, long long in)
{
	if(now == NULL) 
	{
		now = new node();
		now->upper = now->left = now->right = NULL;
		now->value = v;
		now->intre = in;
		now->num = 1;
		now->total_intre = now->intre; 
		now->lazy = 0;
		return now;
	}
	else
	{	
		send(now);
		if(v < now->value)
		{
			if(now->left == NULL)
			{
				node* temp = new node();
				temp->left = temp->right = NULL;
				temp->value = v;
				temp->upper = now;
				temp->intre = in;
				temp->num = 1;
				temp->total_intre = temp->intre;
				temp->lazy = 0;
				now->left = temp;
				update(now);
				return temp;
			}
			else 
			{
				node* t = insert(now->left, v, in);
				update(now);
				return t;
			}
		}
		else
		{
			if(now->right == NULL)
			{
				node* temp = new node();
				temp->left = temp->right = NULL;
				temp->value = v;
				temp->upper = now;
				temp->intre = in;
				temp->num = 1;
				temp->total_intre = temp->intre;
				temp->lazy = 0;
				now->right = temp;
				update(now);
				return temp;
			}
			else
			{
				node* t = insert(now->right, v, in);
				update(now);
				return t;
			}
		}
	}
}
 

node* find(node* now, long long v)
{
	if(now == NULL) return NULL;
	if(now->value == v) return now;
	node * temp;
	temp = find(now->left, v);
	if(temp) return temp;
	temp = find(now->right, v);
	if(temp) return temp;
	return NULL;
}

void show(node* now)
{
	if(now == NULL) return;
	show(now->left);
	cout << now->value << endl;
	show(now->right);
	return;	
} 

node* next_element(node* now)//寻找now的next 
{
	node* next = now->right;
	if(next == NULL) return NULL;
	else
	{
		while(next->left) next = next->left;
		return next;	
	}	
}

node* previous_element(node* now)
{
	node* previous = now->left;
	if(previous == NULL) return NULL;
	else
	{
		while(previous->right) previous = previous->right;
		return previous; 
	}
}

node* next_element(node* now, long long v)//从now开始找值为v的next 
{
	if(now->value < v)
	{
		node* next = next_element(now);
		if(next->value > v) return next;
		else return next_element(now->right, v);
	}
	else if(now->value == v)
	{
		return next_element(now);
	}
	else if(now->value > v)
	{
		node* previous = previous_element(now);
		if(previous->value <= v) return now;
		else return next_element(now->left, v);
	}
}

node* previous_element(node* now, long long v)
{
	if(now->value < v)
	{
		node* next = next_element(now);
		if(next->value >= v) return now;
		else return previous_element(now->right, v);
	}
	else if(now->value == v)
	{
		return previous_element(now);
	}
	else if(now->value > v)
	{
		node* previous = previous_element(now);
		if(previous->value < v) return previous;
		else return previous_element(now->left, v);
	}
}

node* query_not_more_than(node* now, long long v)
{
	if(now == NULL) return NULL;
	else if(now->value == v) return now;
	else if(now->value < v)
	{
		node* now_right = next_element(now);
		if(now_right == NULL) return now;
		else
		{
			if(now_right->value > v) return now;
			else if(now_right->value == v) return now_right;
			else return query_not_more_than(now->right, v);
		}
	}
	else if(now->value > v)
	{
		node* now_left = previous_element(now);
		if(now_left == NULL) return NULL;
		else
		{
			if(now_left->value <= v) return now_left;
			else return query_not_more_than(now->left, v);
		}
	}
}

void right_rotate(node* now)
{
	node* child = now->left;
	
	send(now);
	send(child);
	
	child->upper = now->upper;	
	
	if(now->upper)
	{
		if(now->upper->left == now) now->upper->left = child;
		else now->upper->right = child;
	}
	
	now->left = child->right;
	if(child->right) child->right->upper = now;
	
	child->right = now;
	now->upper = child;
	
	update(now);
	update(child); 
	
	return;
}

void left_rotate(node* now)
{
	node* child = now->right;
	
	send(now);
	send(child);
	
	child->upper = now->upper;
	
	if(now->upper) 
	{
		if(now->upper->left == now) now->upper->left = child;
		else now->upper->right = child;
	}
	
	now->right = child->left;
	if(child->left) child->left->upper = now;
	
	child->left = now;
	now->upper = child;
	
	update(now);
	update(child);
	
	return;
}

void splay(node* now, node* up)
{
	node* p;
	node* g;
	if(!now) return;
	while(now->upper != up)
	{
		p = now->upper;
		if(p->upper == up)
		{
			if(p->left == now) right_rotate(p);
			else if(p->right == now) left_rotate(p);
		}
		else
		{
			g = p->upper;
			if(g->left == p)
			{
				if(p->left == now) 
				{
					right_rotate(g);
					right_rotate(p);
				}
				else if(p->right == now)
				{
					left_rotate(p);
					right_rotate(g);
				}
			}
			else if(g->right == p)
			{
				if(p->right == now)
				{
					left_rotate(g);
					left_rotate(p);
				}
				else if(p->left == now)
				{
					right_rotate(p);
					left_rotate(g);
				}
			}
		}
	} 
	if(!up) head = now;
	return;
}

void remove(node* now)
{
	node* node_k = previous_element(now);
	node* node_l = next_element(now);
	splay(node_k, NULL);
	splay(node_l, node_k);
	node_l->left = NULL;
	return;
}

void remove_all(node* now)
{
	if(now->upper)
	{
		if(now->upper->left == now) now->upper->left = NULL;
		else now->upper->right = NULL;
	}
	if(now->left) remove_all(now->left);
	if(now->right) remove_all(now->right);
	delete now;
	return;
}

int main()
{
	head = NULL;
	insert(head, -1, 0);
	insert(head, 100000001, 0); 
	long long n;
	cin >> n;
	string str;
	long long k, l, m;
	while(n--)
	{
		cin >> str;
		
		if(str == "I") 
		{
			cin >> k >> l;
			node* now = insert(head, k, l); 
			splay(now, NULL);
		}
		else if(str == "Q")
		{
			cin >> k >> l;
			
			node* previous = previous_element(head, k);
			node* next = next_element(head, l);
			
			splay(previous, NULL);
			splay(next, previous);
			
			cout << next->left->total_intre << endl;
			
		}
		else if(str == "M")
		{
			cin >> k >> l >> m;
			node* previous = previous_element(head, k);
			node* next = next_element(head, l);
			
			splay(previous, NULL);
			splay(next, previous);
			
			marking(next->left, m);
		}
		else if(str == "D")
		{
			cin >> k >> l;
			node* previous = previous_element(head, k);
			node* next = next_element(head, l);
			
			splay(previous, NULL);
			splay(next, previous);
			next->left = NULL;
			
			update(next);
			update(previous);
		}
	}
	return 0;
} 
