#include <iostream>
#include <math.h>

using namespace std;

//32000 can be tested by another program.
#define MAXIMUM 32000
unsigned int numOfBitsInSeq[MAXIMUM];
unsigned int globalPosition[MAXIMUM];


//calculate how many digits we need in each sequences(numOfBitsInSeq), and in total(globalPosition).
void init()
{
	numOfBitsInSeq[1] = 1;
	globalPosition[1] = 1;

	for(int i=2; i<MAXIMUM && globalPosition[i-1]<2147483647; ++i)
	{
		numOfBitsInSeq[i] = numOfBitsInSeq[i-1] + (unsigned int)log10((double)i) + 1;
		globalPosition[i] = globalPosition[i-1] + numOfBitsInSeq[i];
	}
}

unsigned int getDigit(unsigned int x)
{
	unsigned int currentPosition = 0;
	int i, leftDigit, currenNumBits;

	if(x == 1)
		return 1;

	//Reduce the range to a sequence. e.g. 1 2 3 4 5 6 7 8 .... k
	for(i = 1; i<MAXIMUM && globalPosition[i]<x; ++i);

	currentPosition = globalPosition[i-1];
	
	//Reduce to a certain number. e.g. k
	for(i = 1; i<MAXIMUM && currentPosition<x; ++i)
	{
		currentPosition += (unsigned int)log10((double)i) + 1;
	}

	currenNumBits = (unsigned int)log10((double)(i-1)) + 1;
	currentPosition -= currenNumBits;
	leftDigit = x-currentPosition;

	return (i-1)/(unsigned int)pow(10.0, (double)(currenNumBits-leftDigit)) % 10;
	

}

int main(int argc, char const *argv[])
{
	int t;
	unsigned int x;

	init();

	cin>>t;
	while(t-- != 0)
	{
		cin>>x;
		cout<<getDigit(x)<<endl;
	}	
	return 0;
}