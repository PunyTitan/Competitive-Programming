#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int alphabet[26];
	int N,M,P;
	char current_char;
	vector<char> mistery_word;
	vector<string> words;
	string input_word;

	memset(alphabet, 0, sizeof(alphabet));

	cin>>N>>M>>P;

	for(int i=0; i<M*N; ++i)
	{
		cin>>current_char;
		++alphabet[current_char-'A'];
	}

	for(int i=0; i<P; ++i)
	{
		cin>>input_word;
		words.push_back(input_word);
	}

	for(int i=0; i<words.size(); ++i)
	{
		string current_word = words[i];
		for(int j=0; j<current_word.length(); ++j)
			--alphabet[current_word[j]-'A'];
	}

	for(int i=0; i<26; ++i)
		if(alphabet[i] != 0)
			for(int j=0; j<alphabet[i]; ++j)
				mistery_word.push_back('A'+i);

	sort(mistery_word.begin(), mistery_word.end());

	for(int i=0; i<mistery_word.size(); ++i)
		cout<<mistery_word[i];

	return 0;
}
