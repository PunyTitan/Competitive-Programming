#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int number)
{
	if (number == 1)
		return false;
	if (number == 2)
		return true;

	for (int i = 2; i <= sqrt((double)number); ++i)
	{
		if (number%i == 0)
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int X, Y;
	int temp;
	int count = 0;

	cin >> X >> Y;

	if (X > Y)
	{
		temp = Y;
		Y = X;
		X = temp;
	}

	for (int i = X; i <= Y; ++i)
	{
		
		if (isPrime(i))
			++count;
	}
	cout << count;
	return 0;
}