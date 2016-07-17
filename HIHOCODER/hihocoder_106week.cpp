#include <iostream>
#include <string>

using namespace std;

struct node
{
	node* left;
	node* right;
	int value;
	int num;
	node(int v): left(NULL), right(NULL), value(v), num(1){};
};

node* root;

void show(node* now)
{
	if(now == NULL) return;
	show(now->left);
	cout << now->value << " " << now->num << endl;
	show(now->right);
	return;	
} 

int size(node* &now)
{
	if(!now) return 0;
	else return now->num;
}

void right_rotate(node* &now)
{
	node* child = now->left;
	
	now->left = child->right;
	child->right = now;
	child->num = now->num;
	now->num = size(now->left) + size(now->right) + 1;
	
	now = child;	
	
	return;
}

void left_rotate(node* &now)
{
	node* child = now->right;
		
	now->right = child->left;
	child->left = now;
	child->num = now->num;
	now->num = size(now->left) + size(now->right) + 1;
	
	now = child;
	
	return;
}

void maintain(node* &now, bool flag)
{
	if(!now) return;
	if(flag == false)
	{
		if(now->left && size(now->left->left) > size(now->right))
		{
			right_rotate(now);
			maintain(now->right, true);
		}
		else if(now->left && size(now->left->right) > size(now->right))
		{
			left_rotate(now->left);
			right_rotate(now);
			maintain(now->left, false);
			maintain(now->right, true);
		}
		else return;
	}
	else
	{
		if(now->right && size(now->right->right) > size(now->left))
		{
			left_rotate(now);
			maintain(now->left, false);
		}
		else if(now->right && size(now->right->left) > size(now->left))
		{
			right_rotate(now->right);
			left_rotate(now);
			maintain(now->left, false);
			maintain(now->right, true);
		}
		else return;
	}
	maintain(now, false);
	maintain(now, true);
	
	return;
}

node* insert(node* &now, int v)
{
	if(!now)
	{
		now = new node(v);
		return now;
	}
	else
	{
		++(now->num);
		node* child;
		if(now->value > v) child = insert(now->left, v);
		else child = insert(now->right, v);
		maintain(now, now->value <= v);
		return child;
	}
}

void query(node* now, int order)
{
	if(size(now->left) + 1 == order) cout << now->value << endl;
	else if(size(now->left) + 1 > order) query(now->left, order);
	else query(now->right, order - 1 - size(now->left));
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
			node* temp_now = now;
			now->right = now->right->right;
			now->left = now->right->left;
			now->num = now->right->num;
			now->value = now->right->value;
			delete temp_now;
			return true;
		}
		else
		{
			now->value = pre->value;
			now->num = now->num - 1;
			
			if(now->left != pre) 
			{
				node* temp = now->left;
				while(temp->right != pre)
				{
					--(temp->num);
					temp = temp->right;
				}
				--(temp->num);
				temp->right = NULL;
			}
			else now->left = NULL;
			
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
