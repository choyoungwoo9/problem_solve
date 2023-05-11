#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int V, E;

vector<pair<int, pair<int, int> > >vt;

int parent[10001];
int answer = 0;

int find(int num)
{
	if(parent[num] == num)
		return num;
	parent[num] = find(parent[num]);
	return parent[num];
}

void union_vertex(int num1, int num2)
{
	parent[find(num1)] = find(num2);
}

bool is_same_group(int num1, int num2)
{
	if(find(num1) == find(num2))
	{
		return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;
	int num1, num2, cost;
	for(int i = 0; i < E; i++)
	{
		cin >> num1 >> num2 >> cost;
		vt.push_back(pair<int, pair<int, int> >(cost, pair<int, int>(num1, num2)));
	}

	sort(vt.begin(), vt.end());
	for(int i = 1; i <= V; i ++)
		parent[i] = i;
	for(int i = 0; i < E; i ++)
	{
		if(!is_same_group(vt[i].second.first, vt[i].second.second))
		{
			union_vertex(vt[i].second.first, vt[i].second.second);
			answer += vt[i].first;
		}
	}
	cout << answer << endl;
}