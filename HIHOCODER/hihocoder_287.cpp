#include <iostream>
#include <string>

int main()
{
    int N, M, K;
    std::cin >> N >> M >> K;
    
    std::string A[50];

    for(int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    
    for (int i = 0; i < K; ++i)
    {
        int H, W;
        std::cin >> H >> W;

        std::string B[100], C[100];

        for(int j = 0; j < H; ++j)
        {
            std::cin >> B[j];
        }
        
        bool is_match = true;
        
        do
        {
            for (int j = 0; j < N; ++j)
            {
                C[j] = A[j];
            }
            
            int len = M;
            
            while (len <= W)
            {
                for (int j = 0; j < N; ++j)
                {
                    C[j] += A[j];
                }
                
                len += M;
            }
            
            int k = 0;

            for(; k < N; ++k)
            {
                if(C[k].find(B[0]) != std::string::npos)
                {
                    break;
                }
            }
            
            if (k == N)
            {
                is_match = false;
                break;
            }
            
            for (int j = 0; j < H; ++j)
            {
                if (C[k].find(B[j]) != std::string::npos)
                {
                    k = (k + 1) % N;
                }
                else
                {
                    is_match = false;
                    break;
                }
            }
        }while(false);

        if(is_match == true)
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
