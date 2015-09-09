#include <iostream>
#include <string>
#include <vector>

using namespace std;

void strMinus(string & str1, string & str2)
{
	int next = 0;
	for (int i = str1.length() - 1; i >= 0; --i)
	{
		if (str1[i] + next >= str2[i])
		{
			str1[i] = '0' + str1[i] - str2[i] + next;
			next = 0;
		}
		else
		{
			next = str1[i] - str2[i] + next;
			str1[i] = 10 + next % 10 + '0';
			next = -1 + next / 10;
		}
	}
}

bool strLarger(string & str1, string & str2)
{
	if (str1.size()>str2.size())
		return true;
	return str1>str2;
}

int main(int argc, char const *argv[])
{
	string dividend, divisor;
	int n;
	vector<int> result;
	int i;
	int result_index;
	string current;


	cin >> n;
	while (n-- != 0)
	{
		cin >> dividend >> divisor;
		getchar();
		getchar();

		result.clear();

		for (i = 0; i<dividend.length(); ++i)
		{
			if (dividend[i] != '0')
				break;
		}
		if (i != 0)
			dividend = dividend.substr(i, dividend.length() - i);

		for (i = 0; i<divisor.length(); ++i)
		{
			if (divisor[i] != '0')
				break;
		}
		if (i != 0)
			divisor = divisor.substr(i, divisor.length() - i);


		if (dividend.length()<divisor.length())
		{
			cout << 0 << endl;
			continue;
		}

		result_index = divisor.length() - 1;
		current = dividend.substr(0, result_index + 1);
		while (result_index != dividend.length() - 1)
		{
			i = 0;
			while (current >= divisor)
			{
				strMinus(current, divisor);
				++i;
			}
			result.push_back(i);

			for (i = 0; i<current.length(); ++i)
			if (current[i] != '0')
				break;
			if (i != 0)
				current = current.substr(i, current.length() - i);

			while (strLarger(divisor, current))
			{
				result.push_back(0);
				if(current.empty())
					current.push_back(dividend[++result_index]);
				else
				{
					current = current.substr(1, current.length() - 1);
					current.push_back(dividend[++result_index]);
				}				
			}

		}
		i = 0;
		while (current >= divisor)
		{
			strMinus(current, divisor);
			++i;
		}
		result.push_back(i);



		for (i = 0; i<result.size(); ++i)
		{
			if (result[i] != 0)
				break;
			result[i] = -1;
		}

		bool zero = true;
		for (i = 0; i<result.size(); ++i)
		{
			if (result[i] != -1)
			{
				cout << result[i];
				zero = false;
			}
		}
		if (result.size() == 0 || zero)
			cout << 0;
		cout << endl;
	}
	return 0;
}