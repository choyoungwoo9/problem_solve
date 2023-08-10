#include <iostream>
#include <queue>

using namespace std;

queue<int> sQue[200001];
int answer[100001];
int N, M;

int main()
{
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
	{
		int k;
		cin >> k;
		for(int j = 0; j < k; j++)
		{
			int num;
			cin >> num;
			sQue[num].push(i);
		}
	}
	for(int i = 1; i <= M; i++)
	{
		int num;
		cin >> num;
		if(sQue[num].empty())
			continue;
		int customer = sQue[num].front();
		sQue[num].pop();
		answer[customer] ++;
	}

	for(int i = 1; i <= N; i++)
	{
		cout << answer[i] << " ";
	}
	cout << endl;
}