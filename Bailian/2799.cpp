#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> numbers(10000);
vector<int> pointIndex(10000);

int main(int argc, char const *argv[])
{
	int n;
	int max = 0;

	cin >> n;
	for (int i = 0; i<n; ++i)
	{
		cin >> numbers[i];
		pointIndex[i] = numbers[i].find('.');
		if (pointIndex[i]>max)
			max = pointIndex[i];
	}

	for (int i = 0; i<n; ++i)
	{
		cout << string(max - pointIndex[i], ' ') << numbers[i] << endl;
	}

	return 0;
}
