#include <iostream>

using namespace std;

int cnt[100001];
int input[15000];
int N, M;

int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i ++)
	{
		cin >> input[i];
		cnt[input[i]] = 1;
	}
	int ans = 0;
	for(int i = 0; i < N; i ++)
	{
		int cur = input[i];
		if(cur > M || M-cur > 100000 || cur == M-cur)
			continue;
		if(cnt[cur] && cnt[M-cur])
		{
			ans ++;
			cnt[M-cur] = 0;
			cnt[cur] = 0;
		}
	}
	cout << ans << endl;
}