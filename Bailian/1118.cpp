#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <set>

using namespace std;


void calculateLine(pair<int, int> &point1, pair<int, int> &point2, double &k, double &b)
{
	if (point1.first == point2.first)
	{
		k = numeric_limits<double>::infinity();
		b = numeric_limits<double>::infinity();
		return;
	}
	k = 1.0 * (point1.second - point2.second) / (point1.first - point2.first);
	b = point1.second - point1.first * k;
}

int main(int argc, char const *argv[])
{
	map< pair<double, double>, set<int> > lines;
	vector< pair<int, int> > points(700);
	int numOfNode, x, y, largest = 0;
	double k, b;
	k = b = 0;

	cin >> numOfNode;
	while (numOfNode != 0)
	{
		for (int i = 0; i<numOfNode; ++i)
		{
			cin >> x >> y;
			points[i].first = x;
			points[i].second = y;
		}

		

		for (int i = 0; i + 1<numOfNode; ++i)
		for (int j = i + 1; j<numOfNode; ++j)
		{
			//cout << "compare: (" << points[i].first << "," << points[i].second << ") & (" << points[j].first << "," << points[j].second<<")" << endl;
			calculateLine(points[i], points[j], k, b);
			//cout << "k: " << k << "  b: " << b << endl;
			lines[pair<double, double>(k, b)].insert(j);
			lines[pair<double, double>(k, b)].insert(i);
			
		}

		for (map< pair<double, double>, set<int> >::const_iterator itr = lines.begin(); itr != lines.end(); ++itr)
		if ((itr->second).size()>largest)
			largest = (itr->second).size();

		cout << largest << endl;
		cin >> numOfNode;

	}
	return 0;
}