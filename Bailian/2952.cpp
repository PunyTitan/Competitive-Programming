#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

set<string> cyclics;

string intToStr(int n)
{
	char number[3];
	if(n>=10)
	{
		number[0] = n/10 + '0';
		number[1] = n%10 + '0';
		number[2] = '\0';
	}
	else
	{
		number[0] = n + '0';
		number[1] = '\0';
	}

	return string(number);
}

void strTimes(string & str, int n, string & result)
{
	int next = 0;
	int result_index;
	int n_index;
	int count;
	int temp;

	result.resize(str.size()+2);
	fill(result.begin(), result.end(), '0');    //do not forget to initialize this!!
	string nStr = intToStr(n);

	//times two large ints
	count = 0;
	for(n_index = nStr.size()-1; n_index>=0; --n_index, ++count)
	{
		result_index = result.size()-1-count;

		for(int str_index=str.size()-1; str_index>=0; --str_index, --result_index)
		{
			temp = (str[str_index]-'0')*(nStr[n_index]-'0') + next + (result[result_index]-'0');
			if(temp>=10)
			{
				next = temp/10;
				result[result_index] = temp%10 + '0';
			}
			else
			{
				next = 0;
				result[result_index] = temp + '0';
			}
		}
		while(next != 0)
		{
			temp = result[result_index]-'0' + next;
			if(temp>=10)
			{
				next = temp/10;
				result[result_index] = temp%10 + '0';
			}
			else
			{
				next = 0;
				result[result_index] = temp + '0';
			}
			--result_index;
		}

	}

	if(result[0] == '0' && result[1] == '0')
		result = result.substr(2, result.size()-2);
	else if(result[0] == '0')
		result = result.substr(1, result.size()-1);
}

int main(int argc, char const *argv[])
{

	string number;
	cin>>number;

	for(int i=0; i<number.size(); ++i)
	{
		cyclics.insert(number.substr(i, number.size()-i) + number.substr(0, i));
	}

	bool isCyclic = true;
	string result;
	for(int i=2; i<=number.size(); ++i)
	{
		strTimes(number, i, result);
		if(cyclics.find(result) == cyclics.end())
		{
			isCyclic = false;
			break;
		}

	}

	if(isCyclic)
		cout<<1;
	else
		cout<<0;


	return 0;
}
