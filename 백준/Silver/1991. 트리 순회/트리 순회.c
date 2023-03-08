#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	char value;
	char left_value;
	char right_value;
	struct s_node *left_node;
	struct s_node *right_node;
}	t_node;

t_node *root = 0;

t_node *make_node(char *info)
{
	t_node *ret_node;

	ret_node = malloc(sizeof(t_node));
	ret_node->value = info[0];
	if(info[1] == '.')
		ret_node->left_value = 0;
	else
		ret_node->left_value = info[1];
	if(info[2] == '.')
		ret_node->right_value = 0;
	else
		ret_node->right_value =info[2];
	return ret_node;
}

void find_push_node(t_node *node, t_node *tmp_node)
{
	if(node->left_value == tmp_node->value)
	{
		node->left_node = tmp_node;
		return ;
	}
	else if(node->right_value == tmp_node->value)
	{
		node->right_node = tmp_node;
		return ;
	}
	if(node->left_node)
		find_push_node(node->left_node, tmp_node);
	if(node->right_node)
		find_push_node(node->right_node, tmp_node);
}

void push_node(char *info)
{
	t_node *tmp_node;
	tmp_node = make_node(info);
	if(root == 0)
		root = tmp_node;
	find_push_node(root, tmp_node);
}

void preorder_traversal(t_node *node)
{
	if(!node)
		return ;
	printf("%c", node->value);
	if(node->left_node)
		preorder_traversal(node->left_node);
	if(node->right_node)
		preorder_traversal(node->right_node);
}

void inorder_traversal(t_node *node)
{
	if(!node)
		return ;
	if(node->left_node)
		inorder_traversal(node->left_node);
	printf("%c", node->value);
	if(node->right_node)
		inorder_traversal(node->right_node);
}

void postorder_traversal(t_node *node)
{
	if(!node)
		return ;
	if(node->left_node)
		postorder_traversal(node->left_node);
	if(node->right_node)
		postorder_traversal(node->right_node);
	printf("%c", node->value);
}

int main()
{
	int N;
	char info[3];
	scanf("%d", &N);
	//printf("N : %d", N);
	for(int i = 0; i < N; i ++)
	{
		char info[3];
		getchar();
		scanf("%c %c %c", info + 0, info + 1, info + 2);
		//printf("||%c %c %c||", info[0], info[1], info[2]);
		push_node(info);
		//printf("here %d\n", i);
	}
	preorder_traversal(root);
	printf("\n");
	inorder_traversal(root);
	printf("\n");
	postorder_traversal(root);
	printf("\n");
}