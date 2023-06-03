#include <iostream>
#include <vector>

using namespace std;

vector<int> node[50];
int N;
int root;
int d_node;

int visited[50];

int dfs(int num)
{
	visited[num] = 1;
	int ret = 0;
	for(int tmp : node[num])
	{
		if(!visited[tmp])
			ret += dfs(tmp);
	}
	if(ret == 0)
		return 1;
	return ret;
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		int num;
		cin >>num;
		if(num == -1)
		{
			root = i;
		}
		else
		{
			node[i].push_back(num);
			node[num].push_back(i);
		}
	}

	cin >> d_node;
	for(int i = 0; i < N; i ++)
	{
		for(auto it = node[i].begin(); it != node[i].end(); it ++)
		{
			if(*it == d_node)
			{
				node[i].erase(it);
				break;
			}
		}
	}
	if(root == d_node)
	{
		cout << 0 << endl;
		return 0;
	}
	cout << dfs(root) << endl;
}