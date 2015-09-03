#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string stripStr(string str)
{
	string result;
	int count = 0;

	result.resize(str.length());
	for (int i = 0; i<str.length(); ++i)
	{
		if (str[i] == ' ')
			continue;
		if (str[i] >= 'A' && str[i] <= 'Z')
			result[count++] = (char)(str[i]+32);
		else
			result[count++] = str[i];

	}

	return result.substr(0, count);
}

int main(int argc, char const *argv[])
{
	int n;
	string str1, str2, temp;

	getline(cin, temp, '\n');
	n = atoi(temp.c_str());

	while (n-- != 0)
	{
		getline(cin, str1, '\n');
		getline(cin, str2, '\n');
		if (n != 0)
			getline(cin, temp, '\n');
	
		if (stripStr(str1) == stripStr(str2))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
	return 0;
}