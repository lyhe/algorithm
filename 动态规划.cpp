#include <iostream>
#include <stdlib.h>

using namespace std;

int MaxSubString(int *A, int n)
{
	int start = A[n - 1];
	int All	  = A[n - 1];

	for (int i = n - 2; i >= 0; i --)	//从后向前遍历，反之亦可
	{
		start = max( A[i], A[i] + start);
		All   = max( start, All);
	}
	return All;
}
int main()
{
	int A[6] = {1, -2, 3, 5, -3, 2};
	cout << MaxSubString(A, 6) << endl;
	return 0;
}
