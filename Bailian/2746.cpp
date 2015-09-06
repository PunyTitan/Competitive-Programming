#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	list<int> monkeys;
	int offset;
	list<int>::iterator itr;

	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;
		monkeys.clear();
		for (int i = 1; i <= n; ++i)
			monkeys.push_back(i);

		itr = monkeys.begin();

		while (monkeys.size() != 1)
		{
			offset = (m - 1) % monkeys.size();
			for (int i = 0; i<offset; ++i)
			{
				++itr;
				if (itr == monkeys.end())
					itr = monkeys.begin();
			}

			itr = monkeys.erase(itr);
			if (itr == monkeys.end())
				itr = monkeys.begin();
		}

		cout << *(monkeys.begin()) << endl;
	}
	return 0;
}