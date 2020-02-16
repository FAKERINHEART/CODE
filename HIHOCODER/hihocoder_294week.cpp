#include <iostream>
#include <cstring>

struct Node
{
    int edge_index;
    int degree_in;
};

struct Edge
{
    int y;
    int next_edge_index;
};

Edge edge[100005];
Node node[100005];
int root_node;
int sub_root_node;

int dfs(int x)
{
    int ret = 0;

    for (int i = node[x].edge_index; i != 0; i = edge[i].next_edge_index)
    {
        int y = edge[i].y;
        ret ^= dfs(y);
    }

    return ret + (x != root_node? 1: 0);
}
 
int dfs2(int x)
{
    int ret = 0;

    for (int i= node[x].edge_index; i != 0; i = edge[i].next_edge_index)
    {
        int y = edge[i].y;
        ret ^= dfs2(y);
    }

    return ret + (x != sub_root_node? 1: 0);
}
 
int main()
{
    int Q, n;
    std::cin >> Q;

    while (Q--)
    {
        memset(node, 0, sizeof(node));
        memset(edge, 0, sizeof(edge));

        int edge_index = 0;
        std::cin >> n;

        for (int i = 1; i < n; ++i)
        {
            int x, y;

            std::cin >> x >> y;

            //edge_index = 0不用
            ++edge_index;

            edge[edge_index].y = y;
            edge[edge_index].next_edge_index = node[x].edge_index;
            node[x].edge_index = edge_index;
            ++node[y].degree_in;
        }

        for (int i = 1; i <= n; ++i) 
        {
            if (node[i].degree_in == 0) 
            {
                root_node = i;
                break;
            }
        }

        int ans1 = dfs(root_node) > 0? 1: 0;
        
        std::cout << ans1;

        int ans2 = 0;

        for (int i = node[root_node].edge_index; i != 0;i = edge[i].next_edge_index)
        {
            sub_root_node = edge[i].y;
            ans2 ^= dfs2(sub_root_node);
        }

        ans2 = ans2 > 0?1: 0;
        std::cout << ans2;
    }

    std::cout << std::endl;

    return 0;
}

