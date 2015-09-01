#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int dec;
	vector<int> result;

	cin>>dec;

	while(dec>=8)
	{
		result.push_back(dec%8);
		dec /= 8;
	}

	result.push_back(dec);

	for(int i=result.size()-1; i>=0; --i)
		cout<<result[i];

	return 0;
}