#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
	bool trees[10001];
	int leftBound[101];
	int rightBound[101];
	int L, M;
	int count = 0;

	cin>>L>>M;

	memset(trees, true, sizeof(trees));

	for(int i=0; i<M; ++i)	
		cin>>leftBound[i]>>rightBound[i];

	for(int i=0; i<M; ++i)
	{
		for(int j=leftBound[i]; j!=rightBound[i]+1; ++j)
			trees[j]=false;
	}

	for(int i=0; i<=L; ++i)
		if(trees[i])
			++count;

	cout<<count<<endl;

	return 0;
}
