#include <iostream>
#include <vector>

using namespace std;

int monthMap[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

int main(int argc, char const *argv[])
{
	int w;
	int result;
	cin>>w;

	for(int i=0; i<12; ++i)
	{
		result = (monthMap[i] + 12 + w)%7;
		if(result == 5)
			cout<<i+1<<endl;
	}
	return 0;
}