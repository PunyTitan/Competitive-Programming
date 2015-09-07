#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	int temp;
	int *data;

	cin>>n>>m;
	data = new int[n];

	for(int i=0; i<n; ++i)
		cin>>data[i];

	for(int i=0; i<m; ++i)
	{
		temp = data[n-1];
		for(int j=0; j<n-1; ++j)
		{
			data[n-1-j] = data[n-2-j];
		}
		data[0] = temp;
	}

	for(int i=0; i<n; ++i)
		cout<<data[i]<<" ";
	return 0;
}