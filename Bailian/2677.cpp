#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > figure;
int N;

bool isTumour(int row, int col)
{
	return figure[row][col] <= 50;
}

bool isTumourEdge(int row, int col)
{
	if (row == 0 || row == N - 1 || col == 0 || col == N - 1)
		return true;
	if (!isTumour(row - 1, col) || !isTumour(row + 1, col) || !isTumour(row, col - 1) || !isTumour(row, col + 1))
		return true;
	return false;
}

int main(int argc, char const *argv[])
{
	int area = 0;
	int per = 0;

	cin >> N;

	figure.resize(N);
	for (int i = 0; i<N; ++i)
		figure[i].resize(N);

	for (int i = 0; i<N; ++i)
	for (int j = 0; j<N; ++j)
		cin >> figure[i][j];

	for (int i = 0; i<N; ++i)
	for (int j = 0; j<N; ++j)
	{
		if (isTumour(i, j))
		{
			++area;
			if (isTumourEdge(i, j))
				++per;
		}
	}

	cout << area << " " << per;

	return 0;
}