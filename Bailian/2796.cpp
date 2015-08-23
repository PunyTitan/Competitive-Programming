#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int a[6];
	int sum=0;

	for(int i=0; i<6; ++i)
		cin>>a[i];

	for(int i=1; i<6; ++i)
		if(a[i]<a[0])
			sum+=a[i];

	cout<<sum<<endl;
	return 0;
}