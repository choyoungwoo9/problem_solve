#include <iostream>
#include <algorithm>
using namespace std;

int N;

int ar1[50];
int ar2[50];

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i ++)
		cin >> ar1[i];
	for(int i = 0; i < N; i ++)
		cin >> ar2[i];
	sort(ar1, ar1+N);
	sort(ar2, ar2+N, compare);
	int answer = 0;
	for(int i = 0; i < N; i ++)
		answer += ar1[i] * ar2[i];
	cout << answer << endl;
}