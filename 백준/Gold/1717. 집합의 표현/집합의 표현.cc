#include <iostream>

using namespace std;

int n, m;

int ar[1000001];

int find(int num)
{
	if(ar[num] == num)
		return num;
	ar[num] = find(ar[num]);
	return ar[num];
}

void uni(int a, int b)
{
	ar[find(ar[a])] = find(ar[b]);
}

int is_same_group(int a, int b)
{
	if(find(a) == find(b))
		return 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i <= n; i++)
		ar[i] = i;
	for(int i = 0; i < m; i ++)
	{
		int mode, a, b;
		cin >> mode >> a >> b;
		if(!mode)
		{
			uni(a, b);
		}
		else
		{
			if(is_same_group(a, b))
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}
}