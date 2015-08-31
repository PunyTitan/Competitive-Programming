#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, finalGrade, classGrade, paper, current_money;
	char member, west;
	string name, result;
	int maximum=0;
	int total = 0;

	cin>>N;
	while(N--!=0)
	{
		cin>>name>>finalGrade>>classGrade>>member>>west>>paper;
		current_money = 0;

		if(finalGrade>80 && paper>=1)
			current_money += 8000;
		if(finalGrade>85 && classGrade>80)
			current_money += 4000;
		if(finalGrade>90)
			current_money += 2000;
		if(finalGrade>85 && west=='Y')
			current_money += 1000;
		if(classGrade>80 && member=='Y')
			current_money += 850;

		total += current_money;

		if(current_money>maximum)
		{
			maximum = current_money;
			result = name;
		}
	}

	cout<<result<<endl;
	cout<<maximum<<endl;
	cout<<total<<endl;
	return 0;
}
