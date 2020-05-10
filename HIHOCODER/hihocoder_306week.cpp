#include <iostream>
#include <set>
#include <utility>
#include <algorithm>

int parent[200001], sz[200001];
std::set<int> s[200001];
int n, m;
std::pair<int, int> ans[400002];

struct node
{
    int x, y, z, id;
    bool operator<(const node &one)const
    {
        return z < one.z;
    }
};

node e[400002];

int getparent(int x)
{
    return (parent[x] != 0 )? parent[x] = getparent(parent[x]) : x;
}

void update(int i, int x, int y)
{
    if (s[x].size() == 0 || s[y].size() == 0)
    {
        return;
    }

    //找到最大的y: ny
    int ny = *--s[y].end();
    std::set<int>::iterator it = s[x].lower_bound(ny);

    //>=ny的第一个x
    if (it == s[x].begin())
    {
        return;
    }

    //<ny的第一个px
    int px = *--it;
    //>=px的第一个py
    int py = *s[y].lower_bound(px);

    if (px > ans[i].first || (px == ans[i].first && py < ans[i].second))
    {
        ans[i] = std::make_pair(px, py);
    }

    return;
}

int main()
{
    std::cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        sz[i] = 1;
        s[i].insert(i);
    }

    for (int i = 1; i <= m; ++i)
    {
        std::cin >> e[i].x >> e[i].y >> e[i].z;
        e[i].id = i;
    }

    std::sort(e + 1, e + m + 1);

    for (int i = 1; i <= m; ++i)
    {
        int x = e[i].x, y = e[i].y;
        int pa = getparent(x);
        int pb = getparent(y);

        if (pa == pb)
        {
            continue;
        }

        if (sz[pa] < sz[pb])
        {
            std::swap(pa, pb);
            std::swap(x, y);
        }

        update(e[i].id, pa, pb);
        update(e[i].id, pb, pa);

        for (std::set<int>::iterator iter = s[pb].begin(); iter != s[pb].end(); ++iter)
        {
            s[pa].insert(*iter);
        }

        s[pb].clear();
        parent[pb] = pa;
        sz[pa] += sz[pb];
    }

    for (int i = 1; i <= m; ++i)
    {
        std::cout << ans[i].first << " " << ans[i].second << std::endl;
    }

    return 0;
}
