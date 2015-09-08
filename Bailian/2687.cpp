#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	vector<int> data;
	int temp;

	cin >> n;
	data.resize(n);

	for (int i = 0; i<data.size(); ++i)
		cin >> data[i];

	for (int i = 0; i<data.size() / 2; ++i)
	{
		temp = data[i];
		data[i] = data[n - 1 - i];
		data[n - 1 - i] = temp;
	}

	for (int i = 0; i<data.size(); ++i)
		cout << data[i] << " ";
	return 0;
}
