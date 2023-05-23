#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> >pq;

int main()
{

	int N;
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		int num;
		cin >> num;
		pq.push(num);
	}
	int answer = 0;
	for(int i = 0; i < N-1; i ++)
	{
		int n1 = pq.top();
		pq.pop();
		int n2 = pq.top();
		pq.pop();
		pq.push(n1 + n2);
		answer += n1 + n2;
	}
	cout << answer << endl;;
}