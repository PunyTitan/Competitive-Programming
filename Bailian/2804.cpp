#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, string> dictionary;

int main(int argc, char const *argv[])
{
	string message;
	int index;
	map<string, string>::const_iterator itr;
	while (getline(cin, message, '\n'))
	{
		if (message == "")
			break;

		index = message.find(' ');
		dictionary[message.substr(index + 1, message.length() - index - 1)] = message.substr(0, index);
	}

	while (cin >> message)
	{
		itr = dictionary.find(message);
		if (itr == dictionary.end())
			cout << "eh" << endl;
		else
			cout << itr->second<<endl;
	}
	return 0;
}