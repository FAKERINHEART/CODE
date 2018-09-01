#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

struct Node
{
    static const int k_sub_node_num = 26;
    Node *fail, *next[k_sub_node_num];
    int count;
    int accumulate;
    bool flag;

    Node()
    {
        fail = NULL;
        memset(next, 0, sizeof(next));
        count = 0;
        accumulate = 0;
        flag = false;
    }
};

void Insert(Node *root, string &str)
{
    Node *p = root;

    for (int i = 0; i < str.length(); ++i)
    {
        int index = str[i] - 'a';
        
        if (p->next[index] == NULL)
        {
            p->next[index] = new Node();
        }
        
        p = p->next[index];
        p->count = i;
        ++p->accumulate;
    }

    p->flag = true;
    
    return;
}

void Query(Node *root, string &str)
{
    Node *p = root;

    for(int i = 0; i < str.length(); ++i)
    {
        int index = str[i] - 'a';

        while (p != NULL && p->next[index] == NULL)
        {
            p = p->fail;
        }

        p = (p == NULL) ? root : p->next[index];
        Node *temp = p;
        
        while (temp != root)
        {
            if (temp->flag)
            {
                for (int j = 0; j <= temp->count; ++j)
                {
                    str[i - j] = '*';
                }

                break;
            }

            temp = temp->fail;
        }
    }
    
    return;
}

void BuildAC(Node *root)
{
    queue<Node *> q;
    root->fail = NULL;
    q.push(root);
    
    while (q.empty() == false)
    {
        Node *temp = q.front();
        q.pop();
        
        Node *temp_fail;
        
        for (int i = 0; i < Node::k_sub_node_num; ++i)
        {
            if (temp->next[i])
            {
                temp_fail = temp->fail;

                while (temp_fail != NULL)
                {
                    if (temp_fail->next[i] != NULL)
                    {
                        temp->next[i]->fail = temp_fail->next[i];
                        break;
                    }

                    temp_fail = temp_fail->fail;
                }
                
                if(temp_fail == NULL)
                {
                    temp->next[i]->fail = root;
                }

                q.push(temp->next[i]);
            }
        }
    }
    
    return;
}

void Delete(Node *cur)
{
    for (int i = 0; i < Node::k_sub_node_num; ++i)
    {
        if (cur->next[i] != NULL)
        {
            Delete(cur->next[i]);
        }
    }

    delete cur;
    
    return;
}

int main()
{
    int N;
    
    cin >> N;
    
    Node *root = new Node();

    string str;

    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        Insert(root, str);
    }
    
    BuildAC(root);
    cin >> str;
    Query(root, str);
    cout << str << endl;
    Delete(root);

    return 0;
}
