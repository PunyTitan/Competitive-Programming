#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	string str1, str2;
	int index, i;
	bool matched = false;

	while (cin >> str1 >> str2)
	{
		index = 0;
		for (i = 0; i<str1.length(); ++i)
		{
			matched = false;
			for (; index<str2.length(); ++index)
			{
				if (str1[i] == str2[index])
				{
					++index;
					matched = true;
					break;
				}
			}
			if (!matched)
			{
				cout << "No" << endl;
				break;
			}
		}

		if (matched)
			cout << "Yes" << endl;
	}
	return 0;
}