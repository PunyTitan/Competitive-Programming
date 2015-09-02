#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

const int MAX_LENGTH = 50;

//add two numbers' decimal digits
vector<int> addVec(vector<int> data1, vector<int> data2)
{
	int extra = 0;
	int digitSum;
	vector<int> result(MAX_LENGTH);

	for(int i=MAX_LENGTH-1; i>=0; --i)
	{
		digitSum = data1[i]+data2[i]+extra;
		result[i] = digitSum%10;
		extra = digitSum/10;
	}

	return result;
}

//convert a double variable to vector<int> to keep high precision
vector<int> doubleToVec(double number)
{
	vector<int> result(MAX_LENGTH);

	for(int i=0; i<MAX_LENGTH; ++i)
	{
		result[i] = (int)(number*10);
		number = number*10 - result[i];
	}

	return result;
}


int main(int argc, char const *argv[])
{
	string oct;
	int digit;
	vector<int> dec(MAX_LENGTH);

	while(cin>>oct)
	{
		digit = 1;
		dec.resize(MAX_LENGTH);
		fill(dec.begin(), dec.end(), 0);
		
		for(int i=2; i<oct.length(); ++i)
		{
			//this statement can be more efficient by using reference in addVec
			dec = addVec(dec, doubleToVec(pow(1.0/8, digit)*(oct[i]-'0')));
			++digit;
		}

		for(int i=dec.size()-1; i>=0; --i)
		{
			if(dec[i] != 0)
				break;
			dec.pop_back();
		}


		cout<<oct<<" [8] = 0.";
		if(dec.size()==0)
			cout<<0;
		else
		{
			for(int i=0; i<dec.size(); ++i)
				cout<<dec[i];
		}		
		cout<<" [10]"<<endl;
	}	
	return 0;
}
