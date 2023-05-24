#include <iostream>

using namespace std;

int cnt = 0;

int ans;

int ar[50];
int tmp[50];
int main()
{
	cin >> cnt;
	for(int i = 1; i <= cnt; i ++)
		ar[i-1] = i;
	int m;
	cin >> m;
	for(int i = 0; i < m; i ++)
	{
		int num;
		cin >> num;
		int idx;
		for(int j = 0; j < cnt; j ++)
		{
			if(ar[j] == num)
				idx = j;
		}
		ans += min(idx, cnt-idx);
		cnt --;
		for(int j = 0; j < cnt; j ++)
		{
			tmp[j] = ar[(idx+1+j) % (cnt+1)];
		}
		for(int j = 0; j < cnt; j ++)
			ar[j] = tmp[j];
	}
	cout << ans << endl;
}