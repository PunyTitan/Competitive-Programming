#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string gender;
	double white, red, xuehong, redcell, redboard;
	int k, numOfAbnormal;

	cin>>k;

	while(k--!=0)
	{
		numOfAbnormal = 0;		
		cin>>gender>>white>>red>>xuehong>>redcell>>redboard;

		if(!(white>=4 && white<=10))
			++numOfAbnormal;
		if(!(red>=3.5 && red<=5.5))
			++numOfAbnormal;
		if(gender == "male")
		{
			if(!(xuehong>=120 && xuehong<=160))
				++numOfAbnormal;
			if(!(redcell>=42 && redcell<=48))
				++numOfAbnormal;
		}
		else
		{
			if(!(xuehong>=110 && xuehong<=150))
				++numOfAbnormal;
			if(!(redcell>=36 && redcell<=40))
				++numOfAbnormal;
		}

		if(!(redboard>=100 && redboard<=300))
			++numOfAbnormal;

		if(numOfAbnormal == 0)
			cout<<"normal"<<endl;
		else
			cout<<numOfAbnormal<<endl;
	}
	return 0;
}