#include <iostream>
#include <vector>
#include <string>

using namespace std;

int maxlength = 0;

bool containSubstr(string sub, string str)
{
	int subStr_length = sub.length();
	bool contain = false;

	//this (int) is very important, otherwise, unsigned int will overflow
	for(int i=0; i<(int)str.length()-subStr_length+1; ++i)
	{
		if(contain)
			break;
		for(int j=0; j<subStr_length; ++j)
		{
			if(sub[j] != str[i+j])
				break;
			if(j == subStr_length-1)
				contain = true;						
		}
	}

	return contain;
}

string reverseStr(string str)
{
	string result;
	result.resize(str.length());
	int count = 0;

	for(int i=str.length()-1; i>=0; --i)
		result[count++] = str[i];

	return result;
}


int main(int argc, char const *argv[])
{
	vector<string> strs;
	int t, n;
	int minlength;
	string minlength_str;
	string current_subStr;
	int count;

	cin>>t;

	while(t--!=0)
	{
		cin>>n;
		strs.resize(n);
		minlength = 101;

		for(int i=0; i<n; ++i)
		{
			cin>>strs[i];
			if(strs[i].length()<minlength)
			{
				minlength = (int)strs[i].length();
				minlength_str = strs[i];
			}
		}

		cout<<"minlength_str: "<<minlength_str<<endl;
		cout<<"minlength: "<<minlength<<endl;

		//The beginning position of current search sub string 
		for(int i=0; i<minlength; ++i)
		{
			cout<<"current search position: "<<i<<endl;	
			//The length of current search sub string
			for(int j=maxlength+1; j+i<=minlength; ++j)
			{	
				cout<<"current search length: "<<j<<endl;
				current_subStr = minlength_str.substr(i, j);
				cout<<"current sub string: "<<current_subStr<<endl;
				count = 0;
				for(int row = 0; row<n; ++n)
				{	
					cout<<"inner search: "<<strs[row]<<endl;
					if(containSubstr(current_subStr, strs[row]) || containSubstr(reverseStr(current_subStr), strs[row]))
						++count;
				}

				cout<<"current count: "<<count<<endl;
				if(count == n)
					maxlength = j;
				else
					break;
				cout<<"current maxlength: "<<maxlength<<endl;			
			}
		}

		cout<<maxlength<<endl;
	}

	return 0;
}