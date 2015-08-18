#include <iostream>
#include <math.h>

using namespace std;

long long data_one = 9;
long long data_ten = data_one + 2 * 90;
long long data_hundred = data_ten + 3 * 900;
long long data_thousand = data_hundred + 4 * 9000;
long long one = 45;
long long ten = one + data_one * 90 + 2 * (1 + 90) * 90 / 2;
long long hundred = ten + data_ten * 900 + 3 * (1 + 900) * 900 / 2;
long long thousand = hundred + data_hundred * 9000 + 4 * (1 + 9000) * 9000 / 2;
//long long tenthousand = 2147483647;

double xSquareSol(double a, double b, double c)
{
	return (-1 * b + sqrt(b*b - 4 * a*c)) / (2 * a);
}

long long findPos(long long number, long long index)
{
	long long temp;
	if (index <= data_one)
		return index;
	else if (index <= data_ten)
	{
		index -= data_one;
		if (index % 2 == 0)
		{
			return (index / 2 - 1) % 10;
		}
		else
		{
			return (long long)ceil(index / 20.0) % 10;
		}
	}
	else if (index <= data_hundred)
	{
		index -= data_ten;
		if (index % 3 == 0)
		{
			return (index / 3 - 1) % 10;
		}
		else if (index % 3 == 1)
		{
			return (long long)ceil(index / 300.0) % 10;
		}
		else
		{
			return (long long)floor(index / 30.0) % 10;
		}
	}
	else if(index <= data_thousand)
	{
		index -= data_hundred;
		if (index % 4 == 0)
		{
			return (index / 4 - 1) % 10;
		}
		else if (index % 4 == 1)
		{
			return (long long)ceil(index / 4000.0) % 10;
		}
		else if (index % 4 == 2)
		{
			return (long long)floor(index / 400.0) % 10;
		}
		else
		{
			return (long long)floor(index / 40.0) % 10;
		}
	}
	else
	{
		index -= data_thousand;
		if (index % 5 == 0)
		{
			return (index / 5 - 1) % 10;
		}
		else if (index % 5 == 1)
		{
			return (long long)ceil(index / 50000.0) % 10;
		}
		else if (index % 5 == 2)
		{
			return (long long)floor(index / 5000.0) % 10;
		}
		else if (index % 5 == 3)
		{
			return (long long)floor(index / 500.0) % 10;
		}
		else
		{
			return (long long)floor(index / 50.0) % 10;
		}
	}
}

long long findPosOne(long long x)
{
	long long left, right;
	if (x == 1)
		return 1;
	else
	{
		right = (long long)ceil(xSquareSol(0.5, 0.5, -1 * x));
		left = right - 1;
		return x - (0.5*left*left + 0.5*left);
	}

}

long long findPosTen(long long x)
{
	long long left, right;
	if (x == 1)
		return 1;
	else
	{
		right = (long long)ceil(xSquareSol(1, data_one + 1, -1 * x));
		left = right - 1;
		if (right != 1)
		{
			x -= data_one*(left)+2 * ((left)*(left)+left) / 2;
		}
		return findPos(right + 9, x);
	}
}

long long findPosHundred(long long x)
{
	long long left, right;
	if (x == 1)
		return 1;
	else
	{
		right = (long long)ceil(xSquareSol(1.5, data_ten + 1.5, -1 * x));
		left = right - 1;
		if (right != 1)
		{
			x -= data_ten*(left)+3 * ((left)*(left)+left) / 2;
		}
		return findPos(right + 99, x);
	}
}

long long findPosThousand(long long x)
{
	long long left, right;
	if (x == 1)
		return 1;
	else
	{
		right = (long long)ceil(xSquareSol(2, data_hundred + 2, -1 * x));
		left = right - 1;
		if (right != 1)
		{
			x -= data_hundred*(left)+4 * ((left)*(left)+left) / 2;
		}
		return findPos(right + 999, x);
	}
}

long long findPosTenThousand(long long x)
{
	long long left, right;
	if (x == 1)
		return 1;
	else
	{
		right = (long long)ceil(xSquareSol(2.5, data_thousand + 2.5, -1 * x));
		left = right - 1;
		if (right != 1)
		{
			x -= data_thousand*(left)+5 * ((left)*(left)+left) / 2;
		}
		return findPos(right + 9999, x);
	}
}


int main(int argc, char const *argv[])
{

	int n;
	long long x;


	cin>>n;
	while(n-- != 0)
	{
		cin>>x;
		if(x<=one)
			cout<<findPosOne(x)<<endl;
		else if(x<=ten)
			cout<<findPosTen(x-one)<<endl;
		else if(x<=hundred)
			cout<<findPosHundred(x-ten)<<endl;
		else if(x<=thousand)
			cout<<findPosThousand(x-hundred)<<endl;
		else
			cout<<findPosTenThousand(x-thousand)<<endl;
	}
	

	return 0;
}