#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> alphabet(26);

void count(string str)
{
	for (int i = 0; i<str.length(); ++i)
	{
		if (str[i]>'A' && str[i]<'Z')
			++alphabet[str[i] - 'A'];
	}
}

int main(int argc, char const *argv[])
{
	string str1, str2, str3, str4;
	int maximum = 0;

	getline(cin, str1, '\n');
	getline(cin, str2, '\n');
	getline(cin, str3, '\n');
	getline(cin, str4, '\n');

	count(str1);
	count(str2);
	count(str3);
	count(str4);

	for (int i = 0; i<26; ++i)
	if (alphabet[i]>maximum)
		maximum = alphabet[i];

	for (int i = 0; i<maximum; ++i)
	{
		for (int j = 0; j<26; ++j)
		{
			if (maximum - alphabet[i] <= i)
				cout << "*" << " ";
			else
				cout << "  ";
		}
		cout << endl;
	}

	for (int i = 0; i < 26; ++i)
		cout << (char)('A' + i)<< " ";

		return 0;
}