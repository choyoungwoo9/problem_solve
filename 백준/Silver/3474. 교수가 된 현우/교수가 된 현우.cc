#include <iostream>

using namespace std;

void solve()
{
	int ans = 0;
	int N;
	cin >> N;
	while(1)
	{
		if(N < 5)
			break;
		N = N / 5;
		ans += N;
	}
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >>T;
	for(int i = 0; i < T; i ++)
	{
		solve();
	}
}