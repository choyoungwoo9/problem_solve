#include <iostream>
#include <algorithm>

using namespace std;

int l, N;

void solution()
{
	cin >> l >> N;
	int mx = -1;
	int mn = -1;
	for(int i = 0; i < N; i ++)
	{
		int num;
		cin >> num;
		mx = max(mx, max(l-num, num));
		
		mn = max(mn, min(l-num, num));
	}
	cout << mn << " " << mx << "\n";
}

int main()
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i ++)
	{
		solution();
	}
}