#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> phoneNums;

string phoneConvert(string phone)
{
	int count = 0;
	string result;
	for (int i = 0; i<phone.length(); ++i)
	{
		if (phone[i] != '-')
			++count;
		if (phone[i] >= 'A' && phone[i] <= 'Z')
		{
			switch (phone[i])
			{
			case 'A':
			case 'B':
			case 'C':
				phone[i] = '2';
				break;
			case 'D':
			case 'E':
			case 'F':
				phone[i] = '3';
				break;
			case 'G':
			case 'H':
			case 'I':
				phone[i] = '4';
				break;
			case 'J':
			case 'K':
			case 'L':
				phone[i] = '5';
				break;
			case 'M':
			case 'N':
			case 'O':
				phone[i] = '6';
				break;
			case 'P':
			case 'R':
			case 'S':
				phone[i] = '7';
				break;
			case 'T':
			case 'U':
			case 'V':
				phone[i] = '8';
				break;
			case 'W':
			case 'X':
			case 'Y':
				phone[i] = '9';
				break;
			}
		}
	}

	result.resize(count + 1);
	count = 0;

	result[3] = '-';
	for (int i = 0; i<phone.length(); ++i)
	{
		if (phone[i] != '-')
		{
			if (count == 3)
				++count;
			result[count++] = phone[i];
		}
	}

	return result;
}

int main(int argc, char const *argv[])
{
	int n;
	string current_phoneNum;
	map<string, int>::iterator update_itr;

	cin >> n;

	while (n-- != 0)
	{
		cin >> current_phoneNum;
		current_phoneNum = phoneConvert(current_phoneNum);

		update_itr = phoneNums.find(current_phoneNum);
		if (update_itr == phoneNums.end())
			phoneNums[current_phoneNum] = 1;
		else
			++(update_itr->second);
	}

	bool noduplicates = true;
	for (map<string, int>::const_iterator itr = phoneNums.begin(); itr != phoneNums.end(); ++itr)
	{
		if (itr->second > 1)
		{
			cout << itr->first << " " << itr->second << endl;
			noduplicates = false;
		}
			
	}

	if (noduplicates)
		cout << "No duplicates." << endl;
	return 0;
}