#include <iostream>
#include <algorithm>
using namespace std;

typedef struct max_set
{
	int first_max;
	int second_max;
}	max_set;

max_set ar[301];

int main()
{
	int N;
	cin >> N;
	for(int i = 1; i <= N; i ++)
	{
		int num;
		cin >> num;
		ar[i].first_max = num;
		ar[i].second_max = num;
		if(i == 1)
			continue;
		ar[i].first_max += ar[i-1].second_max;
		ar[i].second_max += max(ar[i-2].first_max, ar[i-2].second_max);
	}
	cout << max(ar[N].first_max, ar[N].second_max) << endl;
}