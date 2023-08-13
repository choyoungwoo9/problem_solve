#include <iostream>
#include <algorithm>

using namespace std;

int N;
int input[10001];

bool isSorted()
{
	for(int i = 0; i < N-1; i++)
	{
		if(input[i] > input[i+1])
			return false;
	}
	return true;
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> input[i];
	int before = input[N-1];
	if(isSorted())
	{
		cout << -1 << endl;
		return 0;
	}
	for(int i = N-2; i >= 0; i --)
	{
		if(input[i] > before)
		{
			int idx = i+1;
			for(int j = i+2; j < N; j++)
			{
				if(input[i] > input[j] && input[idx] < input[j])
					idx = j;
			}
			swap(input[i], input[idx]);
			sort(input+i+1, input+N, greater<int>());
			break;
		}
		before = input[i];
	}
	for(int i = 0; i < N; i++)
		cout << input[i] << " ";
	cout << endl;
}