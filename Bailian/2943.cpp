#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Mouse
{
public:
	int weight;
	string color;
	Mouse(int w = 0, string c = "") :weight(w)
	{
		color = c;
	}
};

template <typename T>
class cmp
{
public:
	bool operator()(const T & op1, const T & op2)
	{
		return op1.weight>op2.weight;
	}
};

int main(int argc, char const *argv[])
{
	int N;
	int current_weight;
	string current_color;
	vector< Mouse > mouses;

	cin >> N;
	while (N-- != 0)
	{
		cin >> current_weight >> current_color;
		mouses.push_back(Mouse(current_weight, current_color));
	}

	sort(mouses.begin(), mouses.end(), cmp<Mouse>());

	for (int i = 0; i<mouses.size(); ++i)
	{
		cout << mouses[i].color << endl;
	}
	return 0;
}