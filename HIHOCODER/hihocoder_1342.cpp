#include <iostream>

using namespace std;

struct Node 
{
    Node *l, *r;
    int x, y;
    Node(int _x, int _y)
    {
        l = r = NULL;
        x = _x;
        y = _y;
    }
};

int Height(int height)
{
	if(height == 1)
	{
   		return 0;
	}
    else if(height == 3)
	{
        return 2;
    }
	else
	{
		return Height(height - 1) * 2 + 1;
	}
}

void init(Node* now, int height)
{
	if (height == 1)
	{
    	return;
    }
    else
    {
    	int steps = Height(height) + 1;
    	now->l = new Node(now->x + steps, now->y - steps);
    	now->r = new Node(now->x + steps, now->y + steps);
    	init(now->l, height - 1);
    	init(now->r, height - 1);
		return;
	}

}

int count(Node* now, int x1, int y1, int x2, int y2)
{
    int sum = 0;
    
    if (now->x >= x1 && now->y >= y1 && now->x <= x2 && now->y <= y2)
	{
        ++sum;
    }
    
    if (now->l)
	{
        sum += count(now->l, x1, y1, x2, y2);
    }
    
    if (now->r)
	{
        sum += count(now->r, x1, y1, x2, y2);
    }
    
    return sum;
}


int main()
{
    int N, M;
    cin >> N >> M;
    
    Node *root = new Node(0, 0);
    init(root, N);
    
    while(M--)
	{
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << count(root, x1, y1, x2, y2) << endl;
    }
    
    delete root;
    
    return 0;
}

