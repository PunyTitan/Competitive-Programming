#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int size1, size2, s;
	int current;
	map<int, int> setOne;
	map<int, int> setTwo;
	map<int, int>::iterator itr;
	int result;

	cin >> n;
	while (n-- != 0)
	{
		setOne.clear();
		setTwo.clear();

		cin >> s >> size1;

		for (int i = 0; i<size1; ++i)
		{
			cin >> current;
			itr = setOne.find(current);
			if (itr == setOne.end())
				setOne[current] = 1;
			else
				++(itr->second);
		}

		cin >> size2;
		for (int i = 0; i<size2; ++i)
		{
			cin >> current;
			itr = setTwo.find(current);
			if (itr == setTwo.end())
				setTwo[current] = 1;
			else
			{
				++(itr->second);
			}

		}

		result = 0;
		for (map<int, int>::iterator oneitr = setOne.begin(); oneitr != setOne.end(); ++oneitr)
		{
			itr = setTwo.find(s - oneitr->first);
			if (itr == setTwo.end())
				continue;
			result += (itr->second) * (oneitr->second);
		}

		cout << result << endl;
	}
	return 0;
}