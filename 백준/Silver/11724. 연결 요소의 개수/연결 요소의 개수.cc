#include <iostream>

using namespace std;

int N, M;

typedef struct node
{
	int num;
	int team;
	node *next;
}	node;

node node_pool[1000 * 999];
int node_count;

node *get_node(int num)
{
	node_pool[node_count].num = num;
	return &node_pool[node_count ++];
}

node node_index[1001];

void link_node(int base, int target)
{
	node *target_node = get_node(target);
	target_node->next = node_index[base].next;
	node_index[base].next = target_node;
}

int answer;

void travel_node(int num)
{
	if(node_index[num].team)
		return ;
	node_index[num].team = answer;
	node *tmp_node = node_index[num].next;
	while(tmp_node)
	{
		travel_node(tmp_node->num);
		tmp_node = tmp_node->next;
	}
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < M; i ++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		link_node(v1, v2);
		link_node(v2, v1);
	}
	for(int i = 1; i <= N; i ++)
	{
		if(node_index[i].team == 0)
		{
			answer ++;
			travel_node(i);
		}
	}
	cout << answer << endl;
}