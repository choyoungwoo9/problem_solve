// #include <stdio.h>

// typedef struct node_relation
// {
// 	int vertex_num;
// 	struct node_relation *relate;
// }	relation;

// typedef struct vertex_info
// {
// 	int parent;
// 	int depth;
// }	vertex_info;

// relation vertex_index[50001];
// relation vertex_pool[100000];
// int count = 0;

// relation *get_node(int vertex_num)
// {
// 	vertex_pool[count].vertex_num = vertex_num;
// 	vertex_pool[count].relate = NULL;
// 	return &vertex_pool[count ++];
// }

// vertex_info info[50001];

// void set_node(int vertex_1, int vertex_2)
// {
// 	relation *tmp;
// 	tmp = &vertex_index[vertex_1];
// 	while(tmp->relate)
// 		tmp = tmp->relate;
// 	tmp->relate = get_node(vertex_2);
// 	tmp = &vertex_index[vertex_2];
// 	while(tmp->relate)
// 		tmp = tmp->relate;
// 	tmp->relate = get_node(vertex_1);
// }

// void dfs(int parent, int depth)
// {
// 	relation *parent_relation = &vertex_index[parent];
// 	while(parent_relation->relate)
// 	{
// 		parent_relation = parent_relation->relate;
// 		if(info[parent_relation->vertex_num].parent == 0)
// 		{
// 			info[parent_relation->vertex_num].parent = parent;
// 			info[parent_relation->vertex_num].depth = depth + 1;
// 			dfs(parent_relation->vertex_num, depth + 1);
// 		}
// 	}
// }

// void print_common_ancestor(int vertex_1, int vertex_2)
// {
// 	int high_vertex, low_vertex;
// 	if(info[vertex_1].depth >= info[vertex_2].depth)
// 	{
// 		high_vertex = vertex_2;
// 		low_vertex = vertex_1;
// 	}
// 	else
// 	{
// 		high_vertex = vertex_1;
// 		low_vertex = vertex_2;
// 	}
// 	while(info[high_vertex].depth != info[low_vertex].depth)
// 	{
// 		//printf("here\n");
// 		low_vertex = info[low_vertex].parent;
// 	}
// 	while(high_vertex != low_vertex)
// 	{
// 		//printf("here\n");
// 		high_vertex = info[high_vertex].parent;
// 		low_vertex = info[low_vertex].parent;
// 	}
// 	printf("%d\n", high_vertex);	
// }

// void make_tree()
// {
// 	info[1].parent = -1;
// 	info[1].depth = 0;
// 	dfs(1, 0);
// }

// int main()
// {
// 	int N, M;
// 	scanf("%d", &N);
// 	for(int i = 1; i < N; i ++)
// 	{
// 		int vertex_1, vertex_2;
// 		scanf(" %d %d", &vertex_1, &vertex_2);
// 		set_node(vertex_1, vertex_2);
// 	}
// 	make_tree();
// 	scanf("%d", &M);
// 	for(int i = 0; i < M; i ++)
// 	{
// 		int vertex_1, vertex_2;
// 		scanf(" %d %d", &vertex_1, &vertex_2);
// 		print_common_ancestor(vertex_1, vertex_2);
// 	}
// 	// for(int i = 1; i < 16; i ++)
// 	// {
// 	// 	printf("%d parrent : %d\n", i, info[i].parent);
// 	// }
// }

#include <stdio.h>
#include <string.h>

#define MAX_N 50001
#define MAX_M 10001

int n, m, h[MAX_N], e[MAX_N * 2], ne[MAX_N * 2], idx;
int dep[MAX_N], f[MAX_N][21];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int father)
{
    dep[u] = dep[father] + 1;
    f[u][0] = father;
    for (int i = 1; i <= 20; i ++)
    {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == father)
        {
            continue;
        }
        dfs(j, u);
    }
}

int lca(int a, int b)
{
    if (dep[a] < dep[b])
    {
        int t = a;
        a = b, b = t;
    }
    for (int i = 20; i >= 0; i --)
    {
        if (dep[f[a][i]] >= dep[b])
        {
            a = f[a][i];
        }
    }
    if (a == b)
    {
        return a;
    }
    for (int i = 20; i >= 0; i --)
    {
        if (f[a][i] != f[b][i])
        {
            a = f[a][i];
            b = f[b][i];
        }
    }
    return f[a][0];
}

int main(void)
{
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    scanf("%d", &m);
    while (m --)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}