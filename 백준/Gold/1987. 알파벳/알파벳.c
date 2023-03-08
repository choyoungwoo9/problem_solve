#include <stdio.h>

int R, C;

char input[20][21];
int max;

void find_answer(int i, int j, int state, int count)
{
	state = state | 1 << (input[i][j] - 'A');
	int dx[4] = {-1, 0, 0, 1};
	int dy[4] = {0, 1, -1, 0};
	for(int k = 0; k < 4; k ++)
	{
		if(i + dx[k] < 0 || i + dx[k] >= R || j + dy[k] < 0 || j + dy[k] >= C)
			continue;
		if(!(state & 1 << (input[i+dx[k]][j+dy[k]]-'A')))
			find_answer(i+dx[k], j+dy[k], state, count + 1);
	}
	if(max < count)
		max = count;
}


int main()
{
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; i ++)
		scanf("%s", input[i]);
	find_answer(0, 0, 0, 1);
	printf("%d\n", max);
}