#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int count[100001];

int main()
{
    int T;
    cin >> T;
    
    
    for (int i = 0; i < T; ++i)
    {
        int N, K;
        cin >> N >> K;
        
        std::vector<int> A;
        memset(count, 0, sizeof(count));
        
        for (int j = 0; j < N; ++j)
        {
            int temp;
            cin >> temp;
            A.push_back(temp);
            ++count[temp];
        }
        
        bool flag = false;

        for (int i = 0; i < A.size(); ++i)
        {
            if (count[A[i]] == 0)
            {
                continue;
            }
            else
            {
                --count[A[i]];
            }
            
            //std::cout << A[i] << ": ";
            
            for (int j = A[i] + 1; j <= A[i] + K - 1; ++j)
            {
                //std::cout << j << "/" << count[j] << ", ";
                
                if (count[j] == 0)
                {
                    flag = true;
                    break;
                }
                else
                {
                    --count[j];
                }
            }
            
            //std::cout << std::endl;
            
            if (flag == true)
            {
                break;
            }
        }
        
        if (flag == true)
        {
            std::cout << "NO" << std::endl;
        }
        else
        {
            std::cout << "YES" << std::endl;
        }
    }
    
    return 0;
}
