#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int convert(string number)
{
	int digit = 1;
	double result = 0;

	for (int i = number.length() - 1; i >= 0; --i)
	{
		if (number[i] == '1')
			result += pow(2.0, digit) - 1;
		else if (number[i] == '2')
			result += 2 * (pow(2.0, digit) - 1);
		++digit;
	}

	return (int)result;
}

int main(int argc, char const *argv[])
{
	string current_number;

	while (cin >> current_number)
	{
		if (current_number.length() == 1 && current_number[0] == '0')
			break;

		cout << convert(current_number) << endl;

	}
	return 0;
}