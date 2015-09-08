#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> largeResult(100);

void calculate(unsigned long long op1, unsigned long long op2)
{
	unsigned long long current_product;
	int count = 1;
	int result_index, next;
	int result_len = largeResult.size();
	int i;

	while (op1 != 0)
	{
		result_index = result_len - count;
		current_product = (op1 % 10) * op2;
		op1 /= 10;

		next = 0;

		for (i = 0; current_product != 0; ++i)
		{
			largeResult[result_index - i] += current_product % 10 + next;
			current_product /= 10;

			if (largeResult[result_index - i] >= 0)
			{
				next = largeResult[result_index - i] / 10;
				largeResult[result_index - i] %= 10;
			}
			else
				next = 0;
		}
		largeResult[result_index - i] += next;

		++count;
	}

}

int main(int argc, char const *argv[])
{
	unsigned long long resultMap[51];
	int valid = false;
	int N;

	fill(largeResult.begin(), largeResult.end(), 0);

	resultMap[0] = 1;
	for (int i = 1; i <= 50; ++i)
		resultMap[i] = resultMap[i - 1] * 2;

	cin >> N;
	if (N <= 50)
		cout << resultMap[N];
	else
	{
		calculate(resultMap[50], resultMap[N - 50]);
		for (int i = 0; i<largeResult.size(); ++i)
		{
			if (largeResult[i] != 0)
			{
				valid = true;
				cout << largeResult[i];
			}
			else if (valid)
				cout << largeResult[i];
		}
	}

	return 0;
}