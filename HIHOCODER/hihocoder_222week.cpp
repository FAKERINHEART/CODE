#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int up_[500][500], down_[500][500], left_[500][500], right_[500][500];

int main()
{
    int N;
    cin >> N;
    
    std::string matrix[N];
    
    for (int i = 0; i < N; ++i)
    {
        cin >> matrix[i];

        for (int j = 0; j < N; ++j)
        {
            if (matrix[i][j] != '0')
            {
                right_[i][j] = 1;

                if (j >= 1)
                {
                    right_[i][j] += right_[i][j - 1];
                }
                
                down_[i][j] = 1;
                
                if (i >= 1)
                {
                    down_[i][j] = down_[i - 1][j] + 1;
                }
            }
        }
    }
    
    for (int i = N - 1; i >= 0; --i)
    {
        for (int j = N - 1; j >= 0; --j)
        {
            if (matrix[i][j] != '0')
            {
                left_[i][j] = 1;
                
                if (j <= N - 2)
                {
                    left_[i][j] += left_[i][j + 1];
                }
                
                up_[i][j] = 1;
                
                if (i <= N - 2)
                {
                    up_[i][j] = up_[i + 1][j] + 1;
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int temp_min = 1 << 30;
            
            temp_min = std::min(temp_min, right_[i][j]);
            temp_min = std::min(temp_min, down_[i][j]);
            temp_min = std::min(temp_min, left_[i][j]);
            temp_min = std::min(temp_min, up_[i][j]);
            ans = std::max(ans, temp_min);
            
            //cout << i << ", " << j << ": " << temp_min << endl;
        }
    }

    cout << ans - 1 << endl;

    return 0;
}
