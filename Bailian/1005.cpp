#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
	int count, year, i = 0;
	double x,y,area;
	double PI = 3.14159265358979;

	cin>>count;
	while(i++ != count)
	{
		cin>>x>>y;
		area = PI * (x*x + y*y);
		year = ceil(0.5*area/50.0);
		printf("Property %d: This property will begin eroding in year %d.\n", i, (int)year);
	}
	cout<<"END OF OUTPUT.";

	return 0;
}
