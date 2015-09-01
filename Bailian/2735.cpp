#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int oct;
	double result = 0;
	int digit = 0;

	cin>>oct;

	while(oct != 0)
	{
		result += (oct%10) * pow(10.0, digit++);
	}

	cout<<(int)result;

	return 0;
}