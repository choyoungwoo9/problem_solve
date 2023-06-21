#include <iostream>

using namespace std;

int N;
int K;
int ar[1001][3];

bool is_high(int i)
{
	// cout << i << endl;
	if(ar[i][0] != ar[K][0])
		return ar[i][0] > ar[K][0];
	if(ar[i][1] != ar[K][1])
		return ar[i][1] > ar[K][1];
	if(ar[i][2] != ar[K][2])
		return ar[i][2] > ar[K][2];
	return 0;
}

int main()
{
	cin >> N >> K;
	for(int i = 0; i < N; i ++)
	{
		int num;
		cin >> num;
		cin >> ar[num][0] >> ar[num][1] >> ar[num][2];
	}

	int cnt = 0;
	for(int i = 1; i <= N; i ++)
	{
		if(is_high(i))
			cnt ++;
	}
	cout << cnt + 1 << endl;
}