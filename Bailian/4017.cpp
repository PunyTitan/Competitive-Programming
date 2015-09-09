#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int sum[31];
	int zeros[31];
	int ones[31];

	sum[1] = 1;
	zeros[2] = 1;
	ones[2] = 1;
	sum[2] = 2;

	for (int i = 3; i <= 30; ++i)
	{
		zeros[i] = ones[i - 1];
		ones[i] = zeros[i - 1] + ones[i - 1];
		sum[i] = zeros[i] + ones[i];
	}

	while (cin >> n)
	{
		cout << sum[n] << endl;
	}
	return 0;
}