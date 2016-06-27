#include <iostream>

using namespace std;

struct node
{
	node* upper;
	node* left;
	node* right;
	int value;
};

node* head;

node* insert(node*& now, int v)
{
	if(now == NULL) 
	{
		now = new node();
		now->upper = now->left = now->right = NULL;
		now->value = v;
		return now;
	}
	else
	{	
		if(v < now->value)
		{
			if(now->left == NULL)
			{
				node* temp = new node();
				temp->left = temp->right = NULL;
				temp->value = v;
				temp->upper = now;
				now->left = temp;
				return temp;
			}
			else return insert(now->left, v);
		}
		else
		{
			if(now->right == NULL)
			{
				node* temp = new node();
				temp->left = temp->right = NULL;
				temp->value = v;
				temp->upper = now;
				now->right = temp;
				return temp;
			}
			else return insert(now->right, v);
		}
	}
}
 

node* find(node* now, int v)
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

node* next_element(node* now)
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

node* query_not_more_than(node* now, int v)
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
	
	return;
}

void left_rotate(node* now)
{
	node* child = now->right;
	
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

void remove(node* now, int v)
{
	if(!now) return;
	if(v < now->value) remove(now->left, v);
	else if(v > now->value) remove(now->right, v);
	
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
	
	int n;
	cin >> n;
	string str;
	int k, l;
	insert(head, -1);
	insert(head, 1000000001);
	while(n--)
	{
		cin >> str;
		
		if(str == "I") 
		{
			cin >> k;
			node* now = insert(head, k); 
			splay(now, NULL);
			//show(head);
		}
		else if(str == "Q")
		{
			cin >> k;
			node* temp = query_not_more_than(head, k);
			if(temp) 
			{
				cout << temp->value << endl;
				splay(temp, NULL);
			}
			else cout << "NULL" << endl;
		}
		else if(str == "D")
		{
			cin >> k >> l;
			node* node_k = find(head, k);
			if(!node_k) node_k = insert(head, k);
			splay(node_k, NULL);
			node* previous = previous_element(node_k);
			
			node* node_l = find(head, l);
			if(!node_l) node_l = insert(head, l);
			splay(node_l, NULL);
			node* next = next_element(node_l);
			
			splay(previous, NULL);
			splay(next, previous);
			next->left = NULL;
		}
	}
	return 0;
} 
