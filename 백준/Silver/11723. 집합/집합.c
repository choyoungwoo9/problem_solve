#include <stdio.h>

int M;
char input_buf[10];
int input_num;
int set = 0;

void order_add()
{
	scanf(" %d", &input_num);
	set = set | (1 << input_num);
}

void order_remove()
{
	scanf(" %d", &input_num);
	set = set & ~(1 << input_num);
}

void order_check()
{
	scanf(" %d", &input_num);
	if(set & (1 << input_num))
		printf("1\n");
	else
		printf("0\n");
}

void order_toggle()
{
	scanf(" %d", &input_num);
	set = set ^ (1 << input_num);
}

void order_all()
{
	set = (1 << 21) - 1;
}

void order_empty()
{
	set = 0;
}

int main()
{
	scanf("%d", &M);
	for(int i = 0; i < M; i ++)
	{
		scanf("%s", input_buf);
		if(input_buf[0] == 'a')
		{
			if(input_buf[1] == 'd')
				order_add();
			else if(input_buf[1] == 'l')
				order_all();
		}
		else if(input_buf[0] == 'r')
		{
			order_remove();
		}
		else if(input_buf[0] == 'c')
		{	
			order_check();
		}
		else if(input_buf[0] == 't')
		{
			order_toggle();
		}
		else if(input_buf[0] == 'e')
		{
			order_empty();
		}
	}
}