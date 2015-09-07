#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> result(410);
	string str1, str2;
	string long_str, short_str;
	int next;
	int long_len, short_len, long_index, short_index;
	int result_len, result_index;

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
	result_len = long_len*short_len + 1;

	int count = 0;
	for (short_index = short_len - 1; short_index >= 0; --short_index, ++count)
	{
		next = 0;
		result_index = result_len - 1 - count;

		for (long_index = long_len - 1; long_index >= 0; --long_index)
		{
			result[result_index] += (long_str[long_index] - '0') * (short_str[short_index] - '0') + next;
			if (result[result_index] >= 10)
			{
				next = result[result_index] / 10;
				result[result_index] %= 10;
			}
			else
				next = 0;
			--result_index;

		}
		result[result_index] += next;
	}

	bool valid = false;
	for (int i = 0; i<result_len; ++i)
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