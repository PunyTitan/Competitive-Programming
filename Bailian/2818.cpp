#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>


using namespace std;

vector<int> privateKey(200);

void encrypt(int k, string & str)
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

	if (k % 2 != 0)
		str = result;
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


		for (int i = 0; i < n; ++i)
		{
			cin >> privateKey[i];
			--privateKey[i];
		}


		while (cin>>k)
		{
			if (k == 0)
				break;

			getchar();

			getline(cin, current_str, '\n');
			
			current_str += string(n - current_str.length(), ' ');

			encrypt(k, current_str);

			cout << current_str << endl;
		}

		cout<<endl;
	}

	return 0;
}