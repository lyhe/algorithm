#include <iostream>
#include <stdlib.h>

using namespace std;

int MaxSubString(int *A, int n)
{
	int Start 	= A[0];
	int All		= A[0];

	for (int i = 1; i < n; i ++)
	{
		Start 	= max(A[i], A[i] + Start);
		All		= max(Start, All);
	}
	return All;
}

int main()
{
	int A[6] = {1, -2, 3, 5, -3, 2};

	cout << MaxSubString(A, 6) << endl;
	return 0;
}