#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAGIC_NUM 100001

typedef struct node
{
	int num;
	int count;
	struct node *next;
}	node;
node node_pool[500000];
int count = 0;

node index_node[MAGIC_NUM];
int N, M;

void init()
{
	for(int i = 0; i < MAGIC_NUM; i ++)
	{
		index_node[i].next = NULL;
	}
}

node *make_node(int num)
{
	node_pool[count].num = num;
	node_pool[count].next = NULL;
	node_pool[count].count = 1;
	return &node_pool[count ++];
}

void add_hash(int num)
{
	node *tmp = &index_node[abs(num % MAGIC_NUM)];
	while(tmp->next)
	{
		if(tmp->next->num == num)
		{
			//printf("count : %d\n", tmp->next->count);
			tmp->next->count ++;
			return ;
		}
		tmp = tmp->next;
	}
	tmp->next = make_node(num);
}

int find_hash(int num)
{
	node *tmp = &index_node[abs(num % MAGIC_NUM)];
	while(tmp->next)
	{
		if(tmp->next->num == num)
		{
			return tmp->next->count;
		}
		tmp = tmp->next;
	}
	return 0;
}

int main()
{
	init();
	scanf("%d", &N);
	for(int i = 0; i < N; i ++)
	{
		int tmp;
		scanf(" %d", &tmp);
		add_hash(tmp);
	}
	scanf("%d", &M);
	for(int i = 0; i < M; i ++)
	{
		int tmp;
		scanf(" %d", &tmp);
		printf("%d ", find_hash(tmp));
	}
}