//(b-a)(c-a) = a*a + 1

#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
	unsigned a, aSquarePlusOne, minFacSum, currentSum;
	cin>>a;
	aSquarePlusOne = a*a + 1;

	minFacSum = 3600000003;
	for(int i=1; i<=sqrt(1.0*aSquarePlusOne); ++i)
	{
		if(aSquarePlusOne%i == 0)
		{
			currentSum = i + aSquarePlusOne/i;
			if(currentSum<minFacSum)
				minFacSum = currentSum;
		}
	}

	cout<<minFacSum + 2*a<<endl;

	return 0;
}