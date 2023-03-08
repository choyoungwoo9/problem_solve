#include <iostream>

using namespace std;

int generate(int num)
{
	int answer = num;
	while(num)
	{
		answer += num % 10;
		num = num / 10;
	}
	return answer;
}

int is_self_num(int num)
{
	for(int i = 1; i < num; i ++)
	{
		int generated_num;
		if(generate(i) == num)
			return 0;
	}
	return 1;
}

int main()
{
	for(int i = 1; i <= 10000; i ++)
	{
		if(is_self_num(i))
			cout << i << "\n";
	}
}