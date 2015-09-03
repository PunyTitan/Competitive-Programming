#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>


using namespace std;

vector<int> privateKey;

string encrypt(int k, string str)
{
	string result;
	result.resize(str.length());

	for (int i = 0; i<k; ++i)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j<str.length(); ++j)
				result[privateKey[j]] = str[j];
		}
		else
		{
			for (int j = 0; j<str.length(); ++j)
				str[privateKey[j]] = result[j];
		}
	}

	if (k % 2 == 0)
		return str;
	else
		return result;
}

int main(int argc, char const *argv[])
{
	int n;
	int k;
	int findK;
	string current_str;

	while (cin >> n)
	{
		if (n == 0)
			break;

		privateKey.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> privateKey[i];
			--privateKey[i];
		}
		getchar();

		while (getline(cin, current_str, '\n'))
		{
			if (current_str[0] == '0')
				break;

			k = 0;
			for (findK = 0; findK<current_str.length(); ++findK)
			{
				if (current_str[findK] == ' ')
					break;
				k *= 10;
				k += current_str[findK] - '0';
			}
			current_str = current_str.substr(findK + 1, current_str.length() - findK - 1);
			current_str += string(n - current_str.length(), ' ');

			cout << encrypt(k, current_str) << endl;
		}
	}

	return 0;
}