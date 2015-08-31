#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

vector< vector<char> > color;

void king(pair<int, int> begin, pair<int, int> end)
{
	int x_distance = abs(begin.first - end.first);
	int y_distance = abs(begin.second - end.second);
	cout << max(x_distance, y_distance) << " ";
}

void queen(pair<int, int> begin, pair<int, int> end)
{
	int x_distance = abs(begin.first - end.first);
	int y_distance = abs(begin.second - end.second);

	if (begin.first == end.first && begin.second == end.second)
		cout << 0 << " ";
	else if (begin.first == end.first || begin.second == end.second)
		cout << 1 << " ";
	else if (x_distance == y_distance)
		cout << 1 << " ";
	else
		cout << 2 << " ";
}

void vehicle(pair<int, int> begin, pair<int, int> end)
{
	if (begin.first == end.first && begin.second == end.second)
		cout << 0 << " ";
	else if (begin.first == end.first || begin.second == end.second)
		cout << 1 << " ";
	else
		cout << 2 << " ";
}

void elephant(pair<int, int> begin, pair<int, int> end)
{
	int x_distance = abs(begin.first - end.first);
	int y_distance = abs(begin.second - end.second);

	if (begin.first == end.first && begin.second == end.second)
		cout << 0 << " ";
	else if (x_distance == y_distance)
		cout << 1 << " ";
	else if (color[begin.first][begin.second] == color[end.first][end.second])
		cout << 2 << " ";
	else
		cout << "Inf" << " ";
}

int main(int argc, char const *argv[])
{
	int t;
	string str1, str2;
	pair<int, int> begin;
	pair<int, int> end;

	color.resize(8);
	for (int i = 0; i<8; ++i)
		color[i].resize(8);

	int temp;
	for (int i = 0; i<8; ++i)
	{
		temp = i;
		for (int j = 0; j<8; ++j)
		{
			if (temp % 2 == 0)
				color[i][j] = 'w';
			else
				color[i][j] = 'b';
			++temp;
		}
	}
	

	cin >> t;

	while (t-- != 0)
	{
		cin >> str1 >> str2;
		begin.first = 'h' - str1[0];
		begin.second = str1[1] - '1';
		end.first = 'h' - str2[0];
		end.second = str2[1] - '1';

		king(begin, end);
		queen(begin, end);
		vehicle(begin, end);
		elephant(begin, end);

		cout << endl;
	}

	return 0;
}
