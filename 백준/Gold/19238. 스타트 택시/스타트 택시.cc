#include <iostream>
#include <queue>

using namespace std;

//맵 크기, 승객 수
int N, M;

//연료량
int fuel;

//맵
int mp[20][20];

//시작위치
int y, x;

//승객 위치
//y, x로 저장
pair<int, int> target[401];
int manMap[20][20];

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void initMap()
{
	for(int j = 0; j < N; j ++)
	{
		for(int i = 0; i < N; i ++)
		{
			if(mp[j][i] == 2)
				mp[j][i] = 0;
		}
	}
}

//벽으로 막혀있는 경우도 고려해야함
//bfs로 탐색
int findMan()
{
	int minDistance = 1000;
	int minIdx = -1;
	int minY = -1;
	int minX = -1;
	queue<pair<int, pair<int, int> > >que;
	que.push(pair<int, pair<int, int> >(0, pair<int, int>(y, x)));
	//2로 이미 지나간 위치 표시
	mp[y][x] = 2;
	while(!que.empty())
	{
		int curDistance = que.front().first;
		int curY = que.front().second.first;
		int curX = que.front().second.second;
		que.pop();
		if(manMap[curY][curX] != 0)
		{
			if(curDistance < minDistance || (curDistance == minDistance && curY < minY) || (curDistance == minDistance && curY == minY && curX < minX) )
			{
				minDistance = curDistance;
				minIdx = manMap[curY][curX];
				minY = curY;
				minX = curX;
			}

		}
		for(int i = 0; i < 4; i ++)
		{
			int ny = curY + dy[i];
			int nx = curX + dx[i];
			if(ny < 0 || ny >= N || nx < 0 || nx >= N || mp[ny][nx] != 0)
				continue;
			mp[ny][nx] = 2;
			que.push(pair<int, pair<int, int> >(curDistance+1, pair<int, int>(ny, nx)));
		}
	}
	initMap();
	if(minIdx == -1)
		return 0;
	manMap[minY][minX] = 0;
	y = minY;
	x = minX;
	fuel -= minDistance;
	return minIdx;
}

int findTarget(int targetY, int targetX)
{
	queue<pair<int, pair<int, int> > >que;
	que.push(pair<int, pair<int, int> >(0, pair<int, int>(y, x)));
	mp[y][x] = 2;
	while(1)
	{
		//타겟 못찾음
		if(que.empty())
			return 0;
		int curDistance = que.front().first;
		int curY = que.front().second.first;
		int curX = que.front().second.second;
		que.pop();
		if(curY == targetY && curX == targetX)
		{
			fuel -= curDistance;
			if(fuel < 0)
				return 0;
			y = curY;
			x = curX;
			fuel += curDistance * 2;
			break;
		}
		for(int i = 0; i < 4; i ++)
		{
			int ny = curY + dy[i];
			int nx = curX + dx[i];
			if(ny < 0 || ny >= N || nx < 0 || nx >= N || mp[ny][nx] != 0)
				continue;
			mp[ny][nx] = 2;
			que.push(pair<int, pair<int, int> >(curDistance+1, pair<int, int>(ny, nx)));
		}
	}
	initMap();
	return 1;
}

int main()
{
	cin >> N >> M >> fuel;
	for(int j = 0; j < N; j ++)
		for(int i = 0; i < N; i ++)
			cin >> mp[j][i];
	cin >> y >> x;
	y --;
	x --;
	for(int i = 1; i <= M; i++)
	{
		int manY, manX, targetY, targetX;
		cin >> manY >> manX >> targetY >> targetX;
		manY --;
		manX --;
		targetY --;
		targetX --;
		manMap[manY][manX] = i;
		target[i] = pair<int, int>(targetY, targetX);
	}
	for(int i = 0; i < M; i ++)
	{
		int manIdx = findMan();
		if(!manIdx)
		{
			fuel = -1;
			break;
		}
		int flag = findTarget(target[manIdx].first, target[manIdx].second);
		if(!flag)
		{
			fuel = -1;
			break;
		}
	}
	cout << fuel << endl;;
}