#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int sum=0;
	int current_student;
	vector<int> students;

	cin>>n;
	
	for(int i=0; i<n; ++i)
	{
		cin>>current_student;
		students.push_back(current_student);
	}

	for(int i=0; i<students.size(); ++i)
		sum += students[i];

	printf("%.2f\n", 1.0*sum/n);
	return 0;
}