#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <set>
#include <algorithm>

using namespace std;

class Point
{
public:
	Point(int x = 0, int y = 0) :x(x), y(y)
	{}

	int x;
	int y;

};

double getSlope(Point &point1, Point &point2)
{
	double k;

	k = 1.0 * (point1.y - point2.y) / (point1.x - point2.x);

	return k;
}

int getMax(vector<double> & slopes)
{
	int maximum = 0;
	int count = 0;
	double lastSlop = slopes[0];

	for (vector<double>::const_iterator itr = slopes.begin(); itr != slopes.end(); ++itr)
	{
		if (*itr == lastSlop)
			++count;
		else
		{
			if (count>maximum)
				maximum = count;
			count = 1;
			lastSlop = *itr;
		}
	}

	if (count > maximum)
		maximum = count;

	return maximum + 1;
}

int main(int argc, char const *argv[])
{
	vector< Point > points;
	vector<double> slopes;
	int numOfPoints, x, y, temp, largest;
	int vertical;

	cin >> numOfPoints;
	while (numOfPoints != 0)
	{
		largest = 0;
		for (int i = 0; i<numOfPoints; ++i)
		{
			cin >> x >> y;
			points.push_back(Point(x, y));
		}

		for (int i = 0; i + 1<numOfPoints; ++i)
		{
			vertical = 1;
			for (int j = i+1; j < numOfPoints; ++j)
			{
				if (points[i].x == points[j].x)
					++vertical;
				else
					slopes.push_back(getSlope(points[i], points[j]));
			}
		

			if (vertical>largest)
				largest = vertical;
			if (slopes.size()+1 > largest)
			{
				sort(slopes.begin(), slopes.end());
				temp = getMax(slopes);

				if (temp>largest)
					largest = temp;				
			}
			slopes.clear();
			
		}

		cout << largest << endl;
		points.clear();
		cin >> numOfPoints;
	}


	return 0;
}