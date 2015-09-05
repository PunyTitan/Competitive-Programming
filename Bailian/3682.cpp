#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> odd;
	vector<int> even;
	vector<int> data(10);
	int current_int;
	int num = 10;

	while(cin>>data[0]>>data[1]>>data[2]>>data[3]>>data[4]>>data[5]>>data[6]>>data[7]>>data[8]>>data[9])
	{
		even.clear();
		odd.clear();
		
		for(int i=0; i<10; ++i)
		{
			if(data[i]%2 == 0)
				even.push_back(data[i]);
			else
				odd.push_back(data[i]);
		}		

		sort(odd.begin(), odd.end(), greater<int>());
		sort(even.begin(), even.end());

		if (!odd.empty())
		{
			for (int i = 0; i<odd.size(); ++i)
				cout << odd[i] << " ";
		}

		if (!even.empty())
		{
			for (int i = 0; i<even.size(); ++i)
				cout << even[i] << " ";
		}

	}
	

	
	return 0;
}