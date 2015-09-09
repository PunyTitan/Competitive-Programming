#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, k;
vector<int> data;

void move()
{
	bool found = false;
	int temp;

	if (data.size() == 1)
		return;

	for (int i = data.size() - 2; i >= 0; --i)
	{
		for (int j = data.size() - 1; j>i; --j)
		{
			if (data[j]>data[i])
			{
				temp = data[j];
				data[j] = data[i];
				data[i] = temp;
				found = true;
				sort(data.begin() + i + 1, data.end());
				break;
			}
		}
		if (found)
			break;
	}

	if (!found)
	{
		for (int i = 0; i<n; ++i)
		{
			data[i] = i + 1;
		}
	}
}

int main(int argc, char const *argv[])
{


	cin >> m;
	while (m-- != 0)
	{
		cin >> n >> k;
		data.resize(n);
		for (int i = 0; i<n; ++i)
			cin >> data[i];


		while (k-- != 0)
			move();

		for (int i = 0; i < n; ++i)
			cout << data[i] << " ";
			cout << endl;
	}

	return 0;
}