#include <iostream>
#include <queue>

using namespace std;

int A, B;

int answer = -1;

void bfs()
{
	queue<long long> nq;
	queue<int> wq;
	nq.push(A);
	wq.push(0);
	while(!nq.empty())
	{
		long long num = nq.front();
		int weight = wq.front();
		nq.pop();
		wq.pop();
		if(num == B)
		{
			answer = weight + 1;
			break;
		}
		if(num*2 <= B)
		{
			nq.push(num*2);
			wq.push(weight+1);
		}
		if(num*10+1 <= B)
		{
			nq.push(num*10+1);
			wq.push(weight+1);
		}
	}
}

int main()
{
	cin >> A >> B;
	bfs();
	cout << answer << endl;
}