#include <iostream>
#include <random>

using namespace std;

struct node
{
	node* upper;
	node* left;
	node* right;
	int value;
	int weight;	
};

node* head;

default_random_engine generator;
uniform_int_distribution<int> distribution(1, 100000);

node* insert(node*& now, int v)
{
	if(now == NULL) 
	{
		now = new node();
		now->upper = now->left = now->right = NULL;
		now->value = v;
		now->weight = distribution(generator);
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
				temp->weight = distribution(generator);
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
				temp->weight = distribution(generator);
				temp->upper = now;
				now->right = temp;
				return temp;
			}
			else return insert(now->right, v);
		}
	}
}

void show(node* now)
{
	if(now == NULL) return;
	show(now->left);
	cout << now->value << " " << now->weight << endl;
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

void rotate(node* now)
{
	node* up;
	while(now->upper)
	{
		up = now->upper;
		if(now->weight < up->weight)
		{
			if(now == up->left) right_rotate(up);
			else left_rotate(up);
		}
		else break;
	}
	return;
}

void remove(node* now)
{
	node* child;
	while(now->left && now->right)
	{
		child = now->left;
		if(now->left > now->right) child = now->right;
		
		if(child == now->left) right_rotate(now);
		else left_rotate(now);
	}
	
	if(now->left)
	{
		now->left->upper = now->upper;
		if(now->upper)
		{
			if(now == now->upper->left) now->upper->left = now->left;
			else now->upper->right = now->left;
		}
	}
	else if(now->right)
	{
		now->right->upper = now->upper;
		if(now->upper)
		{
			if(now == now->upper->left) now->upper->left = now->right;
			else now->upper->right = now->right;
		}
	}
	
	delete now;
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
	
	int n;
	cin >> n;
	string str;
	int k;
	while(n--)
	{
		cin >> str >> k;
		if(str == "I") 
		{
			node* now = insert(head, k);
			rotate(now);
			//show(head);
		}
		else 
		{
			node* temp = query_not_more_than(head, k);
			if(temp) cout << temp->value << endl;
			else cout << "NULL" << endl;
		}
	}
	return 0;
}
