#include <iostream>
#include <vector>

using namespace std;

struct point
{
	int x;
	int y;
	point(int t_x, int t_y): x(t_x), y(t_y){}
};

struct QuadtreeNode
{
	const int NODE_CAPACITY;
	vector<point> points;
	double up;
	double down;
	double left;
	double right;
	QuadtreeNode* children[4];
	QuadtreeNode(double t_up, double t_down, double t_left, double t_right): NODE_CAPACITY(32), up(t_up), down(t_down), left(t_left), right(t_right)
	{
		points.clear();
		children[0] = children[1] = children[2] = children[3] = NULL;
	}
	bool Insert(int x, int y);
	int Query(int q_up, int q_down, int q_left, int q_right);
	void traverse();
};

bool QuadtreeNode::Insert(int x, int y)
{
	if(x < this->left || x > this->right || y < this->down || y > this->up)
	{
		return false;
	}
	else
	{
		if(this->points.size() < this->NODE_CAPACITY)
		{
			this->points.push_back(point(x, y));
			//cout << "aaa" << this->up << " " << this->down << " " << this->left << " " << this->right << endl; 
		}
		else
		{
			if(this->children[0] == NULL)
			{
				double mid_up_down = (this->up + this->down) / 2;
				double mid_left_right = (this->left + this->right) / 2;
				this->children[0] = new QuadtreeNode(this->up, mid_up_down, this->left, mid_left_right);
				this->children[1] = new QuadtreeNode(this->up, mid_up_down, mid_left_right, this->right);
				this->children[2] = new QuadtreeNode(mid_up_down, this->down, this->left, mid_left_right);
				this->children[3] = new QuadtreeNode(mid_up_down, this->down, mid_left_right, this->right);
			}

			for(int i = 0; i < 4; ++i)
			{
				if(x >= this->children[i]->left && x <= this->children[i]->right && y >= this->children[i]->down && y <= this->children[i]->up)
				{
					if(this->children[i]->Insert(x, y) == true)
					{
						break;	
					}
				}
			}
		}
		return true;
	}
}

int QuadtreeNode::Query(int q_up, int q_down, int q_left, int q_right)
{
	//cout << "qqq" << q_up << " " << q_down << " " << q_left << " " << q_right << endl;
	if(q_up < this->down || q_down > this->up || q_left > this->right || q_right < this->left) return 0;
	//cout << "22222222222222" << endl;
	int x = (q_left + q_right) / 2;
	int y = (q_up + q_down) / 2;
	int r = q_right - x;
	int total = 0;
	//cout << "sss" << this->up << " " << this->down << " " << this->left << " " << this->right << endl; 
	for(int i = 0; i < this->points.size(); ++i)
	{
		//cout << "rrr" << points[i].x << " " << points[i].y << endl;
		if((points[i].x - x) * (points[i].x - x) + (points[i].y - y) * (points[i].y - y) <= r * r)
		{
			++total;
		}
	}
	if(this->children[0] != NULL)
	{
		for(int i = 0; i < 4; i++)
		{
			total += (this->children[i]->Query(q_up, q_down, q_left, q_right));
		}
	}
	return total;
}

void QuadtreeNode::traverse()
{
	cout << "Boundary: " << this->up << " " << this->down << " " << this->left << " " << this->right << endl;
	cout << "Points: ";
	for(int i = 0; i < this->points.size(); ++i)
	{
		cout << "(" << this->points[i].x << ", " << this->points[i].y << "), ";
	}
	cout << endl;
	if(this->children[0])
	{
		for(int i = 0; i < 4; ++i)
		{
			this->children[i]->traverse();
		}
	}
	return;
}

QuadtreeNode* root;

int main()
{
	root = new QuadtreeNode(30000, 0, 0, 30000);
	int N, M, x, y, r;
	cin >> N >> M; 
	for(int i = 0; i < N; ++i)
	{
		cin >> x >> y;
		//cout << root->Insert(x, y) << endl;
		root->Insert(x, y);
	}
	//root->traverse();
	//cout << endl;
	for(int i = 0; i < M; ++i)
	{
		cin >> x >> y >> r;
		cout << root->Query(y + r, y - r, x - r, x + r) << endl;
	}
	return 0;
} 
