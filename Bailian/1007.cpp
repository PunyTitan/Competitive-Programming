#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Node
{
public:
	string seq;
	int numberOfPairs;
	int inputOrder;

	Node(string s, int order, int num=0):seq(s), inputOrder(order), numberOfPairs(num)
	{}
};

bool compareNode(const Node & node1, const Node & node2)
{
	if(node1.numberOfPairs<node2.numberOfPairs)
		return true;
	else if(node1.numberOfPairs>node2.numberOfPairs)
		return false;
	else
		return node1.inputOrder<node2.inputOrder;
}

int countPairs(string str, int size)
{
	int count = 0;
	if(size == 0)
		return 0;
	for(int i=0; i+1<size; ++i)
	{
		for(int j=i+1;j<size; ++j)
		{
			if(str[i]>str[j])
				++count;
		}
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int n, m;
	cin>>n>>m;
	string inputStr;
	vector<Node> nodes;

	for(int i = 0; i<m; ++i)
	{
		cin>>inputStr;
		nodes.push_back(Node(inputStr, i, countPairs(inputStr, n)));
	}	
	sort(nodes.begin(), nodes.end(), compareNode);

	for(vector<Node>::const_iterator itr = nodes.begin(); itr != nodes.end(); ++itr)
		cout<<(*itr).seq<<endl;

	return 0;
}