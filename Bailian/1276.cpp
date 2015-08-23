#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std;

int cash;
int cashV[100001];
int nkV[11];
int dkV[11];

void ZeroOne(int cost)
{
	for(int i=cash; i>=cost; --i)
		if(cashV[i]<cashV[i-cost]+cost)
			cashV[i] = cashV[i-cost]+cost;
}

void Complete(int cost)
{
	for(int i=cost; i<=cash; ++i)
		if(cashV[i]<cashV[i-cost]+cost)
			cashV[i] = cashV[i-cost]+cost;
}

void Multiple(int cost, int count)
{
	if(cost*count >= cash)
		Complete(cost);
	else
	{
		int k=1;
		while(k<=count)
		{
			count -= k;
			ZeroOne(k*cost);
			k *= 2;
		}

		if(count>0)
			ZeroOne(count*cost);
	}
}

int main(int argc, char const *argv[])
{
	int n;

	cin>>cash;

	while(true)
	{
		cin>>n;		

		memset(cashV, 0, sizeof(cashV));

		for(int i=0; i<n; ++i)
			cin>>nkV[i]>>dkV[i];
		
		for(int i=0; i<n; ++i)
		{
			Multiple(dkV[i], nkV[i]);
		}

		cout<<cashV[cash]<<endl;
		
		cin>>cash;
		
	}


	return 0;
}
