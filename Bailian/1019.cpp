#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

//how many digits from 1~9, 10~99, 100~999, 1000~9999
long long data_one = 9;
long long data_ten = data_one + 2 * 90;
long long data_hundred = data_ten + 3 * 900;
long long data_thousand = data_hundred + 4 * 9000;

//how many digits from 1~9, 1~99, 1~999, 1~9999
long long one = 45;
long long ten = one + data_one * 90 + 2 * (1 + 90) * 90 / 2;
long long hundred = ten + data_ten * 900 + 3 * (1 + 900) * 900 / 2;
long long thousand = hundred + data_hundred * 9000 + 4 * (1 + 9000) * 9000 / 2;
//long long tenthousand = 2147483647;
std::vector<long long int> mapBitToDigitNum;



//find solution for f(x) = ax^2 + bx + c
double xSquareSol(double a, double b, double c)
{
	return (-1 * b + sqrt(b*b - 4 * a*c)) / (2 * a);
}


//find digit at index when the sequence is 1234567891011....
long long findPos(long long index)
{
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

//reduce the range of the index into a single sequence such as s_k
long long findIndex(long long x, int bits)
{
	long long left, right;
	if (x == 1)
		return 1;
	else
	{
		right = (long long)ceil(xSquareSol(0.5*bits, mapBitToDigitNum[bits]+bits*0.5, -1*x));
		left = right - 1;
		if (right != 1)
		{
			x -= mapBitToDigitNum[bits]*(left)+bits * ((left)*(left)+left) / 2;
		}
		return findPos(x);
	}
}

int main(int argc, char const *argv[])
{

	int n;
	long long x;

	mapBitToDigitNum.push_back(0);
	mapBitToDigitNum.push_back(0);
	mapBitToDigitNum.push_back(data_one);
	mapBitToDigitNum.push_back(data_ten);
	mapBitToDigitNum.push_back(data_hundred);
	mapBitToDigitNum.push_back(data_thousand);

	cin>>n;
	while(n-- != 0)
	{
		cin>>x;
		if(x<=one)
			cout<<findIndex(x, 1)<<endl;
		else if(x<=ten)
			cout<<findIndex(x-one, 2)<<endl;
		else if(x<=hundred)
			cout<<findIndex(x-ten, 3)<<endl;
		else if(x<=thousand)
			cout<<findIndex(x-hundred, 4)<<endl;
		else
			cout<<findIndex(x-thousand, 5)<<endl;
	}
	

	return 0;
}