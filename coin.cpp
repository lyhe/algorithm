#include <iostream>

using namespace std;

int coin[3] = {1, 3, 5};
int dp[15] ;
int min (int a, int b)
{
	return (a > b) ? b : a;
}

void dp_fun (int i, int num)
{
	if (i == 0)
	{
		dp[i] = 0;
		dp_fun(1, num);
		return;
	}
	else
	{
		int MIN = 9999;
		for (int j = 0; j < 3; j ++)
		{
			if (i >= coin[j])
			{
				MIN = min(dp[i - coin[j]] + 1, MIN);
			}
		}

		dp[i] = MIN;
		if (i == num)
			return;
		else
			dp_fun (i + 1, num);
	}
}

int main()
{
	dp_fun(0, 14);
	for (int i = 0; i < 15; i ++)
	{
		cout << "凑齐" << i << "元，至少需要" << dp[i] << "枚硬币" << endl;
	}
	return 0;
}
