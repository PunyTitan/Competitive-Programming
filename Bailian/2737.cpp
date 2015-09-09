#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;


//subtract two string with the same length, or str2 is 1 less size than str1
void strMinus(string & str1, string & str2)
{
	int next = 0;


	if(str2.size()<str1.size())
		str2 = string(str1.size()-str2.size(), '0') + str2;

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
			if(next%10 == 0)
				str1[i] = '0';
			else
				str1[i] = 10 + next % 10 + '0';
			next = -1;
		}
	}

	if(str2[0] == '0')
		str2 = str2.substr(1, str2.size()-1);
}

bool strLarger(string & str1, string & str2)
{
	if (str1.size()>str2.size())
		return true;
	if (str1.size()<str2.size())
		return false;
	return str1>=str2;
}

int main(int argc, char const *argv[])
{
	string dividend, divisor;
	int n;
	vector<int> result;
	int i,j;
	int result_index;
	string current;


	cin >> n;
	while (n-- != 0)
	{
		cin >> dividend >> divisor;
		getchar();
		getchar();

		result.clear();

		//delete proceeding 0s
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


		//directly output result in this condicion
		if (dividend.length()<divisor.length())
		{
			cout << 0 << endl;
			continue;
		}


		//calculate result. current is the number to be divided now
		result_index = divisor.length() - 1;
		current = dividend.substr(0, result_index + 1);
		while (result_index != dividend.length() - 1)
		{

			i = 0;
			while (strLarger(current, divisor))
			{
				strMinus(current, divisor);
				//delete proceeding 0s
				for (j = 0; j<current.length(); ++j)
				{
					if (current[j] != '0')
						break;
				}
				if (j != 0)
					current = current.substr(j, current.length() - j);
				++i;
			}
			result.push_back(i);

			//add the next char to the current number
			if(current.empty())
			{
				if(dividend[++result_index] == '0')
					continue;
				current.push_back(dividend[result_index]);
			}
			else
			{
				current.push_back(dividend[++result_index]);
			}

		}
		i = 0;
		while (strLarger(current, divisor))
		{
			strMinus(current, divisor);
			++i;
			for (j = 0; j<current.length(); ++j)
			{
				if (current[j] != '0')
					break;
			}
			if (j != 0)
				current = current.substr(j, current.length() - j);

		}
		result.push_back(i);


		//delete proceding 0s
		for (i = 0; i<result.size(); ++i)
		{
			if (result[i] != 0)
				break;
			result[i] = -1;
		}

		//output the result
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
