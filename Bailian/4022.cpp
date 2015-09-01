#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, K;
	int i;
	double money, housePrice;
	while(cin>>N>>K)
	{
		money = 0;
		housePrice = 200;

		if(housePrice*(K/100.0) >= N)
		{
			cout<<"Impossible"<<endl;
			continue;
		}

		for(i=1; i<=20; ++i)
		{
			money += N;
			if(i != 1)
				housePrice *= 1 + K/100.0;
			if(money>=housePrice)
			{
				cout<<i<<endl;
				break;
			}
			if(i == 20)
			{
				cout<<"Impossible"<<endl;
			}
		}


	}
	return 0;
}
