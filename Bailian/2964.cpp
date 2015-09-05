#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int monthMap[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
int monthMapRun[12] = { 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };


bool runnian(int year)
{
	if (year % 100 == 0)
	{
		if (year % 400 == 0)
			return true;
		return false;
	}
	else
	{
		if (year % 4 == 0)
			return true;
		return false;
	}
}

string weekTrans(int i)
{
	switch (i)
	{
	case 1:
		return "Monday";
	case 2:
		return "Tuesday";
	case 3:
		return "Wednesday ";
	case 4:
		return "Thursday";
	case 5:
		return "Friday";
	case 6:
		return "Saturday";
	case 0:
		return "Sunday";

	}
}

string numberTrans(int i)
{
	char temp[3];

	if (i >= 1 && i <= 9)
	{
		temp[0] = '0';
		temp[1] = '0' + i;
	}
	else
	{
		temp[0] = '0' + i / 10;
		temp[1] = '0' + i % 10;
	}

	temp[2] = '\0';

	return string(temp);
}

int main(int argc, char const *argv[])
{
	int dayPass;
	int yearOffset, monthOffset, dayOffset, weekday;
	int i, temp;

	while (cin >> dayPass)
	{
		if (dayPass == -1)
			break;

		weekday = (dayPass + 6) % 7;

		yearOffset = monthOffset = dayOffset = 0;

		for (i = 0; dayPass >= 0; ++i)
		{
			temp = dayPass;
			if (runnian(2000 + i))
				dayPass -= 366;
			else
				dayPass -= 365;
		}
		yearOffset = i - 1;
		dayPass = temp;

		if (dayPass != 0)
		{

			for (i = 0; dayPass >= 0; ++i)
			{
				if (runnian(2000 + yearOffset))
				{
					if (dayPass<monthMapRun[i])
					{
						monthOffset = i;
						if (i != 0)
							dayPass -= monthMapRun[i - 1];
						break;
					}
				}
				else
				{
					if (dayPass<monthMap[i])
					{
						monthOffset = i;
						if (i != 0)
							dayPass -= monthMap[i - 1];
						break;
					}
				}
			}

			dayOffset = dayPass;
		}

		cout << 2000 + yearOffset << "-" << numberTrans(1 + monthOffset) << "-" << numberTrans(1 + dayOffset) << " " << weekTrans(weekday) << endl;

	}

	return 0;
}