#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>


using namespace std;

vector<int> privateKey(200);
vector<int> period(200);
int n;

void calculatePeriod()
{
	int index, count;
	for (int i = 0; i<n; ++i)
	{
		index = i;
		count = 0;
		while (true)
		{
			index = privateKey[index];
			++count;
			if (index == i)
				break;
		}
		period[i] = count;
	}
}

void encrypt(int k, string & str)
{
	string result;
	int current_k;
	int index;

	str += string(n - str.length(), ' ');
	result.resize(n);

	for (int i = 0; i<n; ++i)
	{
		current_k = k%period[i];
		index = i;
		while (current_k-- != 0)
		{
			index = privateKey[index];
		}
		result[index] = str[i];
	}

	str = result;
}

int main(int argc, char const *argv[])
{

	int k;
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

		calculatePeriod();

		while (cin >> k)
		{
			if (k == 0)
				break;

			getchar();

			getline(cin, current_str, '\n');

			encrypt(k, current_str);

			cout << current_str << endl;
		}

		cout << endl;
	}

	return 0;
}