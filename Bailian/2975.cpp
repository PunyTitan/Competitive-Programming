#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

void decode(string & str)
{
	for (int i = 0; i<str.length(); ++i)
	{
		if (str[i] >= 'F' && str[i] <= 'Z')
		{
			str[i] -= 5;
		}
		else if (str[i] >= 'A' && str[i] <= 'E')
		{
			str[i] = 'Z' + (str[i] - 'A') - 4;
		}
	}
}

int main(int argc, char const *argv[])
{
	string message;
	string command;

	while (cin >> command)
	{
		getchar();
		if (command == "ENDOFINPUT")
			break;
		getline(cin, message, '\n');

		cin >> command;

		decode(message);
		cout << message << endl;
	}
	return 0;
}