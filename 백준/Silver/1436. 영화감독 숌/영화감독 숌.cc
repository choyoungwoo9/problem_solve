#include <iostream>

using namespace std;

int is_int_six(int num)
{
	int flag = 0;
	while(num)
	{
		int tmp = num % 10;
		if(tmp == 6)
			flag ++;
		else
			flag = 0;
		if(flag == 3)
			return 1;
		num = num / 10;
	}
	return 0;
}

int main()
{
	int N;
	cin >> N;
	int count = 0;
	int num = 1;
	while(1)
	{
		if(is_int_six(num))
			count ++;
		if(count == N)
			break;
		num ++;
	}
	cout << num << endl;
}
