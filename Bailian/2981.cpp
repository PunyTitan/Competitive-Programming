#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	string str1, str2;
	string short_str;
	string long_str;

	vector<int> result(201);
	int next;
	int long_len;
	int short_len;

	fill(result.begin(), result.end(), 0);

	cin >> str1 >> str2;

	if (str1.length()>str2.length())
	{
		long_str = str1;
		short_str = str2;
	}
	else
	{
		long_str = str2;
		short_str = str1;
	}

	long_len = long_str.length();
	short_len = short_str.length();

	next = 0;
	while (true)
	{
		if (long_len == 0)
		{
			result[long_len] = next;
			break;
		}


		if (short_len == 0)
		{
			for (; long_len>0; --long_len)
			{
				result[long_len] += (long_str[long_len - 1] - '0') + next;
				if (result[long_len] >= 10)
				{
					next = result[long_len] / 10;
					result[long_len] %= 10;
				}
				else
					next = 0;
			}
			result[long_len] = next;
			break;
		}

		result[long_len] += (long_str[long_len - 1] - '0') + (short_str[short_len - 1] - '0') + next;
		if (result[long_len] >= 10)
		{
			next = result[long_len] / 10;
			result[long_len] %= 10;
		}
		else
			next = 0;

		--long_len;
		--short_len;
	}


	bool valid = false;
	for (int i = 0; i<=long_str.length(); ++i)
	{
		if (result[i] != 0)
		{
			valid = true;
			cout << result[i];
		}
		else if (valid)
			cout << result[i];

	}

	if (!valid)
		cout << 0 << endl;
	else
		cout << endl;




	return 0;
}