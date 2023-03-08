#include <stdio.h>
#include <stdlib.h>

int can_use_num[10];
int want_channel;
int min = 2147483647;

int my_abs(int num)
{
	if(num < 0)
		return -1 * num;
	return num;
}

void check_num(int num)
{
	int origin = num;
	int count = 0;
	while(num)
	{
		int cur_num = num % 10;
		if(can_use_num[cur_num] == 0)
			return ;
		count ++;
		num = num / 10;
	}
	//printf("ndum : %d count : %d\n", origin, count);
	int answer = count + my_abs(want_channel - origin);
	//printf("answer : %d\n", answer);
	if(answer < min)
		min = answer;
}

void zero_num()
{
	if(can_use_num[0])
	{
		int answer = 1 + want_channel;
		if(answer < min)
		{
			min = answer;
		}
	}
}

void no_move()
{
	int answer = my_abs(100 - want_channel);
	if(answer < min)
		min = answer;
}

int main()
{
	for(int i = 0; i < 10; i ++)
		can_use_num[i] = 1;
	scanf("%d", &want_channel);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
	{
		int num;
		scanf("%d", &num);
		can_use_num[num] = 0;
	}
	for(int i = 1; i < 1000000; i ++)
	{
		check_num(i);
	}
	zero_num();
	no_move();
	printf("%d\n", min);
}