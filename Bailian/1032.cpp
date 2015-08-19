#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> result;
	int currentSum = 0;
	int N;
	int leftover;
	cin>>N;

	for(int i=2; ; ++i)
	{
		currentSum += i;
		if(currentSum == N)
		{
			result.push_back(i);
			break;
		}
			
		if(currentSum > N)
		{
			leftover = N-(currentSum-i);
			if(leftover/result.size() == 1)
			{
				for(vector<int>::iterator itr=result.begin(); itr!=result.end(); ++itr)
					*itr += 1;
				leftover -= result.size();
			}
			for(vector<int>::iterator itr=--result.end(); leftover!=0; --leftover)
			{
				++(*itr);
				--itr;
			}
			break;	
		}

		result.push_back(i);
	}

	for(vector<int>::const_iterator itr=result.begin(); itr!=result.end(); ++itr)
		cout<<*itr<<" ";

	return 0;
}