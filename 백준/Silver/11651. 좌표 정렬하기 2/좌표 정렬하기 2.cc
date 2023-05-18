#include <iostream>
#include <queue>

using namespace std;

struct compare
{
	bool operator() (pair<int, int> &a, pair<int, int> &b)
	{
		if(a.second == b.second)
			return a.first > b.first;
		return a.second > b.second;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int> >, compare>pq;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		pq.push(pair<int, int>(n1, n2));
	}
	for(int i = 0; i < N; i ++)
	{
		cout << pq.top().first << " " << pq.top().second << "\n";
		pq.pop();
	}

}