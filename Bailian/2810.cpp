#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;


class Point
{
public:
	int a;
	int b;
	int c;
	int d;
	Point(int a = 0, int b = 0, int c = 0, int d = 0) :a(a), b(b), c(c), d(d)
	{}
};

template <typename T>
class Compare
{
public:
	bool operator()(const T & op1, const T & op2)
	{
		if (op1.a < op2.a)
			return true;
		else if (op1.a > op2.a)
			return false;
		else
		{
			if (op1.b < op2.b)
				return true;
			else if (op1.b > op2.b)
				return false;
			else
			{
				if (op1.c < op2.c)
					return true;
				else if (op1.c > op2.c)
					return false;
				else
				{
					if (op1.d < op2.d)
						return true;
					return false;
				}
			}
		}
	}
};

int cubeMap[101];

int main(int argc, char const *argv[])
{
	int n;
	int a_cube;
	vector<Point> result;
	map< int, int > cubes;

	for (int i = 2; i <= 100; ++i)
	{
		cubeMap[i] = i*i*i;
		cubes[cubeMap[i]] = i;
	}


	cin >> n;

	for (int b = 2; b + 2 <= n; ++b)
	{
		for (int c = b + 1; c + 1 <= n; ++c)
		{
			for (int d = c + 1; d <= n; ++d)
			{
				a_cube = cubeMap[b] + cubeMap[c] + cubeMap[d];
				if (cubes.find(a_cube) != cubes.end() && a_cube <= cubeMap[n])
				{
					result.push_back(Point(cubes[a_cube], b, c, d));
				}
			}
		}
	}

	sort(result.begin(), result.end(), Compare<Point>());

	for (int i = 0; i<result.size(); ++i)
	{
		cout << "Cube = " << result[i].a << ", Triple = (" << result[i].b << "," << result[i].c << "," << result[i].d << ")" << endl;
	}

	return 0;
}
