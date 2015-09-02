#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int number;
	int count;
	while(cin>>number)
	{	count = 0;

		if(number%3 == 0)
		{
			cout<<3<<" ";
			++count;
		}
		if(number%5 == 0)
		{
			cout<<5<<" ";
			++count;
		}
		if(number%7 == 0)
		{
			cout<<7<<" ";
			++count;
		}

		if(count == 0)
			cout<<"n";

		cout<<endl;

	}
	return 0;
}