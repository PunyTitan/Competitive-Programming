#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int cash;


void ZeroOne(int cost, vector<int> & cashV)
{
	for(int i=cash; i>=cost; --i)
		cashV[i] = cashV[i]<cashV[i-cost]+cost ? cashV[i-cost]+cost : cashV[i];
}

void Complete(int cost, vector<int> & cashV)
{
	for(int i=cost; i<=cash; ++i)
		cashV[i] = cashV[i]<cashV[i-cost]+cost ? cashV[i-cost]+cost : cashV[i];
}

void Multiple(int cost, int count, vector<int> & cashV)
{
	if(cost*count >= cash)
		Complete(cost, cashV);
	else
	{
		int k=1;
		while(k<=count)
		{
			count -= k;
			ZeroOne(k*cost, cashV);
			k *= 2;
		}

		if(count>0)
			ZeroOne(count*cost, cashV);
	}
}

int main(int argc, char const *argv[])
{
	vector<int> cashV(100001);
	vector<int> nkV(11);
	vector<int> dkV(11);
	int n, nk, dk;

	cin>>cash;

	while(true)
	{
		cin>>n;		

		fill(cashV.begin(), cashV.end(), 0);

		for(int i=0; i<n; ++i)
		{
			cin>>nk>>dk;
			nkV[i] = nk;
			dkV[i] = dk;
		}
		
		for(int i=0; i<n; ++i)
		{
			Multiple(dkV[i], nkV[i], cashV);
		}

		cout<<cashV[cash]<<endl;
		
		cin>>cash;
		
	}


	return 0;
}
