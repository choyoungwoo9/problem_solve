#include <stdio.h>

int N;

unsigned int heap[100001];
int count = 0;

void swap(int index_a, int index_b)
{
	unsigned int tmp;
	tmp = heap[index_a];
	heap[index_a] = heap[index_b];
	heap[index_b] = tmp;
}

void push(unsigned int num)
{
	count ++;
	heap[count] = num;
	int tmp = count;
	while(tmp != 1&&heap[tmp / 2] < heap[tmp])
	{
		swap(tmp, tmp / 2);
		tmp = tmp / 2;
	}
}

unsigned int pop()
{
	if(count == 0)
		return 0;
	unsigned int ret = heap[1];
	heap[1] = heap[count];
	count --;
	int tmp = 1;
	while(1)
	{
		if(tmp * 2 > count)
		{
			break;
		}
		else if(tmp * 2 + 1 > count)
		{
			if(heap[tmp] < heap[tmp * 2])
			{
				swap(tmp, tmp * 2);
				tmp = tmp * 2;
			}
			else
				break;
		}
		else
		{
			int max;
			if(heap[tmp * 2] < heap[tmp * 2 + 1])
				max = tmp * 2 + 1;
			else
				max = tmp * 2;
			if(heap[tmp] < heap[max])
			{
				swap(tmp, max);
				tmp = max;
			}
			else
				break;
		}
	}
	return ret;
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i ++)
	{
		unsigned int num;
		scanf(" %u", &num);
		if(!num)
			printf("%d\n", pop());
		else
			push(num);
	}
}