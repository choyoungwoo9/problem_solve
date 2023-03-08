#include <stdio.h>

typedef struct node
{
	int parent;
	int num;
	struct node *next;
}	node;

node index_node[50];

node node_pool[100];
int count;

node *get_node(int num, int parent)
{
	node_pool[count].num = num;
	node_pool[count].parent = parent;
	return &node_pool[count ++];
}

int N;
int root_index;

int leaf_count;
void get_leaf_node(node *cur)
{
	node *tmp = cur->next;
	if(tmp == NULL)
		leaf_count ++;
	while(tmp)
	{
		get_leaf_node(&index_node[tmp->num]);
		tmp = tmp->next;
	}
	return ;
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i ++)
	{
		int parent;
		scanf("%d", &parent);
		index_node[i].parent = parent;
		if(parent == -1)
		{
			root_index = i;
		}
		else
		{
			node *tmp_node = get_node(i, parent);
			tmp_node->next = index_node[parent].next;
			
			index_node[parent].next = tmp_node;
		}
	}
	int target_index;
	scanf("%d", &target_index);
	int target_parent = index_node[target_index].parent;
	//printf("pa %d\n", target_parent);
	if(target_parent == -1)
	{
		printf("0\n");
		return 0;
	}
	node *tmp = index_node[target_parent].next;
	if(tmp->num == target_index)
	{
		index_node[target_parent].next = tmp->next;
	}
	else
	{
		while(tmp)
		{
			//printf("  %d\n", tmp->num);
			if(tmp->next->num == target_index)
			{
				tmp->next = tmp->next->next;
				break ;
			}
			tmp = tmp->next;
		}
	}
	get_leaf_node(&index_node[root_index]);
	printf("%d\n", leaf_count);
}