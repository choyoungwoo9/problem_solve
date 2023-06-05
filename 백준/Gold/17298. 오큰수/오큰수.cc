#include <iostream>
#include <deque>

using namespace std;

int N;
deque<pair<int, int> > deq;

int ans[1000000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		while(!deq.empty())
		{
			if(deq.front().first < num)
			{
				ans[deq.front().second] = num;
				deq.pop_front();
			}
			else
				break;
		}
		deq.push_front(pair<int, int>(num, i));
	}
	for(auto i : deq)
		ans[i.second] = -1;
	for(int i = 0; i < N; i ++)
		cout << ans[i] << " ";
	cout << endl;
}