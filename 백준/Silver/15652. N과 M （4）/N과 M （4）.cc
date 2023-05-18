#include <iostream>

using namespace std;

int N, M;

void recursive_print(int num)
{
	if(num < 10)
	{
		cout << num << " ";
	}
	else
	{
		recursive_print(num / 10);
		cout << num % 10 << " ";
	}
}

void find(int num, int count, int member)
{
	if(count == M)
	{
		recursive_print(member);
		cout << "\n";
		return ;
	}
	for(int i = num; i <= N; i ++)
	{
		find(i, count+1, member * 10 + i);
	}
	
}

int main()
{
	cin >> N >> M;
	find(1, 0, 0);
}