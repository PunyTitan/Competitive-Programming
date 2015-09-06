#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>

using namespace std;

class Node
{
public:
	double x;
	double y;
	Node(int x = 0, int y = 0) :x(x), y(y)
	{}
};

double calculateDis(Node node1, Node node2)
{
	double x_dis = node1.x - node2.x;
	double y_dis = node1.y - node2.y;

	return x_dis*x_dis + y_dis*y_dis;
}

int main(int argc, char const *argv[])
{
	int n;
	vector<Node> nodes;
	double max_dis = 0;
	double temp;


	cin >> n;
	nodes.resize(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> nodes[i].x >> nodes[i].y;
	}

	for (int i = 0; i + 1 < n; ++i)
	for (int j = i + 1; j<n; ++j)
	{
		temp = calculateDis(nodes[i], nodes[j]);
		if (temp>max_dis)
			max_dis = temp;
	}

	printf("%.4f", sqrt(max_dis));

	return 0;
}