#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

vector< vector<int> > subStrNum;

int max(int x1, int x2, int x3)
{
	int maximum = x1;
	if(x2>maximum)
		maximum = x2;
	if(x3>maximum)
		maximum = x3;

	return maximum;
}

int main(int argc, char const *argv[])
{
	string str1, str2;

	subStrNum.resize(201);
	for (int i = 0; i<201; ++i)
		subStrNum[i].resize(201);

	for (int i = 0; i<201; ++i)
	{
		subStrNum[i][0] = 0;
		subStrNum[0][i] = 0;
	}

	while (cin >> str1 >> str2)
	{
		for (int i = 1; i <= str1.length(); ++i)
		{
			for (int j = 1; j <= str2.length(); ++j)
			{
				subStrNum[i][j] = max(subStrNum[i-1][j], subStrNum[i][j-1], subStrNum[i-1][j-1]+(str1[i-1]==str2[j-1]));
			}
		}

		cout << subStrNum[str1.length()][str2.length()] << endl;

	}
	return 0;
}