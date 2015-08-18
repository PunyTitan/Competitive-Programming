#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;


int main(int argc, char const *argv[])
{
	vector<int> box(7);
	int count;
	int left_blocks, temp_count, max_box2, max_box1;
	cin>>box[1]>>box[2]>>box[3]>>box[4]>>box[5]>>box[6];
	while(!(box[6] == 0 && box[1] == 0 && box[2] == 0 && box[3] == 0 && box[4] == 0 && box[5] == 0))
	{
		count = box[6];

		if(box[5]>0)
		{
			count += box[5];
			box[1] = box[1]-box[5]*11>0 ? box[1]-box[5]*11 : 0; 
		}

		if(box[4]>0)
		{
			count += box[4];
			max_box2 = box[4]*5;
			if(max_box2 >= box[2])
			{
				max_box1 = (max_box2-box[2]) * 4;
				box[2] = 0;
				box[1] = box[1]-max_box1>0 ? box[1]-max_box1 : 0;
			}
			else
			{
				box[2] -= max_box2;
			}			
		}


		if(box[3]>0)
		{
			temp_count = (int)ceil(9.0*box[3]/36.0);
			count += temp_count;

			left_blocks = temp_count*36 - box[3]*9;

			if(left_blocks>0)
			{
				switch(left_blocks/9)
				{
					case 3:
						max_box2 = 5;
						break;
					case 2:
						max_box2 = 3;
						break;
					case 1:
						max_box2 = 1;
						break;
				}
				if(max_box2>box[2])
				{
					max_box1 = left_blocks - box[2]*4;
					box[2] = 0;
				}
				else
				{
					max_box1 = left_blocks - max_box2*4;
					box[2] -= max_box2;
				}

				if(max_box1>0)
					box[1] = box[1]-max_box1>0 ? box[1]-max_box1 : 0;
			}
		}

		if(box[2]>0)
		{
			temp_count = (int)ceil(4.0*box[2]/36.0);
			count += temp_count;

			max_box1 = temp_count*36 - box[2]*4;
			box[1] = box[1]-max_box1>0 ? box[1]-max_box1 : 0;
		}

		if(box[1]>0)
			count += (int)ceil(box[1]/36.0);

		cout<<count<<endl;
		cin>>box[1]>>box[2]>>box[3]>>box[4]>>box[5]>>box[6];
	}

	return 0;
}