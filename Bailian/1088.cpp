#include <iostream>
#include <vector>

using namespace std;

int pathLength(vector< vector<int> > & m, int row, int col)
{
	int left, right, up, down;
	if(row == 0 || m[row-1][col]>m[row][col])
		up = 0;
	else
		up = pathLength(m, )
}

int main(int argc, char const *argv[])
{
	vector< vector<int> > skiField;
	vector< vector<int> > flagV;
	int row, col;
	int largest = -1;

	cin>>row>>col;

	skiField.resize(row);
	for(int i=0; i<row; ++i)
		skiField[i].resize(col);

	flagV.resize(row);
	for(int i=0; i<row; ++i)
		flagV[i].resize(col);

	for(int i=0; i<row; ++i)
		for(int j=0; j<col; ++j)
			flagV[i][j] = -1;

	for(int i=0; i<row; ++i)
		for(int j=0; j<col; ++j)
			cin>>skiField[i][j];

	for(int i=0; i<row; ++i)
		for(int j=0; j<col; ++j)
			if(flagV[i][j] == -1)
				skiField[i][j] = pathLength(skiField, i, j);

	for(int i=0; i<row; ++i)
		for(int j=0; j<col; ++j)
			if(flagV[i][j]>largest)
				largest = flagV[i][j];

	cout<<largest<<endl;

	return 0;
}