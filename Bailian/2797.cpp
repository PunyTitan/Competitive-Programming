#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<string> strs;
	string current_str, subStr;
	bool notMatch;

	while (cin >> current_str)
	{
		strs.push_back(current_str);
	}

	for (int i = 0; i<strs.size(); ++i)
	{
		cout << strs[i] << " ";
		for (int j = 1; j <= strs[i].length(); ++j)
		{
			notMatch = true;
			subStr = strs[i].substr(0, j);

			for (int k = 0; k<strs.size(); ++k)
			{
				if (i == k)
					continue;

				if (subStr == strs[k].substr(0, j))
				{
					notMatch = false;
					break;
				}

			}

			if (notMatch)
			{
				cout << subStr << endl;
				break;
			}
		}
		if(!notMatch)
			cout << strs[i] << endl;
	}
	return 0;
}