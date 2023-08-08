#include <iostream>
#include <vector>

using namespace std;

int score[10];

int main()
{
	for(int i = 1; i <= 9; i++)
	{
		cin >> score[i];
		score[i] += score[i-1];
	}
	int sum = 0;
	int flag = 0;
	for(int i = 1; i <= 9; i++)
	{
		if(sum < score[i])
			flag = 1;
		int num;
		cin >> num;
		sum = sum + num;
	}
	if(flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}