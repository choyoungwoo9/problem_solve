#include <iostream>
#include <string>
using namespace std;

//left = 6
//right = 2
int ar[4][8];

//type 0 -> first gogo
//type 1 -> right gogo
//type 2 -> left gogo

//dir 1 -> clock
//dir -1 -> reverse clock
void spin(int num, int dir, int type)
{
	// cout << num<< " "  << dir << " " << type;
	// cout << endl;
	if(type == 0)
	{
		if(num != 3 && ar[num][2] != ar[num+1][6])
			spin(num+1, dir*(-1), 1);
		if(num != 0 && ar[num][6] != ar[num-1][2])
			spin(num-1, dir*(-1), 2);
	}
	else if(type == 1)
	{
		if(num != 3 && ar[num][2] != ar[num+1][6])
			spin(num+1, dir*(-1), 1);
	}
	else if(type == 2)
	{
		if(num != 0 && ar[num][6] != ar[num-1][2])
			spin(num-1, dir*(-1), 2);
	}

	int tmp_ar[8];
	for(int i = 0; i < 8; i ++)
	{
		if(dir == -1)
		{
			tmp_ar[i] = ar[num][(i+1)%8];
		}
		else if(dir == 1)
		{
			tmp_ar[(i+1)%8] = ar[num][i];
		}
	}
	for(int i = 0; i < 8; i ++)
		ar[num][i] = tmp_ar[i];
	// cout << num << endl;
	// for(int i = 0; i < 8; i ++)
	// 	cout << ar[num][i];
	// cout << endl;
}

int get_answer()
{
	int ret = 0;
	ret += ar[0][0] * 1;
	ret += ar[1][0] * 2;
	ret += ar[2][0] * 4;
	ret += ar[3][0] * 8;
	return ret;
}

int main()
{
	for(int i = 0; i < 4; i ++)
	{
		string str;
		cin >> str;
		for(int j= 0; j < 8;j ++)
			ar[i][j] = str[j] - '0';
	}
	int k;
	cin >> k;
	for(int i = 0; i < k; i ++)
	{
		int num, dir;
		cin >> num >> dir;
		spin(num-1, dir, 0);
		// for(int k = 0; k < 4; k ++)
		// {
		// 	for(int j = 0; j < 8;j ++)
		// 		cout << ar[k][j];
		// 	cout << endl;
		// }
	}

	cout << get_answer() << endl;
}