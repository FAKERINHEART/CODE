#include <iostream>
#include <algorithm>
#include <string.h>

int A[100000];
int B[100000];
int N;

int main()
{
	std::cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		std::cin >> A[i];
	}
	
	memcpy(B, A, sizeof(B));
	
	std::sort(A, A + N);
	
	int begin, end;
	
	for (int i = 0; i < N; ++i)
	{
		if (A[i] != B[i])
		{
			begin = i;
			break;
		}
	}
	
	for (int i = N - 1; i > 0; --i)
	{
		if (A[i] != B[i])
		{
			end = i;
			break;
		}
	}
	
	int num = (end >= begin)? (end - begin + 1): 0;
	
	std::cout << num << std::endl;

	return 0;
}
