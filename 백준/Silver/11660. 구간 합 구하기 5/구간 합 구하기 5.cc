#include <iostream>

using namespace std;

int input[1025][1025];

int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 1; i <= N; i ++)
	{
		for(int j = 1; j <= N; j ++)
		{
			int num;
			cin >> num;
			input[i][j] = input[i][j-1] + num;
		}
	}

	int x1, y1, x2, y2;
	for(int i = 0; i < M; i ++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		int answer = 0;
		for(int i = x1; i <= x2; i ++)
		{
			answer += input[i][y2] - input[i][y1-1];
		}
		cout << answer << "\n";
	}
}