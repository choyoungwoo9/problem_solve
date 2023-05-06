#include <iostream>

using namespace std;

int V;

typedef struct node
{
	int index;
	int length;
	node *next;
} node;

node index_node[100001];

node node_pool[300000];
int pool_count = 0;

node *get_node(int i, int l)
{
	node_pool[pool_count].index = i;
	node_pool[pool_count].length = l;
	return &node_pool[pool_count ++];
}

int answer = 0;

int dfs(int cur_index, int p_index)
{
	node *tmp_node = index_node[cur_index].next;
	int m1 = 0;
	int m2 = 0;
	while(tmp_node)
	{
		if(tmp_node->index != p_index) //length 처리 필요
		{

			int value;
			value = dfs(tmp_node->index, cur_index) + tmp_node->length;
			//cout << "cur : " << cur_index << " " << tmp_node->index << ", " << value << endl;
			if(value > m1)
			{
				m2 = m1;
				m1 = value;
			}
			else if(value > m2)
				m2 = value;
		}
		tmp_node = tmp_node->next;
	}
	if(m1 + m2 > answer)
		answer = m1 + m2;
	//cout << "cur index : " << cur_index << " m : " << m1 << " " << m2 << endl;
	return m1;
}


int main()
{
	scanf("%d", &V);
	for(int i = 1; i <= V; i ++)
	{
		int v_num;
		scanf("%d", &v_num);
		node **tmp_next = &index_node[v_num].next;
		while(1)
		{
			int n1, n2;
			scanf("%d", &n1);
			if(n1 == -1)
				break;
			scanf("%d", &n2);
			*tmp_next = get_node(n1, n2);
			tmp_next = &(*tmp_next)->next;
		}
	}
	dfs(1, 0);
	cout << answer << endl;
}