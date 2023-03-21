#include <iostream>

using namespace std;

int N, M;

int ar[9];

void recursive_find(int num, int count)
{
	if(count == 0)
	{
		for(int i = 0; i < M; i ++)
		{
			cout << ar[i] << " ";
		}
		cout << "\n";
		return ;
	}
	for(int i = num; i <= N - count + 1; i ++)
	{
		ar[M-count] = i;
		recursive_find(i+1, count - 1);
	}
}

int main()
{
	cin >> N >> M;
	recursive_find(1, M);
}