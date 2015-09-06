#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Node
{
public:
	int x;
	int y;
	int count;

	Node(int x = 0, int y = 0, int c = 0) :x(x), y(y), count(c)
	{}
};

template <typename T>
class cmp
{
public:
	bool operator()(const T & op1, const T & op2)
	{
		return op1.count>op2.count;
	}
};

int main(int argc, char const *argv[])
{
	int T;
	int M, N, K;
	int current_count;
	vector< Node > farm;
	int corn_count;
	int distance;

	cin >> T;
	while (T-- != 0)
	{
		corn_count = 0;
		distance = 0;

		cin >> M >> N >> K;

		farm.clear();

		for (int i = 0; i<M; ++i)
		for (int j = 0; j<N; ++j)
		{
			cin >> current_count;
			if (current_count != 0)
				farm.push_back(Node(i, j, current_count));
		}

		sort(farm.begin(), farm.end(), cmp<Node>());

		distance = 2;

		for (int i = 0; i<farm.size(); ++i)
		{
			if (i == 0)
			{
				if (distance + farm[i].x * 2 + 1 > K)
					break;
				distance += farm[i].x + 1;
				corn_count += farm[i].count;
				continue;
			}

			if (distance + abs(farm[i].y - farm[i - 1].y) + abs(farm[i].x - farm[i - 1].x) + 1 + farm[i].x > K)
				break;
			distance += abs(farm[i].y - farm[i - 1].y) + abs(farm[i].x - farm[i - 1].x) + 1;
			corn_count += farm[i].count;
		}

		cout << corn_count << endl;

	}
	return 0;
}