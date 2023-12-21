#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int mp[101][101];
int answer = 0;

int main()
{
	int N;
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		vector<pair<int, int> > vt;
		vt.push_back(pair<int, int>(y, x));
		vt.push_back(pair<int, int>(y+dy[d], x+dx[d]));
		for(int i = 0; i < vt.size(); i ++)
			mp[vt[i].first][vt[i].second] = 1;
		//세대수만큼 끝점을 정해 반복한다.
		for(int i = 0; i < g; i ++)
		{
			int lastIdx = vt.size()-1;
			int lastY = vt[lastIdx].first;
			int lastX = vt[lastIdx].second;
			for(int k = lastIdx-1; k >= 0; k--)
			{
				int curY = vt[k].first;
				int curX = vt[k].second;
				int ny = lastY - (lastX - curX);
				int nx = lastX + (lastY - curY);
				mp[ny][nx] = 1;
				vt.push_back(pair<int, int>(ny, nx));
			}
		}
	}

	for(int j = 0; j < 100; j++)
	{
		for(int i = 0; i < 100; i ++)
		{
			if(mp[j][i] && mp[j+1][i] && mp[j][i+1] && mp[j+1][i+1])
				answer ++;
		}
	}
	cout << answer << endl;
}