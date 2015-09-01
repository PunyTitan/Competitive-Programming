#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int year;
	cin>>year;

	if(year%100 == 0)
	{
		if(year%400 == 0)
			cout<<"Y";
		else
			cout<<"N";
	}
	else
	{
		if(year%4 == 0)
			cout<<"Y";
		else
			cout<<"N";
	}
	return 0;
}