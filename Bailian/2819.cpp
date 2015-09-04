#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int k1, k2, k3;
	string current_str;
	string result;
	vector<int> index_k1;
	vector<int> index_k2;
	vector<int> index_k3;

	while (cin >> k1 >> k2 >> k3)
	{
		if (k1 == 0 && k2 == 0 && k3 == 0)
			break;

		index_k1.clear();
		index_k2.clear();
		index_k3.clear();

		cin >> current_str;

		if (current_str.size() == 0)
		{
			cout << endl;
			return 0;
		}

		result.resize(current_str.length());

		for (int i = 0; i<current_str.length(); ++i)
		{
			if (current_str[i] >= 'a' && current_str[i] <= 'i')
				index_k1.push_back(i);
			else if (current_str[i] >= 'j' && current_str[i] <= 'r')
				index_k2.push_back(i);
			else
				index_k3.push_back(i);
		}
		if(!index_k1.empty())
			k1 %= index_k1.size();
		if(!index_k2.empty())
			k2 %= index_k2.size();
		if(!index_k3.empty())
			k3 %= index_k3.size();

		for (int i = 0; i<index_k1.size(); ++i)
			result[index_k1[(i + k1) % index_k1.size()]] = current_str[index_k1[i]];

		for (int i = 0; i<index_k2.size(); ++i)
			result[index_k2[(i + k2) % index_k2.size()]] = current_str[index_k2[i]];

		for (int i = 0; i<index_k3.size(); ++i)
			result[index_k3[(i + k3) % index_k3.size()]] = current_str[index_k3[i]];

		cout << result << endl;
	}
	return 0;
}