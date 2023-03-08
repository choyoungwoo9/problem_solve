#include <stdio.h>

char str[51];

void solution()
{
	int check = 0;
	for(int i = 0; str[i]; i ++)
	{
		if(str[i] == '(')
			check ++;
		else if(str[i] == ')')
			check --;
		if(check < 0)
		{
			printf("NO\n");
			return ;
		}
	}
	if(check == 0)
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i ++)
	{
		scanf(" %s", str);
		solution();
	}
}