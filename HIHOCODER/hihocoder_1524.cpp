#include <iostream>

int  num[100000], tmp[100000];
long long cnt;

void Merge_Sort(int l, int r)
{
    int mid = l + (r - l)/2;
    int p = l, p1 = l, p2 = mid + 1;

    while(p1 <= mid && p2 <= r)
    {
        if(num[p1] > num[p2])
        {
            tmp[p++] = num[p2++];
            cnt += (mid - p1 + 1);
        }
        else
        {
            tmp[p++] = num[p1++];
        }
    }

    while(p1 <= mid)
    {
        tmp[p++] = num[p1++];
    }
    
    while(p2 <= r)
    {
        tmp[p++] = num[p2++];
    }

    for(int i = l; i <= r; ++i)
    {
        num[i] = tmp[i];
    }
    
    return;
}

void Merge(int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int mid = l + (r - l) / 2;

    Merge(l, mid);
    Merge(mid + 1, r);
    Merge_Sort(l, r);

    return;
}

int main()
{
    int N;
    std::cin >> N;

    for(int i = 0; i < N; ++i)
    {
        std::cin >> num[i];
    }

    cnt = 0;
    Merge(0, N - 1);
        
    std::cout << cnt << std::endl;

    return 0;
}
