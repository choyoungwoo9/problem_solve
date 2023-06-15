#include <iostream>
#include <queue>

using namespace std;

//w : length, L : max_weight

int n, w, L;
queue<int> que;

int main()
{
	cin >> n >> w >> L;
	for(int i = 0; i < n; i ++)
	{
		int tmp;
		cin >>tmp;
		que.push(tmp);
	}

	int time = 0;
	queue<int> gq;
	queue<int> tmp_q;
	int rest_weight = L;
	while(1)
	{
		if(gq.empty() && que.empty())
		{
			break;
		}
		if(!gq.empty() && gq.front() == time)
		{
			rest_weight += tmp_q.front();
			tmp_q.pop();
			gq.pop();
		}
		if(que.empty())
		{
			time++;
			continue;
		}
		if(que.front() > rest_weight)
		{

		}
		else if(que.front() <= rest_weight)
		{
			rest_weight -= que.front();
			gq.push(time + w);
			tmp_q.push(que.front());
			que.pop();
			
		}
		time++;
	}
	cout <<time << endl;
}