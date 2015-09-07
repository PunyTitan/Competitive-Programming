#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int sum;
	int number;

	for(int i=100; i<=999; ++i)
	{
		sum = 0;
		number = i;
		while(number!=0)
		{
			sum += (int)pow(number%10, 3);
			number /= 10;
		}
		if(sum == i)
			cout<<i<<endl;
	}
	return 0;
}