#include <iostream>

using namespace std;

int H, W;
int mp[51][51];

void rotate(int y, int k)
{
	int tmp[51];
	k = k % W;
	for(int i = 0; i < W; i ++)
	{
		tmp[(i+k)%W] = mp[y][i];
	}
	for(int i = 0; i < W; i ++)
		mp[y][i] = tmp[i];
}

void reverse_rotate(int y, int k)
{
	int tmp[51];
	k = k % W;
	for(int i = 0; i < W; i ++)
	{
		int idx = i-k;
		if(idx < 0)
			idx += W;
		tmp[idx] = mp[y][i];
	}
	for(int i = 0; i < W; i ++)
		mp[y][i] = tmp[i];
}

	// for(int j = 1; j <= H; j ++)
	// {
	// 	for(int i = 0; i < W; i ++)
	// 		cout << mp[j][i] << " ";
	// 	cout << endl;
	// }

int visited[51][51];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void dfs(int y, int x, int first)
{
	visited[y][x] = 1;
	int flag = 0;
	for(int i = 0; i < 4; i ++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		// cout << ny << " " << nx << endl;
		if(nx >= W)
			nx -= W;
		else if(nx < 0)
			nx += W;
		if(ny <= 0 || ny > H || visited[ny][nx] == 1 || mp[ny][nx] != mp[y][x])
			continue;
		flag = 1;
		dfs(ny, nx, 0);
	}
	if(first == 0 || flag)
		mp[y][x] = 0;
}

void update()
{
	for(int j = 1; j <= H; j++)
		for(int i = 0; i < W; i ++)
			visited[j][i] = 0;

	
	int flag = 0;
	for(int j = 1; j <= H; j ++)
	{
		for(int i = 0; i < W; i ++)
		{
			if(visited[j][i])
			{
				flag = 1;
				continue;
			}
			if(mp[j][i] == 0)
				continue;
			dfs(j, i, 1);
			
				// cout << j << " " << i << endl;
				// for(int j = 1; j<= H; j++)
				// {
				// 	for(int i = 0; i < W; i ++)
				// 		cout << mp[j][i] << " ";
				// 	cout << endl;
				// }
				// cout << endl;
				// for(int j = 1; j<= H; j++)
				// {
				// 	for(int i = 0; i < W; i ++)
				// 		cout << visited[j][i] << " ";
				// 	cout << endl;
				// }
		}
	}

	// for(int j = 1; j<= H; j++)
	// {
	// 	for(int i = 0; i < W; i ++)
	// 		cout << mp[j][i] << " ";
	// 	cout << endl;
	// }
	
	if(!flag)
	{
		int sum = 0;
		int cnt = 0;
		for(int j = 1; j <= H; j ++)
		{
			for(int i = 0; i < W; i ++)
			{
				if(mp[j][i] == 0)
					continue;
				cnt ++;
				sum += mp[j][i];
			}
		}
		// cout << sum << " " << cnt << endl;
		double average = (double)sum / (double)cnt;
		// cout << "here " << average  <<"\n";
		for(int j = 1; j <= H; j ++)
		{
			for(int i = 0; i < W; i ++)
			{
				if(mp[j][i] == 0)
					continue;
				if(mp[j][i] > average)
					mp[j][i] --;
				else if(mp[j][i] < average)
					mp[j][i] ++;
			}
		}

		// for(int j = 1; j<= H; j++)
		// {
		// 	for(int i = 0; i < W; i ++)
		// 		cout << mp[j][i] << " ";
		// 	cout << endl;
		// }
		
		
	}
}

int main()
{
	int T;
	cin >> H >> W >> T;
	for(int j = 1;j <= H; j ++)
	{
		for(int i = 0; i < W; i ++)
			cin >> mp[j][i];
	}
	for(int i = 0; i < T; i ++)
	{
		int idx, dir, k;
		cin >> idx >> dir >> k;
		int n = 1;
		while(1)
		{
			if(n * idx > H)
				break;
			if(dir == 0)
				rotate(n*idx, k);
			else
				reverse_rotate(n*idx, k);
			n ++;
		}
		update();
	}

	// for(int j = 1; j<= H; j++)
	// {
	// 	for(int i = 0; i < W; i ++)
	// 		cout << mp[j][i] << " ";
	// 	cout << endl;
	// }


	int answer = 0;
	for(int j = 1; j<= H; j++)
		for(int i = 0; i < W; i ++)
			answer += mp[j][i];
	cout << answer << endl;
}