#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int hour, minute, sec, day, month, year;
int monthMap[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
int monthMapRun[13] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};

bool runnian(int year)
{
	if(year%100 == 0)
	{
		if(year%400 == 0)
			return true;
		else
			return false;
	}
	else
	{
		if(year%4 == 0)
			return true;
		else
			return false;
	}
}

int main(int argc, char const *argv[])
{
	int mhour, mminute, msec, mday, mmonth, myear;
	int N;
	int totalDay;
	int totalSec;

	cin>>N;
	while(N--!=0)
	{
		totalSec = totalDay = 0;
		scanf("%d:%d:%d %d.%d.%d",&hour,&minute,&sec,&day,&month,&year);

		if(year>2000)
			totalDay += (year-2000)*365 + ((year-2000-1)/4 + 1) - ((year-2000-1)/100 + 1) + ((year-2000-1)/400 + 1);

		if(runnian(year))
			totalDay += monthMapRun[month-1];
		else
			totalDay += monthMap[month-1];

		totalDay += day-1;

		myear = totalDay/1000;
		mmonth = (totalDay-myear*1000)/100 + 1;
		mday = totalDay - myear*1000 - (mmonth-1)*100 + 1;

		totalSec += hour*3600 + minute*60 + sec;
		totalSec = (int)((double)totalSec * 125 / 108);

		mhour = totalSec/10000;
		mminute = (totalSec - mhour*10000)/100;
		msec = totalSec - mhour*10000 - mminute*100;

		cout<<mhour<<":"<<mminute<<":"<<msec<<" "<<mday<<"."<<mmonth<<"."<<myear<<endl;
	}

	return 0;
}
