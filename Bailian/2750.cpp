#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, a, maximum, minimum;
	cin>>n;

	while(n--!=0)
	{
		cin>>a;
		if(a%2 != 0 || a<0)
		{
			cout<<0<<" "<<0<<endl;
			continue;
		}
		maximum = a/2;
		minimum = a/4 + (a-a/4*4)/2;

		cout<<minimum<<" "<<maximum<<endl;
	}
	return 0;
}