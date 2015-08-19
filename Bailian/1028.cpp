#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string str)
{
	vector<string> rtr;
	string token;
	stringstream strS(str);
	while(getline(strS, token ,' '))
	{
		rtr.push_back(token);
	}

	return rtr;
}

int main(int argc, char const *argv[])
{
	stack<string> backS;
	stack<string> forwardS;
	string command, page_name, current_page = "http://www.acm.org/";
	vector<string> commandV;

	getline(cin, command, '\n');
	commandV = split(command);

	while(commandV[0] != "QUIT")
	{
		if(commandV[0] == "BACK")
		{
			if(backS.empty())
				cout<<"Ignored"<<endl;
			else
			{
				forwardS.push(current_page);
				current_page = backS.top();
				backS.pop();
				cout<<current_page<<endl;
			}
		}
		else if(commandV[0] == "FORWARD")
		{
			if(forwardS.empty())
				cout<<"Ignored"<<endl;
			else
			{
				backS.push(current_page);
				current_page = forwardS.top();
				forwardS.pop();
				cout<<current_page<<endl;
			}
		}
		else
		{
			page_name = commandV[1];
			backS.push(current_page);
			current_page = page_name;
			cout<<current_page<<endl;
			while(!forwardS.empty())
				forwardS.pop();
		}

		getline(cin, command, '\n');
		commandV = split(command);
	}

	return 0;
}