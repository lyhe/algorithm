#include <iostream>
#include <stdlib.h>
using namespace std;
int MaxSubString(int *A, int n);

int main()
{
	int A[6] = {1, -2, 3, 5, -3 ,2};
	cout << MaxSubString(A, 6) << endl; 
	return 0;
}

int MaxSubString(int *A, int n)
{
	int max = -999999999;
	int sum;

	for (int i = 0; i < n; i ++)
	{
		sum = 0;
		cout << "i=" << i << " " << max << endl;
		for (int j = i; j < n; j ++)
		{
			sum += A[j];
			if (sum > max)
				max = sum;
		}
	}
	return max;
}
