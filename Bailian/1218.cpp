#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, numOfCell,count;
	vector<bool> open;

	cin>>n;
	while(n-- != 0)
	{
		cin>>numOfCell;
		count = 0;
		open.resize(numOfCell+1);

		for(int i=1; i<numOfCell+1; ++i)
		{
			for(int j=i; j<numOfCell+1; j+=i)
				open[j] = open[j] ? false : true;
		}

		for(vector<bool>::const_iterator itr=open.begin(); itr!=open.end(); ++itr)
		{
			if(*itr)
				++count;
		}

		cout<<count<<endl;
		open.clear();

	}
	return 0;
}
