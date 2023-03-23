#include <iostream>
#include <algorithm>

using namespace std;

int N;
int ar[1000000];

int main()
{
	cin >> N;
	for(int i = 0; i < N; i ++)
		cin >> ar[i];
	sort(ar, ar+N);
	for(int i = 0; i < N; i ++)
		cout << ar[i] << "\n";
}