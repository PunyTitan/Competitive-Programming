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
	vector<int> cashV;
	vector<int> nkV;
	vector<int> dkV;
	int n, nk, dk;

	cin>>cash;

	while(true)
	{
		cashV.resize(cash+1);
		cin>>n;

		if(n == 0 || cash == 0)
		{
			cout<<0<<endl;
			cin.clear();
            fflush(stdin);
		}
		else
		{
			while(n-- != 0)
			{
				cin>>nk>>dk;
				nkV.push_back(nk);
				dkV.push_back(dk);
			}

			for(int i=0; i<nkV.size(); ++i)
			{
				Multiple(dkV[i], nkV[i], cashV);
			}

			cout<<cashV[cash]<<endl;
		}



		nkV.clear();
		dkV.clear();
		cashV.clear();
		cin>>cash;
	}


	return 0;
}
