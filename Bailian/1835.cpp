#include <iostream>
#include <string>
#include <vector>

using namespace std;

int x, y, z, p;

void action(int dis)
{
	switch(p)
	{
		case 0:
			x += dis;
			break;
		case 1:
			y += dis;
			break;
		case 2:
			z += dis;
			break;
		case 3:
			x -= dis;
			break;
		case 4:
			y -= dis;
			break;
		case 5:
			z -= dis;
			break;
	}	
}

int main(int argc, char const *argv[])
{
	int forwardCor, upCor, rightCor;
	int m, n;	
	string command;
	int distance;
	
	cin>>m;

	while(m--!=0)
	{
		cin>>n;

		p = forwardCor = 0;
		upCor = 2;
		rightCor = 1;
		x = y = z = 0;
		for(int i=0; i<n; ++i)
		{
			cin>>command>>distance;

			if(command == "up")
			{
				p = upCor;
				upCor = forwardCor<3 ? forwardCor+3 : forwardCor-3;
				forwardCor = p;
			}
			else if(command == "down")
			{
				p = upCor<3 ? upCor+3 : upCor-3;
				upCor = forwardCor;
				forwardCor = p;
			}
			else if(command == "left")
			{
				p = rightCor<3 ? rightCor+3 : rightCor-3;
				rightCor = forwardCor;
				forwardCor = p;
			}
			else if(command == "right")
			{
				p = rightCor;
				rightCor = forwardCor<3 ? forwardCor+3 : forwardCor-3;
				forwardCor = p;
			}
			else if(command == "back")
			{
				forwardCor = forwardCor<3 ? forwardCor+3 : forwardCor-3;
				rightCor = rightCor<3 ? rightCor+3 : rightCor-3;
				p = forwardCor;
			}
			
			action(distance);
		}

		cout<<x<<" "<<y<<" "<<z<<" "<<p<<endl;
	}


	return 0;
}