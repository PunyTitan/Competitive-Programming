#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	string message;

	cin>>n;

	while(n--!=0)
	{
		getline(cin, message, '\n');
		for(int i=0; i<message.length(); ++i)
		{
			if(message[i] >= 'A' && message[i] <= 'Z' || message[i] >= 'a' && message[i] <= 'z')
			{
				if(message[i] == 'Z')
					message[i] = 'A';
				else if(message[i] == 'z')
					message[i] = 'a';
				else
					message[i] += 1;
			}
		}

		cout<<message<<endl;
	}
	return 0;
}