#include <iostream>

using namespace std;

int N, K;

int answer;
int ar[100001];
int tmp[100001];
int main()
{
	cin >> N >> K;
	for(int j = 0; j < N; j ++)
	{
		// for(int x = 0; x <= K; x++)
		// {
		// 	cout << ar[x] << " ";
		// }
		// cout << endl;
		int W, V;
		cin >> W >> V;
		for(int i = 0; W+i <= K; i ++)
		{
			if(ar[W+i] < ar[i] + V)
			{
				tmp[W+i] = ar[i] + V;
			}
		}
		for(int i = 0; W+i <= K; i ++)
		{
			if(ar[W+i] < ar[i] + V)
			{
				ar[W+i] = tmp[W+i];
				if(answer < ar[W+i])
					answer = ar[W+i];
			}
		}
	}
	cout << answer << endl;
}