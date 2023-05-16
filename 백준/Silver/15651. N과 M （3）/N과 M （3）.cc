#include <iostream>

using namespace std;

int N, M;

void my_print(int num)
{
	if(!num)
		return ;
	int tmp_num = num % 10;
	my_print(num / 10);
	cout << tmp_num << " ";
}

void recursive_print(int stack, int num)
{
	if(stack == M)
	{
		my_print(num);
		cout << "\n";
		return ;
	}
	for(int i = 1; i <= N; i ++)
	{
		recursive_print(stack+1, num * 10 + i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> N >> M;
	recursive_print(0, 0);
}