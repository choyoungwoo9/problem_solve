#include <iostream>
#include <algorithm>

using namespace std;

int M, N;

int ar[8];

int tmp[8];

void recursive_print(int cnt, int visited)
{
	if(cnt == N)
	{
		for(int i = 0; i < N; i ++)
			cout << ar[tmp[i]] << " ";
		cout << "\n";
		return; 
	}
	for(int i = 0; i < M; i ++)
	{
		if(visited & (1 << i))
			continue;
		tmp[cnt] = i;
		recursive_print(cnt+1, visited | (1 << i));
	}
}

int main()
{
	cin >> M >> N;
	for(int i = 0; i < M; i ++)
		cin >> ar[i];
	sort(ar, ar+M);
	recursive_print(0, 0);
}