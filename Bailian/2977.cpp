#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int p, e, i, d;
	int begin_p, begin_e, begin_i;
	int next;
	int caseI = 1;

	while (cin >> p >> e >> i >> d)
	{
		if (p == -1 && e == -1 && i == -1 && d == -1)
			break;
		begin_p = p % 23;
		begin_e = e % 28;
		begin_i = i % 33;

		for (next = begin_i;; next += 33)
		{
			if ((next - begin_p) % 23 == 0 && (next - begin_e) % 28 == 0 && next>d)
			{
				cout << "Case " << caseI << ": the next triple peak occurs in " << next - d << " days." << endl;
				break;
			}
		}
		++caseI;
	}
	return 0;
}
