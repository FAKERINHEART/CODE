#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    bool leaf;
    bool val;
    bool change;
    std::vector<int> children;
};

Node data[210];

int DFS(int p)
{
    if (data[p].leaf == true)
    {
       data[p].change = false;

       return -1;
    }

    int l = data[p].children[0];
    int r = data[p].children[1];
    int L = DFS(l);
    int R = DFS(r);

    if (data[p].val == true)
    {
        data[p].val = data[l].val | data[r].val;

        if (data[l].val == true && data[r].val == true) //如果左右两颗子树都为1, 操作符为or, 则要改变其中一颗子树的值, 且改变操作符
        {
            int MIN = 1 << 18;

            if (data[l].change == true && MIN > L)
            {
                MIN = L;
            }

            if (data[r].change == true && MIN > R)
            {
                MIN = R;
            }

            if (MIN < (1 << 18))
            {
                data[p].change = true;

                return MIN + 1;
            }
        }
        else if (data[l].val == true && data[r].val == false || data[l].val == false && data[r].val == true)
        {
            data[p].change = true;

            return 1;
        }
        else
        {
            int MIN = 1 << 18;

            if (data[l].change == true && MIN > L)
            {
                MIN = L;
            }

            if (data[r].change == true && MIN > R)
            {
                MIN = R;
            }

            if (MIN < (1 << 18))
            {
                data[p].change = true;

                return MIN;
            }
        }
    }
    else
    {
        data[p].val = data[l].val & data[r].val;

        if (data[l].val == true && data[r].val == true) //如果左右两颗子树都为1, 操作符为and, 则要改变其中一颗子树的值
        {
            int MIN = 1 << 18;

            if (data[l].change == true && MIN > L)
            {
                MIN = L;
            }

            if (data[r].change == true && MIN > R)
            {
                MIN = R;
            }

            if (MIN < (1 << 18))
            {
                data[p].change = true;

                return MIN;
            }
        }
        else if (data[l].val == true && data[r].val == false || data[l].val == false && data[r].val == true)
        {
            data[p].change = true;

            return 1;
        }
        else
        {
            int MIN = 1 << 18;

            if (data[l].change == true && MIN > L)
            {
                MIN = L;
            }

            if (data[r].change == true && MIN > R)
            {
                MIN = R;
            }

            if (MIN < (1 << 18))
            {
                data[p].change = true;

                return MIN + 1;
            }
        }
    }

    data[p].change = false;

    return -1;
}


int main()
{
    int N, root;

    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        int P;
        string s;

        cin >> P >> s;

        if (P != 0)
        {
            data[P].children.push_back(i);
        }
        else
        {
            root = i;
        }

        if (s == "TRUE")
        {
            data[i].leaf = true;
            data[i].val = true;
        }
        else if (s == "FALSE")
        {
            data[i].leaf = true;
            data[i].val = false;
        }
        else if (s == "AND")
        {
            data[i].leaf = false;
            data[i].val = false;
        }
        else
        {
            data[i].leaf = false;
            data[i].val = true;
        }
    }

    cout << DFS(root) << endl;

    return 0;
}
