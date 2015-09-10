#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	string leftStr[3];
	string rightStr[3];
	string result[3];
	vector<int> coins(12);
	int n;
	int bingo = false;
	int leftCount, rightCount;

	cin >> n;
	while (n-- != 0)
	{
		for (int i = 0; i<3; ++i)
		{
			cin >> leftStr[i] >> rightStr[i] >> result[i];
		}

		for (int fake = 0; fake<12; ++fake)
		{
			fill(coins.begin(), coins.end(), 0);
			for (int lightHeavy = 0; lightHeavy<2; ++lightHeavy)
			{
				if (lightHeavy == 0)
					coins[fake] = -1;
				else
					coins[fake] = 1;

				bingo = true;
				for (int j = 0; j<3; ++j)
				{
					leftCount = rightCount = 0;
					for (int str_index = 0; str_index<leftStr[j].size(); ++str_index)
						leftCount += coins[leftStr[j][str_index] - 'A'];
					for (int str_index = 0; str_index<rightStr[j].size(); ++str_index)
						rightCount += coins[rightStr[j][str_index] - 'A'];

					if (leftCount == rightCount && result[j] != "even")
					{
						bingo = false;
						break;
					}
					if (leftCount < rightCount && result[j] != "down")
					{
						bingo = false;
						break;
					}
					if (leftCount > rightCount && result[j] != "up")
					{
						bingo = false;
						break;
					}

				}

				if (bingo)
				{
					cout << (char)('A' + fake) << " is the counterfeit coin and it is ";
					if (lightHeavy == 0)
						cout << "light";
					else
						cout << "heavy";
					cout << "." << endl;
				}
			}
			if (bingo)
				break;

		}

	}



	return 0;
}