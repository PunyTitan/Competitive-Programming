#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int count;
	int N;
	int number;
	int remaind;

	cin>>N;
	while(N--!=0)
	{
		count = 0;
		cin>>number;
		while(number!=0)
		{
			remaind = number%2;
			if(remaind == 1)
				++count;

			number /= 2;
		}

		cout<<count<<endl;
	}
	return 0;
}