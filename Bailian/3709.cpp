#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int binToDec(string number)
{
	double result = 0;
	int digit = 0;
	for (int i = number.length()-1; i >= 0; --i, ++digit)
	{
		result += (number[i] - '0') * pow(2.0, digit);
	}

	return (int)result;
}

vector<int> decToTri(int number)
{
	vector<int> result;
	while (number != 0)
	{
		result.push_back(number % 3);
		number /= 3;
	}

	return result;
}

int main(int argc, char const *argv[])
{
	int n;
	string current_number;
	vector<int> result;

	cin >> n;
	while (n-- != 0)
	{
		cin >> current_number;
		result = decToTri(binToDec(current_number));
		for (int i = result.size() - 1; i >= 0; --i)
			cout << result[i];
		cout << endl;
	}
	return 0;
}