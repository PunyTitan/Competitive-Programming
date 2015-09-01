#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string current_line;
	string command;


	while(true)
	{
		getline(cin, command, '\n');
		if(command == "ENDOFINPUT")
			break;

		getline(cin, current_line, '\n');

		getline(cin, command, '\n');

		for(int i=0; i<current_line.length(); ++i)
		{
			if(current_line[i]>='A' && current_line[i]<='Z')
			{
				if(current_line[i]<='E')
					current_line[i] = 'Z'+1+(current_line[i]-'A')-5;
				else
					current_line[i] -= 5;
			}
		}

		cout<<current_line<<endl;
	}

	return 0;
}
