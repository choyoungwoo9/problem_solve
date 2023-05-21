#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int N;
pair<int, int> ar[1000000];

int answer[1000000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		cin >> ar[i].first;
		ar[i].second = i;
	}
	sort(ar, ar+N);
	int index = 0;
	for(int i = 0; i < N; i ++)
	{
		if(i != 0 && ar[i].first != ar[i-1].first)
			index ++;
		answer[ar[i].second] = index;
	}

	for(int i = 0; i < N; i ++)
	{
		cout << answer[i] << " ";
	}
	cout << endl;
}