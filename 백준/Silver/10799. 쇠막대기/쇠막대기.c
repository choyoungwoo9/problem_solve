#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
	char str[100001];
	//scanf("%s", str);
	char c;
	int i = 0;
	scanf("%s", str);
	//printf("%s\n", str);
	int answer;
	int stick_count;
	stick_count = 0;
	answer = 0;
	for(int i = 0; *(str + i); i++)
	{
		if(*(str + i) == '(' && *(str + i + 1) == ')')
		{
			answer = answer + stick_count;
			i = i + 1;
		}
		else if(*(str + i) == '(')
		{
			stick_count ++;
			answer ++;
		}
		else if(*(str + i) == ')')
		{
			stick_count --;
		}
		// else
		// {
		// 	printf("??\n");
		// }
	}
	printf("%d", answer);
	//printf("%d\n", stick_count);
}
