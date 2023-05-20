#include <iostream>
#include <deque>

using namespace std;

int N;
deque<int> deq;

int main()
{
	cin >> N;
	for(int i = 1; i <= N; i ++)
		deq.push_back(N-i+1);
	int flag = 1;
	while(deq.size() != 1)
	{
		if(flag)
		{
			cout << deq.back() << " ";
			deq.pop_back();
			flag = 0;
		}
		else
		{
			deq.push_front(deq.back());
			deq.pop_back();
			flag = 1;
		}
	}
	cout << deq.back() << endl;
}