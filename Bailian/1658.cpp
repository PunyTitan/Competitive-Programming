#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int diff1, diff2, diff3;
	int t;
	int x1, x2, x3, x4;

	cin >> t;
	while (t-- != 0)
	{
		cin >> x1 >> x2 >> x3 >> x4;

		diff1 = x2 - x1;
		diff2 = x3 - x2;
		diff3 = x4 - x3;

		if (diff1 == diff2 && diff2 == diff3)
			cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << x4 + diff3 << endl;
		else
		{
			if (x4 == 0)
				cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << 0 << endl;
			else
				cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << (int)x4*(1.0*x4 / x3) << endl;
		}
			
	}
	return 0;
}