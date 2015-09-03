#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string str1, str2;
	int count;

	while(cin>>str1>>str2)
	{
		count = 0;
		for(int i=0; i<str2.length(); ++i)
		{
			if(str1[count] == str2[i])
				++count;
			if(count == str1.length())
				break;
		}

		if(count == str1.length())
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}