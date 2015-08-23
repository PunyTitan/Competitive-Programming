#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	vector< vector<int> > square;
	int n;
	int x1, y1, x2, y2, x3, y3, hitX, hitY;
	bool flag = false;

	cin>>n;
	square.resize(n);
	for(int i=0; i<n; ++i)
		square[i].resize(n);

	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			cin>>square[i][j];


	//hit the upper bound of the matrix
	for(int i=0; i<n; ++i)
	{
		if(flag)
			break;
		for(int j=0; j<n; j+=2)
			if(square[i][j] == 0)
			{
				x2 = x1 = hitX = i;
				hitY = j;
				flag = true;
				break;
			}
	}

	if(!flag)
	{
		cout<<0<<endl;
		return 0;
	}

	//find the left-upper point of the matrix
	for(int i=hitY; i>=0; --i)
	{
		if(square[x1][i] == 255)
		{
			y1 = i+1;
			break;
		}

		if(i == 0)
			y1 = i;
	}

	if(x1 == n-1 || y1 == n-1)
	{
		cout<<0<<endl;
		return 0;
	}

	//find the right-upper point of the matrix
	for(int i=hitY; i<n; ++i)
	{
		if(square[x2][i] == 255)
		{
			y3 = y2 = i-1;
			break;
		}

		if(i == n-1)
			y3 = y2 = i;
	}

	//find the right-lower point of the matrix
	for(int i=x2; i<n; ++i)
	{
		if(square[i][y3] == 255)
		{
			x3 = i-1;
			break;
		}

		if(i == n-1)
			x3 = i;
	}

	if(y3 == y1 || x3 == x1)
		cout<<0<<endl;
	else
		cout<<(y3-y1-1)*(x3-x1-1)<<endl;
	
	return 0;
}