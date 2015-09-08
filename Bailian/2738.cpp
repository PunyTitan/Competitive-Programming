#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	string str1, str2;
	string int_part1, int_part2, fact_part1, fact_part2;
	vector<int> fact_result(110);
	vector<int> int_result(110);
	int split_index;
	int next;
	int result_index;
	int long_len;
	int count;

	cin >> n;
	while (n-- != 0)
	{
		cin >> str1 >> str2;
		getchar();
		getchar();

		fill(fact_result.begin(), fact_result.end(), 0);
		fill(int_result.begin(), int_result.end(), 0);


		//split the data into int part and fact part
		split_index = str1.find('.');
		int_part1 = str1.substr(0, split_index);
		fact_part1 = str1.substr(split_index + 1, str1.length() - 1 - split_index);

		split_index = str2.find('.');
		int_part2 = str2.substr(0, split_index);
		fact_part2 = str2.substr(split_index + 1, str2.length() - 1 - split_index);


		//caculate the fact part
		long_len = fact_part1.length()<fact_part2.length() ? fact_part2.length() : fact_part1.length();
		next = 0;
		result_index = long_len - 1;
		for (int long_index = long_len - 1; long_index >= 0; --long_index, --result_index)
		{
			if (long_index<fact_part1.length())
				fact_result[result_index] += fact_part1[long_index] - '0';
			if (long_index<fact_part2.length())
				fact_result[result_index] += fact_part2[long_index] - '0';

			fact_result[result_index] += next;

			if (fact_result[result_index] >= 10)
			{
				next = fact_result[result_index] / 10;
				fact_result[result_index] %= 10;
			}
			else
				next = 0;
		}


		//calculate the int part
		long_len = int_part1.length()<int_part2.length() ? int_part2.length() : int_part1.length();
		result_index = int_result.size() - 1;
		for (count = 0; count<long_len; ++count, --result_index)
		{
			if ((int)int_part1.length() - 1 - count >= 0)
				int_result[result_index] += int_part1[int_part1.length() - 1 - count] - '0';
			if ((int)int_part2.length() - 1 - count >= 0)
				int_result[result_index] += int_part2[int_part2.length() - 1 - count] - '0';
			int_result[result_index] += next;

			if (int_result[result_index] >= 10)
			{
				next = int_result[result_index] / 10;
				int_result[result_index] %= 10;
			}
			else
				next = 0;
		}
		int_result[result_index] = next;

		//output the result
		bool valid = false;
		for (int i = 0; i<int_result.size(); ++i)
		{
			if (int_result[i] != 0)
			{
				valid = true;
				cout << int_result[i];
			}
			else if (valid)
				cout << int_result[i];
		}

		if (!valid)
			cout << 0;
		cout << ".";

		valid = false;
		for (int i = fact_result.size() - 1; i >= 0; --i)
		{
			if (valid)
				break;
			if (fact_result[i] == 0)
				fact_result[i] = -1;
			else
				valid = true;
		}

		valid = false;
		for (int i = 0; i<fact_result.size() - 1; ++i)
		{
			if (fact_result[i] != -1)
			{
				valid = true;
				cout << fact_result[i];
			}
			else
				break;
		}

		if (!valid)
			cout << 0 << endl;
		else
			cout << endl;
	}
	return 0;
}