#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	double x;
	long long right,left;
	cin>>n;
	while(n-- != 0)
	{
		cin>>x;
		if(x == 1)
			cout<<1<<endl;
		else
		{
			right = (long long)ceil(-0.5 + sqrt(0.25 + 2*x));
			left = right-1;
			cout<<x - (0.5*left*left + 0.5*left)<<endl;
		}
	}
	return 0;
}