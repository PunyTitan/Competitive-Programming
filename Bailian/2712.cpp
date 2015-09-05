#include <iostream>
#include <math.h>

using namespace std;

int days[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

int main(int argc, char const *argv[])
{
	int n;
	int month1, month2, day1, day2;
	long long number;
	int numOfDay;

	cin>>n;
	while(n--!=0)
	{
		cin>>month1>>day1>>number>>month2>>day2;
		numOfDay = days[month2] + day2 - (days[month1] + day1);
		cout<<(long long)(number*pow(2.0, numOfDay))<<endl;
	}


	return 0;
}
