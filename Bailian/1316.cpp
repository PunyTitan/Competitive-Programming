#include <iostream>
#include <vector>

#define MAXIMUM 10001

using namespace std;

int generate(int generator)
{
	int result = generator;
	while(generator != 0)
	{
		result += generator%10;
		generator /= 10;
	}

	return result;
}

int main(int argc, char const *argv[])
{
	vector<bool> hasGenerator(MAXIMUM);

	for(int i=1; i<MAXIMUM; ++i)
	{
		int generatedNum = generate(i);
		while(generatedNum < MAXIMUM)
		{
			if(hasGenerator[generatedNum])
				break;
			hasGenerator[generatedNum] = true;
			generatedNum = generate(generatedNum);
		}
	}

	for(int i=1; i<MAXIMUM; ++i)
		if(!hasGenerator[i])
			cout<<i<<endl;
	return 0;
}