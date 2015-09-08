#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string str1, str2;
	int index = 0;
	char result = '=';

	getline(cin, str1, '\n');
	getline(cin, str2, '\n');

	for (int i = 0; i < str1.length(); ++i)
		if (str1[i] >= 'A' && str1[i] <= 'Z')
			str1[i] += 32;	
	for (int i = 0; i < str2.length(); ++i)
		if (str2[i] >= 'A' && str2[i] <= 'Z')
			str2[i] += 32;	

	for (index = 0;; ++index)
	{
		if (index == str1.length() && index == str2.length())
			break;
		if (index == str1.length())
		{
			result = '<';
			break;
		}
		if (index == str2.length())
		{
			result = '>';
			break;
		}

		if (str1[index] < str2[index])
		{
			result = '<';
			break;
		}
		else if (str1[index]>str2[index])
		{
			result = '>';
			break;
		}
	}

	cout << result;
	return 0;
}