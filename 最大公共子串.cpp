#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void
LCS(string str1, string str2)
{
	string str;
	int len1 	= str1.size();
	int len2 	= str2.size();
	int maxlen 	= len1 > len2 ? len1 : len2;

	if (len1 == 0 || len2 == 0)
	{
		cout << "" << endl;
		return;
	}
	if (str1.size() < str2.size()) 
	{
		str = str2; str2 = str1; str1 = str;
	}

	int *result = new int[maxlen]();
	int *max	= new int[maxlen]();
	int *index	= new int[maxlen]();

	for (int i = 0; i < str2.size(); i ++)
	{
		for (int j = str1.size() - 1; j >= 0; j --)
		{
			if (str2[i] == str1[j])
			{
				j == 0 ? result[0] = 1 : result[j] = result[j - 1] + 1;
			}
			else
				result[j == 0 ? 0 : j] = 0;

			if (result[j] > max[0])
			{
				max[0] 		= result[j];
				index[0]	= j;

				for (int k = 1; k < maxlen; k ++)
				{
					max[k]		=0;
					index[k]	=0;
				}
			}
			else if (result[j] == max[0])
			{
				for (int k = 1; k < maxlen; k ++)
				{
					if (max[k] == 0)
					{
						max[k] 		= result[j];
						index[k]	= j;
						break;
					}
				}
			}
		}
		for (int k = 0; k < maxlen; k ++)
			cout << result[k] << " ";
		cout << endl;
	}

	for (int j = 0; j < maxlen; j ++)
	{
		if(max[j] != 0)
		{
			cout << "第" << j + 1 << "个公共子串:" << endl;
			cout << str1.substr(index[j] - max[j] + 1, max[j]) << endl;
		}
		else
			break;
	}

	delete []result;
	delete []max;
	delete []index;
}

int main(int argv, char **argc)
{
	string str1(argc[1]);
	string str2(argc[2]);

	LCS(str1, str2);

	return 0;
}