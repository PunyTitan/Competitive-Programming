#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

vector< vector<int> > subStrNum;
vector<bool> matched(201);

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
		fill(matched.begin(), matched.end(), false);
		for (int i = 1; i <= str1.length(); ++i)
		{
			for (int j = 1; j <= str2.length(); ++j)
			{
				subStrNum[i][j] = subStrNum[i - 1][j]<subStrNum[i][j - 1] ? subStrNum[i][j - 1] : subStrNum[i - 1][j];
				if (str1[i - 1] == str2[j - 1] && !matched[j])
				{
					++subStrNum[i][j];
					matched[j] = true;
					for (int index = j+1; index <= str2.length(); ++index)
						subStrNum[i][index] = subStrNum[i][j]>subStrNum[i-1][index]? subStrNum[i][j] : subStrNum[i-1][index];
					break;
				}
			}
		}

		cout << subStrNum[str1.length()][str2.length()] << endl;

	}
	return 0;
}