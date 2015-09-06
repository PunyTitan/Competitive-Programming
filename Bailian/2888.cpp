#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	vector<int> result;

	while(getline(cin, str, '\n'))
	{
		result.clear();
		for(int i=0; i<str.length(); ++i)
		{
			if(str[i]>='0' && str[i]<='9')
				result.push_back(str[i]-'0');
		}

		sort(result.begin(), result.end());
		for(int i=0; i<result.size(); ++i)
			cout<<setw(4)<<result[i];
		cout<<endl;
	}
	return 0;
}