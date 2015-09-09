#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool outputed;
int s, n;
int row, col;

void pRow1(int i, int j)
{
	if ((j != 0 && j != col - 1) && (i == 0))
	{
		cout << '-';
		outputed = true;
	}
}

void pRow2(int i, int j)
{
	if ((j != 0 && j != col - 1) && (i == s + 1))
	{
		cout << '-';
		outputed = true;
	}
}

void pRow3(int i, int j)
{
	if ((j != 0 && j != col - 1) && (i == row - 1))
	{
		cout << '-';
		outputed = true;
	}
}

void pCol1(int i, int j)
{
	if ((j == 0) && (i>0 && i<s + 1))
	{
		cout << '|';
		outputed = true;
	}
}

void pCol2(int i, int j)
{
	if ((j == col - 1) && (i>0 && i<s + 1))
	{
		cout << '|';
		outputed = true;
	}
}

void pCol3(int i, int j)
{
	if ((j == 0) && (i>s + 1 && i<row - 1))
	{
		cout << '|';
		outputed = true;
	}
}

void pCol4(int i, int j)
{
	if ((j == col - 1) && (i>s + 1 && i<row - 1))
	{
		cout << '|';
		outputed = true;
	}
}

void pAllRow(int i, int j)
{
	pRow1(i, j);
	pRow2(i, j);
	pRow3(i, j);
}

void pAllCol(int i, int j)
{
	pCol1(i, j);
	pCol2(i, j);
	pCol3(i, j);
	pCol4(i, j);
}

int main(int argc, char const *argv[])
{
	
	vector<int> number;


	while (cin >> s >> n)
	{
		if (s == 0 && n == 0)
			break;

		number.clear();
		while (n != 0)
		{
			number.insert(number.begin(), n % 10);
			n /= 10;
		}

		for(int i=0; i<number.size(); ++i)
			cout<<number[i]<<" ";

		row = 2 * s + 3;
		col = s + 2;

		for (int i = 0; i<row; ++i)
		{
			for (int num = 0; num<number.size(); ++num)
			{
				for (int j = 0; j<col; ++j)
				{
					outputed = false;
					switch (number[num])
					{
					case 0:
						pRow1(i, j);
						pRow3(i, j);
						pAllCol(i, j);
						break;
					case 1:
						pCol2(i, j);
						pCol4(i, j);
						break;
					case 2:
						pAllRow(i, j);
						pCol2(i, j);
						pCol3(i, j);
						break;
					case 3:
						pAllRow(i, j);
						pCol2(i, j);
						pCol4(i, j);
						break;
					case 4:
						pRow2(i, j);
						pCol1(i, j);
						pCol2(i, j);
						pCol4(i, j);
						break;
					case 5:
						pAllRow(i, j);
						pCol1(i, j);
						break;
					case 6:
						pAllRow(i, j);
						pCol1(i, j);
						pCol3(i, j);
						pCol4(i, j);
						break;
					case 7:
						pRow1(i, j);
						pCol2(i, j);
						pCol4(i, j);
						break;
					case 8:
						pAllRow(i, j);
						pAllCol(i, j);
						break;
					case 9:
						pAllRow(i, j);
						pCol1(i, j);
						pCol2(i, j);
						pCol4(i, j);
						break;
					}
					if (!outputed)
						cout << ' ';
				}
				cout << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}