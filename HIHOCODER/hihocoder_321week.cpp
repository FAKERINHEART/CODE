#include <iostream>
#include <cstring>

struct Edge
{
    int to;
    int next;
};

struct Data
{
    int left;
    int right;
    int value;
};

int V[100005], head[100005], total_edge_num;
Edge edge[100005];
int query_in[100005], query_out[100005], query_value[100005];
Data data[400020];

//根据dfs形成从x到dfs下标的映射
void dfs(int x, int &index)
{
    query_in[x]        = ++index;
    query_value[index] = V[x];

    for (int i = head[x]; i != -1; i = edge[i].next)
    {
        int next = edge[i].to;
        dfs(next, index);
    }

    query_out[x] = index;

    return;
}

void build(int left, int right, int index)
{
    data[index].left  = left;
    data[index].right = right;

    if (left == right)
    {
        data[index].value = query_value[left];

        return;
    }

    int mid = (left + right) / 2;
    build(left, mid, 2 * index);
    build(mid + 1, right, 2 * index + 1);

    data[index].value = std::min(data[2 * index].value, data[2 * index + 1].value);

    return;
}

void update(int left, int right, int index, int value)
{
    if (left == data[index].left && right == data[index].right)
    {
        data[index].value = value;
        return;
    }

    int mid = (data[index].left + data[index].right) / 2;

    if (right <= mid)
    {
        update(left, right, 2 * index, value);
    }
    else if (left >= mid + 1)
    {
        update(left, right, 2 * index + 1, value);
    }
    else
    {
        update(left, mid, 2 * index, value);
        update(mid + 1, right, 2 * index + 1, value);
    }

    data[index].value = std::min(data[2 * index].value, data[2 * index + 1].value);

    return;
}

int find(int left, int right, int index)
{
    if (left == data[index].left && right == data[index].right)
    {
        return data[index].value;
    }

    int mid = (data[index].left + data[index].right) / 2;

    if (right <= mid)
    {
        return find(left, right, 2 * index);
    }
    else if (left >= mid + 1)
    {
        return find(left, right, 2 * index + 1);
    }
    else
    {
        return std::min(find(left, mid, 2 * index), find(mid + 1, right, 2 * index + 1));
    }
}

int main(void)
{
    int N;
    std::cin >> N;

    memset(head, -1, sizeof(head));
    total_edge_num = 0;

    for (int i = 1; i <= N; ++i)
    {
        std::cin >> V[i];
    }

    for (int i = 2; i <= N; ++i)
    {
        int P;
        std::cin >> P;

        edge[total_edge_num].to   = i;
        edge[total_edge_num].next = head[P];
        head[P]                   = total_edge_num++;
    }

    int index = 0;
    dfs(1, index);

    build(1, N, 1);

    int Q;
    std::cin >> Q;

    while (Q--)
    {
        int op, x, u;
        std::cin >> op;

        if (op == 1)
        {
            std::cin >> x >> u;
            //
            update(query_in[x], query_in[x], 1, u);
        }
        else
        {
            std::cin >> x;
            std::cout << find(query_in[x], query_out[x], 1) << std::endl;
        }
    }

    return 0;
}
