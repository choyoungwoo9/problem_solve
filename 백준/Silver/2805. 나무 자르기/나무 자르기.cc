#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long N, M;

long long tree[1000001];
long long sum = 0;

int main()
{
	cin >> N >> M;
	//cout << N << M;
	for(int i = 1; i <= N; i ++)
	{
		cin >> tree[i];
		sum += tree[i];
	}
	sort(tree, tree+N+1);
	long long answer = 0;

	for(int i = 1; i <= N; i ++)
	{
		// cout << "answer "<< answer << endl;
		// cout << "sum " << sum << endl;
		long long gap = tree[i] - tree[i-1];
		if(sum-(long long)(N-i+1)*gap > (long long)M)
		{
			sum = sum-(N-i+1)*gap;
			answer += gap;
		}
		else
		{
			answer = answer + (long long)floor((long double)(sum - M) / (long double)(N-i+1));
			break ;
		}
	}
	cout << answer << endl;
}
