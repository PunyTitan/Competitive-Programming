#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	vector<int> alphabet(26);
	string current_str;
	int maxIndex;
	int maximum = 0;


	cin>>n;
	while(n--!=0)
	{
		cin>>current_str;
		fill(alphabet.begin(), alphabet.end(), 0);
		maximum = 0;
		for(int i=0; i<current_str.length(); ++i)
		{
			++alphabet[current_str[i]-'a'];
		}

		for(int i=0; i<26; ++i)
			if(alphabet[i]>maximum)
			{
				maxIndex = i;
				maximum = alphabet[i];
			}

		cout<<(char)('a'+maxIndex)<<" "<<alphabet[maxIndex]<<endl;
	}
	return 0;
}