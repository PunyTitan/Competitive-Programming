#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

vector< vector<char> > mistery;
vector<char> charOfWords;
vector< vector<bool> > flags;
int N,M,P;

/*
	state: 0 for begin, 1 for other characters
*/
bool dfs(int state, int row, int col, vector<char>::const_iterator currentChar_itr)
{
	bool next;

	if(currentChar_itr == charOfWords.end())
		return true;

	if(*currentChar_itr == '*')
		return dfs(0, 0, 0, currentChar_itr+1);

	//current character is the begin charactor of a word
	if(state == 0)	
	{
		for(int i=0; i<M; ++i)
		{
			for(int j=0; j<N; ++j)
			{
				if(mistery[i][j] == *currentChar_itr && !flags[i][j])
				{
					flags[i][j] == true;
					next = dfs(1, i, j, currentChar_itr+1);
					if(next)
						return true;
					else
						flags[i][j] = false;
				}
			}
		}
		return false;
	}

	//current character is not the begin charactor of a word
	else
	{
		if(row-1>=0 && mistery[row-1][col]==*currentChar_itr && !flags[row-1][col])
		{
			flags[row-1][col] = true;
			next = dfs(1, i-1, j, currentChar_itr+1);
			if(next)
				return true;
			else
				flags[row-1][col] = false;
		}
		else if(i+1<M && mistery[row+1][col]==*currentChar_itr && !flags[row+1][col])
		{
			flags[row+1][col] = true;
			next = dfs(1, i+1, j, currentChar_itr+1);
			if(next)
				return true;
			else
				flags[row+1][col] = false;
		}
		else if(j-1>=0 && mistery[row][col-1]==*currentChar_itr && !flags[row][col-1])
		{
			flags[row][col-1] = true;
			next = dfs(1, i, j-1, currentChar_itr+1);
			if(next)
				return true;
			else
				flags[row][col-1] = false;
		}
		else if(j+1<N && mistery[row][col+1]==*currentChar_itr && !flags[row][col+1])
		{
			flags[row][col+1] = true;
			next = dfs(1, i, j+1, currentChar_itr+1);
			if(next)
				return true;
			else
				flags[row][col+1] = false;
		}
		return false;
	}
}

int main(int argc, char const *argv[])
{	
	int charOfWords_length=0;
	string current_word;
	vector<string> words;

	cin>>N>>M>>P;

	mistery.resize(N);
	for(int i=0; i<N; ++i)
		mistery[i].resize(M);

	for(int i=0; i<N; ++i)
		for(int j=0; j<M; ++j)
			cin>>mistery[i][j];

	for(int i=0; i<N; ++i)
		for(int j=0; j<M; ++j)
			flags[i][j] = false;	

	for(int i=0; i<P; ++i)
	{
		cin>>current_word;
		words.push_back(current_word);
		charOfWords_length += current_word.length() + 1;
	}

	charOfWords.reserve(charOfWords_length);

	for(int i=0; i<words.size(); ++i)
	{
		for(int j=0; j<words[i].length(); ++j)
		{
			charOfWords.push_back(words[i][j]);
		}
		charOfWords.push_back('*');
	}

	bool search_result = dfs(0, 0, 0, charOfWords.begin());
	set<char> result;

	if(search_result)
	{
		for(int i=0; i<N; ++i)
			for(int j=0; j<M; ++j)
				if(!flags[i][j])
					result.insert(mistery[i][j]);

		for(set<char>::const_iterator itr=result.begin(); itr!=result.end(); ++itr)
			cout<<*itr;
	}
	else
		cout<<"Some word cannot be found"<<endl;

/*	for(int i=0; i<N; ++i)
	{
		for(int j=0; j<M; ++j)
			cout<<mistery[i][j]<<" ";
		cout<<endl;
	}

	for(int i=0; i<charOfWords.size(); ++i)
		cout<< charOfWords[i]<< " ";*/

	
	return 0;
}