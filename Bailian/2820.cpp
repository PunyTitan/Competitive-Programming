#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> alphabet1(26);
	vector<int> alphabet2(26);
	string str1, str2;

	cin>>str1>>str2;

	if(str1.length() != str2.length())
	{
		cout<<"NO"<<endl;
		return 0;
	}

	for(int i=0; i<str1.length(); ++i)
		++alphabet1[str1[i]-'A'];
	for(int i=0; i<str2.length(); ++i)
		++alphabet2[str2[i]-'A'];

	sort(alphabet1.begin(), alphabet1.end());
	sort(alphabet2.begin(), alphabet2.end());

	for(int i=0; i<26; ++i)
		if(alphabet1[i] != alphabet2[i])
		{
			cout<<"NO"<<endl;
			return 0;
		}

	cout<<"YES"<<endl;

	return 0;
}