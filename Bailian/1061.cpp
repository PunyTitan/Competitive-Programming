#include <iostream>

using namespace std;

long long exGCD(long long a, long long b, long long *x, long long *y)
{
	if(b == 0)
	{
		*x = 1;
		*y = 0;
		return a;
	}
	long long gcd = exGCD(b, a%b, x, y);
	long long temp_x = *x;
	*x = *y;
	*y = temp_x - (a/b)* *y;
	return gcd;
}

int main(int argc, char const *argv[])
{
	int x, y, m, n, L;
	long long x1, x2;
	long long gcd;

	cin>>x>>y>>m>>n>>L;

	long long a = n-m;
	long long b = L;

	if(m == n)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
		
	gcd = exGCD(a, b, &x1, &x2);
	if((x-y)%gcd != 0)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}

	x1 *= (x-y)/gcd;
	x1 = (x1%b+b)%b;
	cout<<x1<<endl;

	return 0;
}