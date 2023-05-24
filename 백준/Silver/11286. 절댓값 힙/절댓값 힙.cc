#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

class hp
{
	public:
	int value;
	bool operator <(const hp &a) const
	{
		if(abs(a.value) == abs(value))
			return a.value < value;
		return abs(a.value) < abs(value);
	}
};

priority_queue<hp> pq;

int cnt = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		int num;
		cin >> num;
		if(!num)
		{
			if(pq.empty())
			{
				cout << "0\n";
				continue;
			}
			cout << pq.top().value << "\n";
			pq.pop();
		}
		else
		{
			hp a;
			a.value = num;
			pq.push(a);
		}
	}
}