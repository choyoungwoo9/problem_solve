#include <iostream>
using namespace std;
struct house
{
	int cost[3];
	int final_cost[3];
};

house house_table[1001];

int my_min(int a, int b)
{
	if(a > b)
		return b;
	return a;
}

void update_final_cost(int index, int color)
{
	if(color == 0)
	{
		house_table[index].final_cost[color] +=
			my_min(house_table[index-1].final_cost[1], house_table[index-1].final_cost[2]);
	}
	else if(color == 1)
	{
		house_table[index].final_cost[color] +=
			my_min(house_table[index-1].final_cost[0], house_table[index-1].final_cost[2]);
	}
	else if(color == 2)
	{
		house_table[index].final_cost[color] +=
			my_min(house_table[index-1].final_cost[0], house_table[index-1].final_cost[1]);
	}
}

void update_table(int index)
{
	for(int color = 0; color < 3; color ++)
	{
		update_final_cost(index, color);
	}
}

int main()
{
	int N;
	cin >> N;
	for(int i = 1; i <= N; i ++)
	{
		for(int j = 0; j < 3; j ++)
		{
			cin >> house_table[i].cost[j];
			house_table[i].final_cost[j] = house_table[i].cost[j];
		}
	}

	for(int i = 2; i <= N; i ++)
	{
		update_table(i);
	}
	cout << my_min(house_table[N].final_cost[0], my_min(house_table[N].final_cost[1], house_table[N].final_cost[2])) << endl;
}