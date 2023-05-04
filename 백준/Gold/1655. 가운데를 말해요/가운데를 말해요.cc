#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int> > min_heap;


int high_count;

int low_count;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		int num;
		cin >> num;
		if(i == 0)
		{
			max_heap.push(num);
			printf("%d\n", max_heap.top());
			continue;
		}
		if(max_heap.top() <= num)
		{
			if(max_heap.size() <= min_heap.size())
			{
				min_heap.push(num);
				max_heap.push(min_heap.top());
				min_heap.pop();
			}
			else
				min_heap.push(num);
		}
		else
		{
			if(max_heap.size() > min_heap.size())
			{
				max_heap.push(num);
				min_heap.push(max_heap.top());
				max_heap.pop();
			}
			else
				max_heap.push(num);
		}
		printf("%d\n", max_heap.top());
	}
}
