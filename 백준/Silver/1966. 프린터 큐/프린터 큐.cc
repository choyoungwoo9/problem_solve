#include <iostream>
#include <deque>
using namespace std;

int N, M;

class doc
{
	public:
		doc(int p1, int p2)
		{
			pri = p1;
			flag = p2;
		}
		int pri;
		int flag;
};

int check_best(deque<doc> &deq)
{
	for(int i = 0; i < deq.size(); i ++)
	{
		if(deq[i].pri > deq[0].pri)
			return 0;
	}
	return 1;
}

void solution()
{
	deque<doc> deq;
	cin >> N >> M;
	int num;
	for(int i = 0; i < N; i ++)
	{
		cin >> num;
		if(i == M)
			deq.push_back(doc(num, 1));
		else
			deq.push_back(doc(num, 0));
	}
	int answer = 0;
	while(1)
	{
		if(check_best(deq))
		{
			answer ++;
			if(deq.front().flag)
			{
				cout << answer << "\n";
				break;
			}
			deq.pop_front();
		}
		else
		{
			deq.push_back(deq.front());
			deq.pop_front();
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for(int i = 0; i < T; i ++)
	{
		solution();
	}
}