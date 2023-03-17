#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int ar[100000];

int gap_min = 2147483647;

void find_optimal_left(int start, int end, int num)
{
	if(start > end)
		return ;
	int mid = (start + end) / 2;
	int gap = num - ar[mid];
	if(gap >= M)
	{
		if(gap_min > gap)
			gap_min = gap;
		find_optimal_left(start, mid-1, num);
	}
	else
	{
		find_optimal_left(mid+1, end, num);
	}
}

void find_optimal_right(int start, int end, int num)
{
	if(start > end)
		return ;
	int mid = (start + end) / 2;
	int gap = ar[mid] - num;
	if(gap >= M)
	{
		if(gap_min > gap)
			gap_min = gap;
		find_optimal_right(mid+1, end, num);
	}
	else
	{
		find_optimal_right(start, mid-1, num);
	}
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i ++)
	{
		cin >> ar[i];
	}
	sort(ar, ar + N);
	for(int i = 0; i < N; i ++)
	{
		int idx = lower_bound(ar+i, ar+N, M+ar[i]) - ar;
		if(idx == N)
			continue;
		if(gap_min > ar[idx] - ar[i])
		{
			gap_min = ar[idx] - ar[i];
		}
	}
	cout << gap_min << endl;
}