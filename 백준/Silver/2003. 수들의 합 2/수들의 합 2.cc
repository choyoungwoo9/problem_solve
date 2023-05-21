#include <iostream>

using namespace std;

int N, M;

int answer = 0;

int ar[10000];

int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i ++)
		cin >> ar[i];

	for(int i = 0; i < N; i ++)
	{
		int tmp = 0;
		for(int j = i; j < N; j ++)
		{
			tmp = tmp + ar[j];
			if(tmp == M)
				answer ++;
		}
	}
	cout << answer << endl;
}