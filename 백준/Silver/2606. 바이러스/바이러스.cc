#include <iostream>

using namespace std;

int N;
int answer;

typedef struct relation
{
	int visited;
	int num;
	relation *next;
}	relation;

relation r_pool[10000];
int pool_index;
relation index_relation[101];
relation *get_pool(int num)
{
	r_pool[pool_index].num = num;
	r_pool[pool_index].next = NULL;
	return &r_pool[pool_index++];
};

void add_relation(int root, int com)
{
	relation *com_rel = get_pool(com);
	com_rel->next = index_relation[root].next;
	index_relation[root].next = com_rel;
}

void dfs(int num)
{
	if(index_relation[num].visited)
		return;
	index_relation[num].visited = 1;
	answer ++;
	relation *tmp = index_relation[num].next;
	while(tmp)
	{
		if(!tmp->visited)
			dfs(tmp->num);
		tmp = tmp->next;
	}
}

int main()
{
	cin >> N;
	int repeat_count;
	cin >> repeat_count;
	for(int i = 1; i <= N; i ++)
	{
		index_relation[i].visited = 0;
		index_relation[i].next = NULL;
	}
	for(int i = 0; i < repeat_count; i ++)
	{
		int com1, com2;
		cin >> com1 >> com2;
		add_relation(com1, com2);
		add_relation(com2, com1);
	}
	if(index_relation[1].next == NULL)
	{
		cout << "0" << endl;
	}
	dfs(1);
	cout << answer - 1 << endl;
}