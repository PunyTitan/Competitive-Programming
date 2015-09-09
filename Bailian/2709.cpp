#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;


int main(int argc, char const *argv[])
{
	double fact = 1;
	double result = 2;
	int n;
	cin>>n;

	for(int i=2; i<=n; ++i)
	{
		fact *= 1;
		result += 1.0/fact;
	}

	printf("%.10lf\n", result);
	return 0;
}