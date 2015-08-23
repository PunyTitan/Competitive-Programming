#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;

vector<int> split(string str)
{
	vector<int> result;
	stringstream strS(str);
	string token;

	while (getline(strS, token, ' '))
		result.push_back(atoi(token.c_str()));

	return result;
}

int main(int argc, char const *argv[])
{
	string line;
	vector<int> numbers;
	int numOfPairs;

	while (getline(cin, line, '\n'))
	{
		numOfPairs = 0;
		numbers = split(line);

		if (numbers[0] == -1)
			break;

		sort(numbers.begin(), numbers.end());

		for (int i = 0; i + 1<numbers.size(); ++i)
		{
			for (int j = i + 1; j<numbers.size(); ++j)
			{
				if (numbers[i] * 2 == numbers[j])
				{
					++numOfPairs;
					break;
				}

			}
		}

		cout << numOfPairs << endl;
		numbers.clear();
	}
	return 0;
}