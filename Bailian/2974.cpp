#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char map[] = "22233344455566677778889999";
string current_phoneNum;
vector<string> phoneNums;

void phoneConvert(int index)
{
	int count = 0;
	string result = "        ";

	for (int i = 0; i<current_phoneNum.length(); ++i)
	{
		if (current_phoneNum[i] == '-')
			continue;

		if (count == 3)
		{
			result[count++] = '-';
		}

		if (current_phoneNum[i] >= 'A' && current_phoneNum[i] <= 'Z')
		{
			result[count++] = map[current_phoneNum[i]-'A'];
		}
		else
			result[count++] = current_phoneNum[i];		
		
	}

	phoneNums[index] = result;
}

int main(int argc, char const *argv[])
{
	int n;
	int count;
	string previous_str;
	bool duplicates = false;

	cin >> n;
	phoneNums.resize(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> current_phoneNum;
		phoneConvert(i);
	}

	sort(phoneNums.begin(), phoneNums.end());

	count = 0;
	previous_str = phoneNums[0];

	for (int i = 0; i<phoneNums.size(); ++i)
	{
		if (phoneNums[i] == previous_str)
			++count;
		else
		{
			if (count > 1)
			{
				cout << previous_str << " " << count << endl;
				duplicates = true;
			}

			previous_str = phoneNums[i];
			count = 1;
		}
	}
	if (count>1)
	{
		cout << previous_str << " " << count << endl;
		duplicates = true;
	}

	if (!duplicates)
		cout << "No duplicates." << endl;

	return 0;
}