#include <iostream>
#include <vector>
#include <string>

using namespace std;

int calculateRoot(string & str)
{
	int result = 0;
	int return_val;

	for(int i=0; i<str.length(); ++i)
		result += str[i]-'0';

	while(result>9)
	{
		return_val = 0;
		while(result!=0)
		{
			return_val += result%10;
			result /= 10;
		}
		result = return_val;
	}
	return = result;
}

int main(int argc, char const *argv[])
{
	string number;
	while(cin>>number)
	{
		if(number[0]=='0' && number.size()==1)
			break;
		cout<<calculateRoot(number)<<endl;
	}
	return 0;
}