#include <stdio.h>
#include <stdbool.h>
#define INF 500000000

int N, E;
int city_1, city_2;
int map[801][801];

int visited[801];
int dist[801];

int get_min_index()
{
	int min = -1;
	int min_index = -1;
	for(int i = 1; i <= N; i ++)
	{
		if(visited[i])
			continue;
		if(min < 0)
		{
			min = dist[i];
			min_index = i;
		}
		if(min > dist[i])
		{
			min = dist[i];
			min_index = i;
		}
	}
	return min_index;
}

void dijkstra(int start_city)
{
	for(int i = 1; i <= N; i ++)
		dist[i] = map[start_city][i];
	while(1)
	{
		int selected_city = get_min_index();
		//printf("select : %d\n", selected_city);
		if(selected_city == -1)
			break;
		visited[selected_city] = true;
		for(int i = 1; i <= N; i ++)
		{
			if(dist[selected_city] + map[selected_city][i] < dist[i])
				dist[i] = dist[selected_city] + map[selected_city][i];
		}
	}
}

int main()
{
	for(int i = 1; i <= 800; i ++)
	{
		visited[i] = false;
		dist[i] = INF;
		for(int j = 1; j <= 800; j ++)
		{
			map[i][j] = INF;
			if(i == j)
				map[i][j] = 0;
		}
	}
	scanf("%d %d", &N, &E);
	for(int i = 0; i < E; i ++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		map[a][b] = c;
		map[b][a] = c;
	}
	scanf("%d %d", &city_1, &city_2);
	dijkstra(1);
	int start_to_city_1 = dist[city_1];
	int start_to_city_2 = dist[city_2];
	for(int i = 1; i <= N; i ++)
	{
		dist[i] = INF;
		visited[i] = false;
	}
	dijkstra(city_1);
	// for(int i = 1; i <= N; i ++)
	// {
	// 	printf("%d ", dist[i]);
	// }
	// printf("\n");
	int city_1_to_N = dist[N];
	int city_1_to_city_2 = dist[city_2];
	for(int i = 1; i <= N; i ++)
	{
		dist[i] = INF;
		visited[i] = false;
	}
	dijkstra(city_2);
	int city_2_to_N = dist[N];
	int city_2_to_city_1 = dist[city_1];
	int min;

	//printf("%d %d %d", start_to_city_2, city_2_to_city_1, city_1_to_N);
	if(start_to_city_1 + city_1_to_city_2 + city_2_to_N < start_to_city_2 + city_2_to_city_1 + city_1_to_N)
	{
		min = start_to_city_1 + city_1_to_city_2 + city_2_to_N;
		if(min >= INF)
			min = -1;
		printf("%d\n", min);
	}
	else
	{
		min = start_to_city_2 + city_2_to_city_1 + city_1_to_N;
		if(min >= INF)
			min = -1;
		printf("%d\n", min);
	}
}