#include <iostream>
#include <string>

using namespace std;

struct node
{
	node* upper;
	node* left;
	node* right;
	int value;
	int num;
};

node* root;

void show(node* now)
{
	if(now == NULL) return;
	show(now->left);
	cout << "qqqqq" << now->value << " " << now->num << endl;
	show(now->right);
	return;	
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
	
	child->num = now->num;
	int num_left = 0, num_right = 0;
	if(now->left) num_left = now->left->num;
	if(now->right) num_right = now->right->num;
	now->num = num_left + num_right + 1;
	
	if(child->upper == NULL) root = child;
	
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
	
	child->num = now->num;
	int num_left = 0, num_right = 0;
	if(now->left) num_left = now->left->num;
	if(now->right) num_right = now->right->num;
	now->num = num_left + num_right + 1;
	
	if(child->upper == NULL) root = child;
	
	return;
}

void maintain(node* now, bool flag)
{
	if(now)
	{
		if(flag == false)
		{
			if(now->left && now->left->left && now->right && now->left->left->num > now->right->num)
			{
				right_rotate(now);
				maintain(now, true);
			}
			else if(now->left && now->left->right && now->right && now->left->right->num > now->right->num)
			{
				left_rotate(now->left);
				right_rotate(now);
				maintain(now->upper->left, false);
				maintain(now->upper->right, true);
			}
			else return;
		}
		else
		{
			if(now->right && now->right->right && now->left && now->right->right->num > now->left->num)
			{
				left_rotate(now);
				maintain(now, false);
			}
			else if(now->right && now->right->left && now->left && now->right->left->num > now->left->num)
			{
				right_rotate(now->right);
				left_rotate(now);
				maintain(now->upper->left, false);
				maintain(now->upper->right, true);
			}
			else return;
		}
		maintain(now->upper, false);
		maintain(now->upper, true);
	}
	
	return;
}


node* insert(node* &now, int v)
{
	if(now == NULL)
	{
		now = new node();
		now->left = now->right = now->upper = NULL;
		now->value = v;
		now->num = 1;
		return now;
	}
	else
	{
		now->num = now->num + 1;
		node* child = NULL;
		if(now->value > v)
		{
			if(now->left) child = insert(now->left, v);
			else
			{
				insert(child, v);
				child->upper = now;
				now->left = child;
			}
			
		}
		else
		{
			if(now->right) child = insert(now->right, v);
			else
			{
				insert(child, v);
				child->upper = now;
				now->right = child;
			}
			
		}
		maintain(now, now->value <= v);
		return child;
	}
}

void query(node* now, int order)
{
	if(now->left)
	{
		if(now->left->num == order - 1) cout << now->value << endl;
		else if(now->left->num >= order) query(now->left, order);
		else query(now->right, order - 1 - now->left->num);
	}
	else
	{
		if(order == 1) cout << now->value << endl;
		else query(now->right, order - 1);
	}
	return;
}

node* next_element(node* now)//Ñ°ÕÒnowµÄnext 
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

bool remove(node* now, int v)
{
	if(now == NULL) return false;
	if(now->value < v) 
	{
		bool ret = remove(now->left, v);
		now->num = now->num - 1;
		return ret;
	}
	else if(now->value > v) 
	{
		bool ret = remove(now->right, v);
		now->num = now->num - 1;
		return ret;
	}
	else
	{
		node* pre = previous_element(now);
		if(pre == NULL) 
		{
			now->right->upper = now->upper;
			delete now;
			return true;
		}
		else
		{
			now->value = pre->value;
			now->num = now->num - 1;
			
			if(pre->upper != now) 
			{
				pre->upper->right = NULL;
				node* temp = now->left;
				while(temp != pre)
				{
					temp->num = temp->num - 1;
					temp = temp->right;
				}
			}
			else pre->upper->left = NULL;
			
			delete pre;
			return true;
		}
	}
}

int main()
{
	root = NULL;
	
	int n;
	cin >> n;
		
	string str;
	int temp;
	while(n--)
	{
		cin >> str >> temp;
		if(str == "I") insert(root, temp);
		else query(root, temp);
	}
	return 0;
}
