#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
    int N, x0, y0, x1, y1;
    
    std::cin >> N;

    std::map<std::pair<int, int>, int> m;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> x0 >> y0 >> x1 >> y1;

        ++m[std::make_pair(x0, y0)];
        ++m[std::make_pair(x0, y1)];
        ++m[std::make_pair(x1, y0)];
        ++m[std::make_pair(x1, y1)];
    }

    std::vector<int> v_x, v_y;

    for (std::map<std::pair<int, int>, int>::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        if(iter->second & 1 != 0)
        {
            v_x.push_back((iter->first).first);
            v_y.push_back((iter->first).second);
        }
    }

    std::sort(v_x.begin(), v_x.end());
    std::sort(v_y.begin(), v_y.end());

    std::cout << v_x[0] << " " << v_y[0] << " " << v_x[3] << " " << v_y[3] << std::endl;
    return 0;
}
