#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;

string intToStr(int number)
{
	char temp[3];

	if (number>=0 && number<=9)
	{
		temp[0] = '0';
		temp[1] = '0'+number;
	}
	else
	{
		temp[0] = '0'+number/10;
		temp[1] = '0'+number%10;
	}
	temp[2] = '\0';

	return string(temp);
}

int main(int argc, char const *argv[])
{
	int N;
	string current_time, timezone1, timezone2, ampm;
	map<string, double> zones;
	int hour, minute;
	double temphour;

	zones["UTC"] = 0;
	zones["GMT"] = 0;
	zones["BST"] = 1;
	zones["IST"] = 1;
	zones["WET"] = 0;
	zones["WEST"] = 1;
	zones["CET"] = 1;
	zones["CEST"] = 2;
	zones["EET"] = 2;
	zones["EEST"] = 3;
	zones["MSK"] = 3;
	zones["MSD"] = 4;
	zones["AST"] = -4;
	zones["ADT"] = -3;
	zones["NST"] = -3.5;
	zones["NDT"] = -2.5;
	zones["EST"] = -5;
	zones["EDT"] = -4;
	zones["CST"] = -6;
	zones["CDT"] = -5;
	zones["MST"] = -7;
	zones["MDT"] = -6;
	zones["PST"] = -8;
	zones["PDT"] = -7;
	zones["HST"] = -10;
	zones["AKST"] = -9;
	zones["AKDT"] = -8;
	zones["AEST"] = 10;
	zones["AEDT"] = 11;
	zones["ACST"] = 9.5;
	zones["ACDT"] = 10.5;
	zones["AWST"] = 8;

	cin>>N;
	while(N--!=0)
	{
		cin>>current_time;
		if(current_time=="noon" || current_time=="midnight")
		{
			if(current_time=="noon")
				ampm = "p.m.";
			else
				ampm = "a.m.";
			current_time = "00:00";
		}
		else
			cin>>ampm;

		cin>>timezone1>>timezone2;

		hour = atoi( current_time.substr(0, current_time.find(':')).c_str() );
		minute = atoi( current_time.substr(current_time.find(':')+1, 2).c_str() );

		if(ampm == "p.m.")
		{
			if(hour!=12)
				hour += 12;
		}
		else if(hour == 12)
			hour = 0;

		temphour = hour + zones[timezone2] - zones[timezone1] + 24;

		hour = (int)temphour;
		if( temphour-hour == 0.5)
		{
			minute += 30;
			if(minute>=60)
			{
				++hour;
				minute -= 60;
			}
		}

		hour %= 24;

		if(hour == 12 && minute == 0)
			cout<<"noon"<<endl;
		else if(hour == 0 && minute == 0)
			cout<<"midnight"<<endl;
		else
		{
			if(hour == 0)
				cout<<12<<":"<<intToStr(minute)<<" a.m."<<endl;
			else if(hour == 12)
				cout<<12<<":"<<intToStr(minute)<<" p.m."<<endl;
			else if(hour<12)
				cout<<hour<<":"<<intToStr(minute)<<" a.m."<<endl;
			else
				cout<<hour-12<<":"<<intToStr(minute)<<" p.m."<<endl;
		}
	}
	return 0;
}
