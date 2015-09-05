#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > dp;

int min3(int x1, int x2, int x3)
{
	int minimum = x1;
	if(x2<minimum)
		minimum = x2;
	if(x3<minimum)
		minimum = x3;

	return minimum;
}

int main(int argc, char const *argv[])
{
	string str1, str2;
	int n;

	dp.resize(1001);
	for(int i=0; i<1001; ++i)
		dp[i].resize(1001);

	for(int i=0; i<1001; ++i)
	{
		dp[0][i] = i;
		dp[i][0] = i;
	}


	cin>>n;

	while(n--!=0)
	{
		cin>>str1>>str2;

		for(int i=1; i<=str2.length(); ++i)
		{
			for(int j=1; j<=str1.length(); ++j)
			{
				if(str1[j-1] == str2[i-1])
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = min3(1+dp[i-1][j-1], 1+dp[i-1][j], 1+dp[i][j-1]);
			}
		}

		cout<<dp[str2.length()][str1.length()]<<endl;

	}

	return 0;
}
