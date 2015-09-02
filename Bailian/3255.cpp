#include <iostream>
#include <vector>

using namespace std;

vector<int> decToSix(int number)
{
	vector<int> result;

	while(number != 0)
	{
		result.push_back(number%6);
		number /= 6;
	}

	return result;
}

int main(int argc, char const *argv[])
{
	int n;
	int dec;
	vector<int> six;
	cin>>n;

	while(n--!=0)
	{
		cin>>dec;
		six = decToSix(dec);

		for(int i=six.size()-1; i>=0; --i)
			cout<<six[i];
		cout<<endl;
	}
	return 0;
}