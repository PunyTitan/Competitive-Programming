#include <iostream>
#include <vector>

using namespace std;

int max4(int x1, int x2, int x3, int x4)
{
	int maxX = x1;
	if(x2>maxX)
		maxX = x2;
	if(x3>maxX)
		maxX = x3;
	if(x4>maxX)
		maxX = x4;

	return maxX;
}

int pathLength(vector< vector<int> > & m, int row, int col, vector< vector<int> > & f)
{
	if(f[row][col] != -1)
		return f[row][col];

	int left, right, up, down;
	left = right = up = down = 0;

	if(!(row == 0 || m[row-1][col]>=m[row][col]))
		up = pathLength(m, row-1, col, f);

	if(!(row+1 == m.size() || m[row+1][col]>=m[row][col]))
		down = pathLength(m, row+1, col, f);

	if(!(col == 0 || m[row][col-1]>=m[row][col]))
		left = pathLength(m, row, col-1, f);

	if(!(col+1 == m[0].size() || m[row][col+1]>=m[row][col]))
		right = pathLength(m, row, col+1, f);
	
	return f[row][col] = max4(up, down, left, right) + 1;
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
				flagV[i][j] = pathLength(skiField, i, j, flagV);

	for(int i=0; i<row; ++i)
		for(int j=0; j<col; ++j)
			if(flagV[i][j]>largest)
				largest = flagV[i][j];

	cout<<largest<<endl;

	return 0;
}