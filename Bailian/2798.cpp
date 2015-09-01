}
#include <iostream>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	string input_number;
	vector<char> result;
	double current_dec;

	cin >> n;

	while (n-- != 0)
	{
		cin >> input_number;

		if (input_number.length() % 4 == 1)
			input_number = "000" + input_number;
		else if (input_number.length() % 4 == 2)
			input_number = "00" + input_number;
		else if (input_number.length() % 4 == 3)
			input_number = "0" + input_number;

		for (int i = 0; i<input_number.length(); i += 4)
		{
			current_dec = (input_number[i] - '0') * 8 + (input_number[i + 1] - '0') * 4 + (input_number[i + 2] - '0') * 2 + (input_number[i + 3] - '0') * 1;
			switch ((int)current_dec)
			{
			case 15:
				cout << 'F';
				break;
			case 14:
				cout << 'E';
				break;
			case 13:
				cout << 'D';
				break;
			case 12:
				cout << 'C';
				break;
			case 11:
				cout << 'B';
				break;
			case 10:
				cout << 'A';
				break;
			default:
				cout << current_dec;
				break;
			}
		}
		cout << endl;
	}

	return 0;
}