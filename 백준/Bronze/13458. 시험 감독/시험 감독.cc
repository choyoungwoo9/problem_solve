#include <iostream>

using namespace std;

long long N;
long long ar[1000000];
long long B, C;

long long answer = 0;

int main()
{
	cin >> N;
	for(int i = 0; i < N; i ++)
		cin >> ar[i];
	cin >> B >> C;
	answer += N;
	for(int i = 0; i < N; i ++)
	{
		ar[i] -= B;
		if(ar[i] > 0)
			answer += (ar[i] / C + (ar[i]%C ? 1 : 0));
	}
	cout << answer << endl;
}