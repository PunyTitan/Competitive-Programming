#include <iostream>
#include <math.h>

using namespace std;

bool convert(int number, int num_system, double & result)
{
	int digit = 0;
	result = 0;

	while(number != 0)
	{
		if(number%10 >= num_system)
			return false;

		result += (number%10) * pow(num_system, digit);
		++digit;
		number /= 10;
	}

	return true;
}

int main(int argc, char const *argv[])
{
	int T, p, q, r;
	bool find;
	double result;
	double pp, qq, rr;

	cin>>T;

	while(T--!=0)
	{
		find = false;
		cin>>p>>q>>r;

		for(int i=2; i<=16; ++i)
		{

			if(convert(p,i,pp) && convert(q,i,qq) && convert(r,i,rr))
			{
				if(pp*qq == rr)
				{
					cout<<i<<endl;
					find = true;
					break;
				}				
			}
		}

		if(!find)
			cout<<0<<endl;

	}

	return 0;
}
