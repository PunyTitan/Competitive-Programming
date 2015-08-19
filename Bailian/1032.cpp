#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

int getFactor(int number)
{
	if(number <= 4)
		return -1;
	if(number == 6)
		return 3;
	for(int i = 2; i<=sqrt(number); ++i)
	{
		if(number%i == 0)
			return i;
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	int N, current_factor, factor1, factor2, indicator;
	queue<int> factors;
	vector<int> results;

	cin>>N;
	factors.push(N);

	while(!factors.empty())
	{
		current_factor = factors.front();
		factors.pop();

		indicator = getFactor(current_factor);

		if(indicator == -1)
		{
			if(current_factor >= 2 && current_factor <= 4)
				results.push_back(current_factor);
			else 
			{
				if(current_factor%2 == 0)
					factor1 = factor2 = current_factor/2;
				else
				{
					factor1 = current_factor/2;
					factor2 = current_factor/2+1;
				}
				factors.push(factor1);
				factors.push(factor2);
			}
		}
		else if(indicator == 2)
		{	
			for(int i=0; i<current_factor/indicator/2; ++i)
				results.push_back(4);
			if(current_factor/indicator%2 == 1)
				results.push_back(2);
				
		}
		else
		{
			for(int i=0; i<current_factor/indicator; ++i)
				results.push_back(indicator);
		}
		
	}

	sort(results.begin(), results.end());

	for(vector<int>::const_iterator itr = results.begin(); itr!=results.end(); ++itr)
		cout<<*itr<<" ";


	return 0;
}